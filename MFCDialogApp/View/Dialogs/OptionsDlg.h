#pragma once

#include "../../Model/DialogModelBase.h"

// COptionsDlg dialog
class COptionsDlg : public CDialog
{
	DECLARE_DYNAMIC(COptionsDlg)

public:
	COptionsDlg(DialogModelBase& model, CWnd* pParent = nullptr);
	virtual ~COptionsDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPTIONS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()

	// Message handlers
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();

private:
	// Controls
	CStatic m_label;
	CComboBox m_comboBox;

	// Data
	DialogModelBase& m_model;
	int m_initialSelection;
};