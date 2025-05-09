#pragma once
#include "afxwin.h"
#include "../../Controller/AppController.h"

class CMainDlg : public CDialogEx {
public:
	CMainDlg(CWnd* pParent = nullptr);
	virtual ~CMainDlg();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

	// Message handlers
	afx_msg void OnShowGroundWaterOptionsDialog();
	afx_msg void OnShowThermalOptionsDialog();

	// UI update method
	void UpdateUI();

	// Controls
	CButton m_groundwaterButton;
	CButton m_thermalButton;
	CStatic m_groundwaterLabel;
	CStatic m_thermalLabel;

	// Controller that manages models
	AppController m_controller;

	DECLARE_MESSAGE_MAP()
};