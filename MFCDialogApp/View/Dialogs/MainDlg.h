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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	// UI update method
	void UpdateUI();

	// Controls
	CButton m_button1;
	CButton m_button2;
	CStatic m_label1;
	CStatic m_label2;

	// Controller that manages models
	AppController m_controller;

	DECLARE_MESSAGE_MAP()
};