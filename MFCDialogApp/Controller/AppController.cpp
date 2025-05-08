#include "pch.h"
#include "AppController.h"

AppController::AppController()
{
    InitializeModels();
}

AppController::~AppController()
{
    // Clean up any resources if needed
}

void AppController::InitializeModels()
{
    // Configure models for each dialog type
    m_groundWaterModel.SetDialogType(GROUNDWATER_DIALOG);
    m_thermalModel.SetDialogType(THERMAL_DIALOG);
}