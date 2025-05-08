#pragma once
#include "../Model/DialogModel.h"

/**
 * @class AppController
 * @brief Controller class that coordinates between models and views
 */
class AppController
{
public:
    AppController();
    virtual ~AppController();

    // Initialize models
    void InitializeModels();

    // Access methods for models
    DialogModel& GetGroundWaterModel() { return m_groundWaterModel; }
    DialogModel& GetThermalModel() { return m_thermalModel; }

private:
    // Data models
    DialogModel m_groundWaterModel;
    DialogModel m_thermalModel;
};