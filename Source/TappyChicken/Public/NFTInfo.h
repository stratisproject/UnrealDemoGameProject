/**
 * NOTE: This class is auto generated by  Generator
 * https://github.com/Tools/-generator
 * Do not edit the class manually.
 */

#pragma once

#include "BaseModel.h"
#include "NFTInfoAttributes.h"

namespace stratis {
namespace nft {

/*
 * NFTInfo
 *
 *
 */
class TAPPYCHICKEN_API NFTInfo : public Model {
public:
  virtual ~NFTInfo() {}
  bool FromJson(const TSharedPtr<FJsonValue> &JsonValue) final;
  void WriteJson(JsonWriter &Writer) const final;

  TOptional<FString> Name;
  TOptional<FString> Category;
  TOptional<FString> Image;
  TOptional<FString> Description;
  TOptional<FString> ExternalUrl;
  TOptional<TArray<NFTInfoAttributes>> Attributes;
  TOptional<FString> AnimationUrl;
};

} // namespace nft
} // namespace stratis