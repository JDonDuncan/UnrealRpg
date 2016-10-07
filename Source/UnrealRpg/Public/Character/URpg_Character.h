// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"

// STATS and ATTRIBUTES //
#include "URpg_Stat_Struct.h"
#include "URpg_Attribute_Struct.h"
#include "URpg_PowerUpEffect_Struct.h"

#include "URpg_Character.generated.h"

UENUM(BlueprintType)
enum class ECharacterType : uint8 {
	// A player Character
	Player,
	// A fake player / bot controlled by AI
	AI,
	// A NPC like a shop owner
	NPC,
	// Monsters always hostile beasts
	Monster,
	// Animals can be friend or foe
	Animal,
	// Wildlife
	Critter,
	None
};


UCLASS()
class UNREALRPG_API AURpg_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AURpg_Character(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	// set replicated properties
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// * STAT FUNCTIONS * //
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetStatValue_ByName(EStatName stat, float value, EAffectedProperty prop = EAffectedProperty::Base);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetStatValue_ByIndex(uint8 statIndex, float value, EAffectedProperty prop = EAffectedProperty::Base);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void AddStatValue_ByName(EStatName stat, float value, EAffectedProperty prop = EAffectedProperty::Base);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void AddStatValue_ByIndex(uint8 statIndex, float value, EAffectedProperty prop = EAffectedProperty::Base);
	void UpdateStatWidget(EStatName stat = EStatName::None);

protected:
	// * STATS * //
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = true))
		TArray<FURpg_Stat_Struct> Stats;
	// * ATTRIBUTES * //
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = true))
		TArray<FURpg_Attribute_Struct> Attributes;
	//TArray<FTimerHandle> ActiveStatusEffects;

	// Characters type
	UPROPERTY(Replicated, EditDefaultsOnly, BlueprintReadWrite, Category = "Bio")
		ECharacterType CharacterType;
	// The in game name of the character
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Bio")
	FName Nickname = "Nameme";

	// * INLINE FUNCTIONS * //
public:
	void SetCharacterType(const ECharacterType newCharacterType) { if (Role == ROLE_Authority) { CharacterType = newCharacterType; } }
	ECharacterType GetCharcterType() const { return CharacterType; }

	TArray<FURpg_Stat_Struct> GetStats() const { return Stats; }
	TArray<FURpg_Attribute_Struct> GetAttributes() const { return Attributes; }
};