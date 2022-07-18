// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"

#include "Base64FunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class TAPPYCHICKEN_API UBase64FunctionLibrary
    : public UBlueprintFunctionLibrary {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "Base64",
            meta = (DisplayName = "Decode base64 data",
                    Keywords = "decode encode base64"))
  static FString DecodeBase64(const FString &encoded);
};
