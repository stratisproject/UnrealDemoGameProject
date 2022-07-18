#pragma once

#include "Core.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "FNFTInfo.h"
#include "NFTApi.h"
#include "NFTApiOperations.h"

#include "AsyncTaskGetNFTInfo.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetNFTInfoDelegate,
                                            const FNFTInfo &, info);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FErrorDelegate);

UCLASS(BlueprintType, Blueprintable)
class TAPPYCHICKEN_API UAsyncTaskGetNFTInfo : public UBlueprintAsyncActionBase {
  GENERATED_UCLASS_BODY()

public:
  UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
  static UAsyncTaskGetNFTInfo *GetNFTInfo(FString URL);

public:
  UPROPERTY(BlueprintAssignable)
  FGetNFTInfoDelegate OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FErrorDelegate OnFail;

public:
  void Start(FString URL);

private:
  stratis::nft::NFTApi api_;
  stratis::nft::NFTApi::GetNFTInfoRequest request_;
  stratis::nft::NFTApi::FGetNFTInfoDelegate delegate_;

  FHttpRequestPtr requestPtr_;

  void HandleNFTInfoResponse(
      const stratis::nft::NFTApi::GetNFTInfoResponse &response);
};
