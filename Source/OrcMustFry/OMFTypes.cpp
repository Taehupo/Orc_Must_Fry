// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTypes.h"

ETeamAttitude::Type UUtilitaries::OMFTeamAttitudeSolver(FGenericTeamId A, FGenericTeamId B)
{
	return A.GetId() != B.GetId() ? ETeamAttitude::Hostile : ETeamAttitude::Friendly;
}

FGenericTeamId::FAttitudeSolverFunction* UUtilitaries::OMFAttitudeTeamSolver = &UUtilitaries::OMFTeamAttitudeSolver;