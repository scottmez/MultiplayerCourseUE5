// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBox.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AMyBox::AMyBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ReplicatedVar = 100;
	//bReplicates = true; //same as SetReplicates(true);
}

// Called when the game starts or when spawned
void AMyBox::BeginPlay()
{
	Super::BeginPlay();
	
	SetReplicates(true);
	SetReplicateMovement(true); //if you want physics to be copied
}

// Called every frame
void AMyBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyBox::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyBox, ReplicatedVar); //replicates var of certain class
}

void AMyBox::OnRep_ReplicatedVar()
{
	if (HasAuthority()) //if you are the server
	{
		//note this wont be called since the OnRep functions should only ever be called by a client
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Server: OnRep_ReplicatedVar"));
	}
	else //if you are the client
	{
		//called by EACH client
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Client: OnRep_ReplicatedVar"));
	}
}