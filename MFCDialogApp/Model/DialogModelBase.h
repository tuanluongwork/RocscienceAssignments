#pragma once
#include <string>
#include <vector>

// Base class for dialog models
class DialogModelBase {
protected:
    std::wstring m_dialogTitle;
    std::wstring m_labelText;
    std::vector<std::wstring> m_comboOptions;
    int m_selectedIndex = 0;
    int m_savedIndex = 0;  // Added for saving selection state

public:
    // Common getters
    virtual std::wstring GetDialogTitle() const { return m_dialogTitle; }
    virtual std::wstring GetLabelText() const { return m_labelText; }
    virtual const std::vector<std::wstring>& GetComboOptions() const { return m_comboOptions; }
    virtual int GetSelectedIndex() const { return m_selectedIndex; }

    // Get the text of the selected option
    virtual std::wstring GetSelectedOption() const {
        if (m_selectedIndex >= 0 && m_selectedIndex < m_comboOptions.size()) {
            return m_comboOptions[m_selectedIndex];
        }
        return L"";
    }

    // Common setters
    virtual void SetSelectedIndex(int index) { m_selectedIndex = index; }

    // Save the current selection (can be overridden by derived classes)
    virtual void SaveCurrentSelection() { m_savedIndex = m_selectedIndex; }

    virtual ~DialogModelBase() = default;
};