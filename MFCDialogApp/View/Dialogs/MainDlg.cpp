#include "pch.h"
#include "../../MFCDialogApp.h"
#include "MainDlg.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Constructor now takes an optional controller reference
CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDIALOGAPP_DIALOG, pParent)
{
	// Controller is now responsible for model initialization
}

CMainDlg::~CMainDlg()
{
	// Destructor implementation
	// Clean up any resources allocated by this dialog
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	// Link member variables to dialog controls
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_STATIC_LABEL1, m_label1);
	DDX_Control(pDX, IDC_STATIC_LABEL2, m_label2);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Initialize the controller
	m_controller.InitializeModels();

	// Set button text
	m_button1.SetWindowText(L"Ground Water Method");
	m_button2.SetWindowText(L"Thermal Method");

	// Initialize labels with styled appearance
	m_label1.SetWindowText(L"No selection");
	m_label2.SetWindowText(L"No selection");

	// Set custom font for better visibility
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = 16;
	wcscpy_s(lf.lfFaceName, L"MS Shell Dlg");
	lf.lfWeight = FW_NORMAL;
	CFont* pFont = new CFont();
	pFont->CreateFontIndirect(&lf);
	m_label1.SetFont(pFont);
	m_label2.SetFont(pFont);

	// Update UI based on models from controller
	UpdateUI();

	return TRUE;
}

void CMainDlg::UpdateUI()
{
	// Get models from controller
	DialogModel& groundWaterModel = m_controller.GetGroundWaterModel();
	DialogModel& thermalModel = m_controller.GetThermalModel();

	// Update label contents from models
	std::wstring groundWaterOption = groundWaterModel.GetSelectedOption();
	std::wstring thermalOption = thermalModel.GetSelectedOption();

	if (!groundWaterOption.empty()) {
		m_label1.SetWindowText(groundWaterOption.c_str());
	}

	if (!thermalOption.empty()) {
		m_label2.SetWindowText(thermalOption.c_str());
	}
}

void CMainDlg::OnBnClickedButton1()
{
	// Get model from controller
	DialogModel& groundWaterModel = m_controller.GetGroundWaterModel();

	// Create and show Ground Water dialog with model from controller
	COptionsDlg dlg(groundWaterModel);

	// The dialog will update the model when selection changes
	// and return IDOK when closed
	if (dlg.DoModal() == IDOK) {
		// Update UI after dialog closes
		UpdateUI();
	}
}

void CMainDlg::OnBnClickedButton2()
{
	// Get model from controller
	DialogModel& thermalModel = m_controller.GetThermalModel();

	// Create and show Thermal dialog with model from controller
	COptionsDlg dlg(thermalModel);

	// The dialog will update the model when selection changes
	// and return IDOK when closed
	if (dlg.DoModal() == IDOK) {
		// Update UI after dialog closes
		UpdateUI();
	}
}