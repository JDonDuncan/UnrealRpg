// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#ifndef __UNREALRPG_H__
#define __UNREALRPG_H__

#include "Engine.h"
// custom global strings
#include "Strings.h" // will be used for translating in game text elements between Languages
#include "URLs.h"
// Custom  global game logic
//#include "UnrealRpgPlayerController.h"
//#include "UnrealRpgPlayerCharacter.h"
//#include "UnrealRpgPlayerCameraManager.h"
//#include "UnrealRpgHUD.h"
#include "UnrealRpgGameInstance.h"
//General Log
DECLARE_LOG_CATEGORY_EXTERN(GeneralLog, Log, All);
//General debug Log
DECLARE_LOG_CATEGORY_EXTERN(DebugLog, Log, All);
//Logging during game startup
DECLARE_LOG_CATEGORY_EXTERN(InitLog, Log, All);
//Logging for your AI system
DECLARE_LOG_CATEGORY_EXTERN(AILog, Log, All);
//Logging for Critical Errors that must always be addressed
DECLARE_LOG_CATEGORY_EXTERN(CriticalErrorsLog, Log, All);

#endif
