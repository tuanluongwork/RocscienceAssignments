#include "pch.h"
#include "DialogModel.h"

DialogModel::DialogModel() : m_selectedIndex(0) {
    // Default constructor
}

DialogModel::~DialogModel() {
    // Virtual destructor
}

void DialogModel::SetDialogType(DialogType type) {
    // Clear previous options
    m_comboOptions.clear();

    // Configure based on dialog type
    switch (type) {
    case GROUNDWATER_DIALOG:
        m_dialogTitle = L"Ground Water Method";
        m_labelText = L"Ground Water Method:";
        m_comboOptions.push_back(L"Static Water");
        m_comboOptions.push_back(L"Steady FEA");
        m_comboOptions.push_back(L"Transient FEA");
        break;

    case THERMAL_DIALOG:
        m_dialogTitle = L"Thermal Method";
        m_labelText = L"Thermal Method:";
        m_comboOptions.push_back(L"Static Temperature");
        m_comboOptions.push_back(L"Steady Thermal FEA");
        m_comboOptions.push_back(L"Transient Thermal FEA");
        break;
    }

    // Reset selection
    m_selectedIndex = 0;
}

void DialogModel::SetSelectedIndex(int index) {
    // Bounds checking for index
    if (index >= 0 && index < static_cast<int>(m_comboOptions.size())) {
        m_selectedIndex = index;
    }
}

std::wstring DialogModel::GetSelectedOption() const {
    // Safe access with bounds checking
    if (m_selectedIndex >= 0 && m_selectedIndex < static_cast<int>(m_comboOptions.size())) {
        return m_comboOptions[m_selectedIndex];
    }
    return L"";
}