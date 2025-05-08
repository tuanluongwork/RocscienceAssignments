#pragma once
#include <string>
#include <vector>

// Dialog types enumeration
enum DialogType {
    GROUNDWATER_DIALOG,
    THERMAL_DIALOG
};

/**
 * @class DialogModel
 * @brief Model component of MVC pattern - holds dialog data and configuration
 */
class DialogModel {
public:
    DialogModel();
    virtual ~DialogModel();

    // Configure dialog based on type
    void SetDialogType(DialogType type);

    // Accessors
    std::wstring GetDialogTitle() const { return m_dialogTitle; }
    std::wstring GetLabelText() const { return m_labelText; }
    const std::vector<std::wstring>& GetComboOptions() const { return m_comboOptions; }
    int GetSelectedIndex() const { return m_selectedIndex; }
    std::wstring GetSelectedOption() const;

    // Mutators
    void SetSelectedIndex(int index);

private:
    std::wstring m_dialogTitle;         // Dialog title
    std::wstring m_labelText;           // Label text
    std::vector<std::wstring> m_comboOptions;  // Combo box options
    int m_selectedIndex;                // Selected item index
};