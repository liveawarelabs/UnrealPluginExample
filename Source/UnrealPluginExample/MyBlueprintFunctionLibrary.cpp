// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintFunctionLibrary.h"
#include <memory>
#include <string>
#include <RecorderPlugin.h>

namespace {
	std::unique_ptr<LiveAwareLabs::RecorderPlugin> plugin;
	std::string teamName;
	std::string eventName;
	bool wantsCamera;
	bool wantsMicrophone;
	bool wantsLive;
	bool wantsFullScreen;
}

void UMyBlueprintFunctionLibrary::MakeConnection() {
	plugin = LiveAwareLabs::RecorderPlugin::Create();
}

void UMyBlueprintFunctionLibrary::CloseConnection() {
	plugin = nullptr;
}

void UMyBlueprintFunctionLibrary::ChangeMode() {
	plugin->ChangeBuffering(!plugin->IsBuffering);
}

void UMyBlueprintFunctionLibrary::CreateSlice() {
	plugin->CreateSlice();
}

void UMyBlueprintFunctionLibrary::SetTeamName(FString const& newTeamName) {
	teamName = TCHAR_TO_UTF8(*newTeamName);
}

void UMyBlueprintFunctionLibrary::SetEventName(FString const& newEventName) {
	eventName = TCHAR_TO_UTF8(*newEventName);
}

void UMyBlueprintFunctionLibrary::SetCamera(bool newWantsCamera) {
	wantsCamera = newWantsCamera;
}

void UMyBlueprintFunctionLibrary::SetMicrophone(bool newWantsMicrophone) {
	wantsMicrophone = newWantsMicrophone;
}

void UMyBlueprintFunctionLibrary::SetLive(bool newWantsLive) {
	wantsLive = newWantsLive;
}

void UMyBlueprintFunctionLibrary::SetFullScreen(bool newWantsFullScreen) {
	wantsFullScreen = newWantsFullScreen;
}

void UMyBlueprintFunctionLibrary::StartRecording() {
	LiveAwareLabs::RecorderPlugin::StreamSettings settings{
		.teamName = teamName.c_str(),
		.eventName = eventName.c_str(),
		.fullScreen = wantsFullScreen,
		.live = wantsLive,
		.useMicrophone = wantsMicrophone,
		.useCamera = wantsCamera,
	};
	plugin->StartStreaming(settings);
}

void UMyBlueprintFunctionLibrary::StopRecording() {
	plugin->StopStreaming();
}
