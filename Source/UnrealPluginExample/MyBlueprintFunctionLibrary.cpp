// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include <memory>
#include <RecorderPlugin.h>

namespace {
	std::unique_ptr<LiveAwareLabs::RecorderPlugin> plugin;
}

void UMyBlueprintFunctionLibrary::MakeConnection() {
	plugin = LiveAwareLabs::RecorderPlugin::Create();
}

void UMyBlueprintFunctionLibrary::ChangeMode() {
	plugin->ChangeBuffering(!plugin->IsBuffering);
}
