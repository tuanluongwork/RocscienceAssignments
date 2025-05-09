#pragma once
#include "DialogModelBase.h"

class ThermalDialogModel : public DialogModelBase {
public:
    ThermalDialogModel() {
        m_dialogTitle = L"Thermal Analysis Options";
        m_labelText = L"Select Thermal Analysis Type:";
        m_comboOptions = {
            L"Steady State Analysis",
            L"Transient Analysis",
            L"Coupled Analysis"
        };
    }

    virtual void SaveCurrentSelection() override {
        // Thermal-specific save implementation
        DialogModelBase::SaveCurrentSelection();
    }
};