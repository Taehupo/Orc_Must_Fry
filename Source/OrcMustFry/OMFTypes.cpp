// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTypes.h"

ETeamAttitude::Type OMFTeamAttitudeSolver(FGenericTeamId A, FGenericTeamId B)
{
	return A.GetId() != B.GetId() ? ETeamAttitude::Hostile : ETeamAttitude::Friendly;
}