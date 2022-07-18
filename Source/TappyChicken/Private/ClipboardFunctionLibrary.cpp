// Fill out your copyright notice in the Description page of Project Settings.

#include "ClipboardFunctionLibrary.h"

#include "HAL/PlatformApplicationMisc.h"

void UClipboardFunctionLibrary::CopyToClipboard(const FString &value) {
  FPlatformApplicationMisc::ClipboardCopy(*value);
}

void UClipboardFunctionLibrary::PasteFromClipboard(FString &targetValue) {
  FPlatformApplicationMisc::ClipboardPaste(targetValue);
}
