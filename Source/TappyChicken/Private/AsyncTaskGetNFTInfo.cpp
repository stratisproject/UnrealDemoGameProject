// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsyncTaskGetNFTInfo.h"

#include "Misc/Base64.h"

UAsyncTaskGetNFTInfo::UAsyncTaskGetNFTInfo(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {
  if (HasAnyFlags(RF_ClassDefaultObject) == false) {
    AddToRoot();
  }
}

UAsyncTaskGetNFTInfo *UAsyncTaskGetNFTInfo::GetNFTInfo(FString URL) {
  UAsyncTaskGetNFTInfo *Task = NewObject<UAsyncTaskGetNFTInfo>();
  Task->Start(URL);
  return Task;
}

void UAsyncTaskGetNFTInfo::Start(FString URL) {
  request_.NFTInfoPath = URL;
  delegate_.BindUObject(this, &UAsyncTaskGetNFTInfo::HandleNFTInfoResponse);
  requestPtr_ = api_.GetNFTInfo(request_, delegate_);
}

void UAsyncTaskGetNFTInfo::HandleNFTInfoResponse(
    const stratis::nft::NFTApi::GetNFTInfoResponse &response) {
  if (response.IsSuccessful()) {
    FNFTInfo info;

    info.Name = response.Content.Name.Get("it was empty");
    info.Description = response.Content.Description.Get("it was empty");
    info.ImageLink = response.Content.Image.Get("it was empty");

    auto attributes(response.Content.Attributes.Get({}));
    for (const auto &attribute : attributes) {
      if (attribute.TraitType.Get("it was empty") == "texture") {
        info.TextureLink = attribute.Value.Get("it was empty");
        // FBase64::Decode(attribute.Value.GetValue(), info.TextureLink);
        break;
      }
    }

    OnSuccess.Broadcast(info);
  } else {
    OnFail.Broadcast();
  }
}