#pragma once
#include <string>
#include <vector>

// Dialog types enumeration
enum DialogType {
	GROUNDWATER_DIALOG,
	THERMAL_DIALOG
};

/**
 * @struct DialogOptions
 * @brief Container for dialog configuration data
 */
struct DialogOptions {
	std::wstring dialogTitle;
	std::wstring labelText;
	std::vector<std::wstring> comboOptions;
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
	std::wstring GetDialogTitle() const { return m_options.dialogTitle; }
	std::wstring GetLabelText() const { return m_options.labelText; }
	const std::vector<std::wstring>& GetComboOptions() const { return m_options.comboOptions; }
	int GetSelectedIndex() const { return m_selectedIndex; }
	std::wstring GetSelectedOption() const;

	// Mutators
	void SetSelectedIndex(int index);

	// Restore the previously saved selection
	void RestoreSavedSelection() { m_selectedIndex = m_savedIndex; }

	// Save the current selection
	void SaveCurrentSelection() { m_savedIndex = m_selectedIndex; }

private:
	DialogOptions m_options;            // Container for dialog options
	int m_selectedIndex;                // Current selected item index
	int m_savedIndex;                   // Saved selection (for cancel operation)
};