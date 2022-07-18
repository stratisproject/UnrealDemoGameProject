#pragma once

#include "Core.h"

#include "FNFTInfo.generated.h"

USTRUCT(BlueprintType)
struct TAPPYCHICKEN_API FNFTInfo {

  GENERATED_USTRUCT_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Name;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Description;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString ImageLink;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString TextureLink;
};