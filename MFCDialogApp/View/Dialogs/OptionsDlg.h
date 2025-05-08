#pragma once
#include "../../Model/DialogModel.h"
#include "../Resources/resource.h"

/**
 * @class COptionsDlg
 * @brief View component of MVC pattern - reusable dialog for options
 */
class COptionsDlg : public CDialog
{
	DECLARE_DYNAMIC(COptionsDlg)

public:
	// Constructor that accepts a model reference
	COptionsDlg(DialogModel& model, CWnd* pParent = nullptr);
	virtual ~COptionsDlg();

	// Dialog Data
	enum { IDD = IDD_OPTIONS_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	BOOL OnInitDialog() override;

	// No longer need OnOK and OnCancel overrides
	// We'll use WM_CLOSE instead

	DECLARE_MESSAGE_MAP()

private:
	// Reference to the model
	DialogModel& m_model;

	// Dialog controls
	CStatic m_label;
	CComboBox m_comboBox;

public:
	// Message handlers
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnClose();
};