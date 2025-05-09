#pragma once
#include <string>
#include <vector>

class DialogModelBase
{
public:
	// Constructor and destructor
	DialogModelBase() : m_selectedIndex(0) {}
	virtual ~DialogModelBase() {}

	// Title methods
	void SetTitle(const std::wstring& title) { m_title = title; }
	std::wstring GetTitle() const { return m_title; }

	// Label text methods
	void SetLabelText(const std::wstring& labelText) { m_labelText = labelText; }
	std::wstring GetLabelText() const { return m_labelText; }

	// Options methods
	void SetOptions(const std::vector<std::wstring>& options) { m_options = options; }
	std::vector<std::wstring> GetOptions() const { return m_options; }

	// Index selection methods
	void SetSelectedIndex(int index) {
		if (index >= 0 && index < static_cast<int>(m_options.size())) {
			m_selectedIndex = index;
		}
	}
	int GetSelectedIndex() const { return m_selectedIndex; }

	// Get the currently selected option text
	std::wstring GetSelectedOption() const {
		if (m_selectedIndex >= 0 && m_selectedIndex < static_cast<int>(m_options.size())) {
			return m_options[m_selectedIndex];
		}
		return L"";
	}

private:
	std::wstring m_title;
	std::wstring m_labelText;
	std::vector<std::wstring> m_options;
	int m_selectedIndex;
};