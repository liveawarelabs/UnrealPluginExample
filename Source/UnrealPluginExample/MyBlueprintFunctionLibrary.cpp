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

void UMyBlueprintFunctionLibrary::GetState(bool& running, FString& status, FString& changeModeText, FString& startText, FString& stopText) {
	running = plugin->IsRunning;
	FString state = plugin->IsRecording ? "Recording" : "Idle";
	FString mode = plugin->IsBuffering ? ", buffering" : "";
	status = state + mode;
	changeModeText = plugin->IsBuffering ? "Stop buffering" : "Start buffering";
	startText = wantsLive ? "GO LIVE" : "Start Recording";
	stopText = wantsLive ? "End Stream" : "Stop Recording";
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
