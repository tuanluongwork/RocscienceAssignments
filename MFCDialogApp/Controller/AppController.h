#pragma once
#include "../Model/GroundwaterDialogModel.h"
#include "../Model/ThermalDialogModel.h"

class AppController {
public:
    AppController();
    virtual ~AppController();

    // Initialize model data
    void InitializeModels();

    // Getters for models
    DialogModelBase& GetGroundWaterModel() { return m_groundWaterModel; }
    DialogModelBase& GetThermalModel() { return m_thermalModel; }

private:
    // Model instances
    GroundwaterDialogModel m_groundWaterModel;
    ThermalDialogModel m_thermalModel;
};