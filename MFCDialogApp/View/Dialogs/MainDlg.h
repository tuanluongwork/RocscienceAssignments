#pragma once
#include "../../Controller/AppController.h"

/**
 * @class CMainDlg
 * @brief Main application dialog - the primary view
 */
class CMainDlg : public CDialogEx
{
public:
	CMainDlg(CWnd* pParent = nullptr);
	virtual ~CMainDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDIALOGAPP_DIALOG };
#endif

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	BOOL OnInitDialog() override;

	DECLARE_MESSAGE_MAP()

private:
	// Application controller
	AppController m_controller;

	// Dialog controls
	CButton m_button1;
	CButton m_button2;
	CStatic m_label1;
	CStatic m_label2;

	// Helper methods
	void UpdateUI();

public:
	// Message handlers
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};