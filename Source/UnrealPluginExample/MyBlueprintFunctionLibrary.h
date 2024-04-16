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
	static void ChangeMode();
};
