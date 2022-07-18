// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"

#include "ClipboardFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class TAPPYCHICKEN_API UClipboardFunctionLibrary
    : public UBlueprintFunctionLibrary {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "Clipboard",
            meta = (DisplayName = "Copy string to clipboard",
                    Keywords = "copy paste clipboard"))
  static void CopyToClipboard(const FString &value);

  UFUNCTION(BlueprintCallable, Category = "Clipboard",
            meta = (DisplayName = "Paste string from clipboard",
                    Keywords = "copy paste clipboard"))
  static void PasteFromClipboard(FString &targetValue);
};
