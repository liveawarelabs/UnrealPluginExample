// Fill out your copyright notice in the Description page of Project Settings.

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
	static void CreateSlice();
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetTeamName(FString const& teamName);
	UFUNCTION(BlueprintCallable, Category = "Live Aware")
	static void SetEventName(FString const& eventName);
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
