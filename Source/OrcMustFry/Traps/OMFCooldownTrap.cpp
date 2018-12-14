// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFCooldownTrap.h"


bool AOMFCooldownTrap::CanAttack()
{
	return bIsReloaded;
}

