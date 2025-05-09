#pragma once
#include <vector>
#include <string>
#include "../Resources/resource.h"

class COptionsDlg : public CDialog
{
	DECLARE_DYNAMIC(COptionsDlg)

public:
	// Constructor with no model dependency
	COptionsDlg(CWnd* pParent = nullptr);
	virtual ~COptionsDlg();

	// Dialog Data
	enum { IDD = IDD_OPTIONS_DIALOG };

	// Methods for controller to set dialog properties
	void SetDialogTitle(const CString& title);
	void SetLabelText(const CString& text);
	void SetComboOptions(const std::vector<std::wstring>& options);
	void SetSelectedIndex(int index);
	int GetSelectedIndex() const;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

	// Member variables for dialog controls
	CStatic m_label;
	CComboBox m_comboBox;

	// Member variables to store data
	CString m_dialogTitle;
	CString m_labelText;
	std::vector<std::wstring> m_comboOptions;
	int m_selectedIndex;
	int m_initialSelection;

	// Message map and event handlers
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnOK();
	afx_msg void OnCancel();
	afx_msg void OnClose();
};