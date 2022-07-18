// Fill out your copyright notice in the Description page of Project Settings.

#include "Base64FunctionLibrary.h"

#include "Misc/Base64.h"

FString UBase64FunctionLibrary::DecodeBase64(const FString &encoded) {
  FString result;
  FBase64::Decode(encoded, result);
  return result;
}