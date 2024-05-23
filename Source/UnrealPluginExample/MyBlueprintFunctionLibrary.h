#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class UNREALPLUGINEXAMPLE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void MakeConnection();
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void CloseConnection();
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void ChangeMode();
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void GetState(bool& running, FString& status, FString& changeModeText, FString& startText, FString& stopText, bool& isTeamChanged, FString& newTeamName, bool& isEventChanged, FString& newEventName);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void CreateSlice();
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetTeamName(FString const& teamName);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetEventName(FString const& eventName);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetRecordingName(FString const& recordingName);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetUpload(bool wantsUpload);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetCamera(bool wantsCamera);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetMicrophone(bool wantsMicrophone);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetLive(bool wantsLive);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetFullScreen(bool wantsFullScreen);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void StartRecording();
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void StopRecording();
};
