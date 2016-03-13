// Copyright Jordan Duncan 2015 \\ Description=RPG Template

#include "UnrealRpg.h"
#include "URpg_GameMode.h"
// includes for our custom classes
#include "URpg_PlayerCharacter.h"
#include "URpg_PlayerController.h"
#include "URpg_HUD.h"

// * INTITIALIZATION * //
// Constructor
AURpg_GameMode::AURpg_GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	// Set the default player pawn
	// Blueprinted Version, relies on the asset path obtained from the editor
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(*FURpg_BpAsset_Paths::DefaultPlayerCharacterBP);
	if (PlayerPawnBPClass.Class != nullptr)
	{
		// assign blueprint version
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else {
		// Failsafe assigns native cpp version
		DefaultPawnClass = AURpg_PlayerCharacter::StaticClass();
	}
	// Set the default player controller
	// Blueprinted Version, relies on the asset path obtained from the editor
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBpClass(*FURpg_BpAsset_Paths::DefaultPlayerControllerBp);
	if (PlayerControllerBpClass.Class != nullptr) {
		// assign blueprint version
		PlayerControllerClass = PlayerControllerBpClass.Class;
	}
	else {
		// Failsafe assigns native cpp version
		PlayerControllerClass = AURpg_PlayerController::StaticClass();
	}

	// TODO: Assign Blueprint version of HUD in the Gamemode, only cpp assignment currently exists
	// Failsafe assigns native cpp version
	HUDClass = AURpg_HUD::StaticClass();
}
