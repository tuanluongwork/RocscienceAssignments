#include "pch.h"
#include "../../MFCDialogApp.h"
#include "MainDlg.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"
#include "../Resources/Resource.h"

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
	DDX_Control(pDX, IDC_BUTTON_GROUNDWATER, m_groundwaterButton);
	DDX_Control(pDX, IDC_BUTTON_THERMAL, m_thermalButton);
	DDX_Control(pDX, IDC_STATIC_LABEL_GROUNDWATER, m_groundwaterLabel);
	DDX_Control(pDX, IDC_STATIC_LABEL_THERMAL, m_thermalLabel);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GROUNDWATER, &CMainDlg::OnShowGroundWaterOptionsDialog)
	ON_BN_CLICKED(IDC_BUTTON_THERMAL, &CMainDlg::OnShowThermalOptionsDialog)
END_MESSAGE_MAP()

BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Initialize the controller
	m_controller.InitializeModels();

	// Set button text
	m_groundwaterButton.SetWindowText(L"Ground Water Method");
	m_thermalButton.SetWindowText(L"Thermal Method");

	// Initialize labels with styled appearance
	m_groundwaterLabel.SetWindowText(L"No selection");
	m_thermalLabel.SetWindowText(L"No selection");

	// Set custom font for better visibility
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = 16;
	wcscpy_s(lf.lfFaceName, L"MS Shell Dlg");
	lf.lfWeight = FW_NORMAL;
	CFont* pFont = new CFont();
	pFont->CreateFontIndirect(&lf);
	m_groundwaterLabel.SetFont(pFont);
	m_thermalLabel.SetFont(pFont);

	// Update UI based on models from controller
	UpdateUI();

	return TRUE;
}

void CMainDlg::UpdateUI()
{
	// Get models from controller
	DialogModelBase& groundWaterModel = m_controller.GetGroundWaterModel();
	DialogModelBase& thermalModel = m_controller.GetThermalModel();

	// Update label contents from models
	std::wstring groundWaterOption = groundWaterModel.GetSelectedOption();
	std::wstring thermalOption = thermalModel.GetSelectedOption();

	if (!groundWaterOption.empty()) {
		m_groundwaterLabel.SetWindowText(groundWaterOption.c_str());
	}

	if (!thermalOption.empty()) {
		m_thermalLabel.SetWindowText(thermalOption.c_str());
	}
}

void CMainDlg::OnShowGroundWaterOptionsDialog()
{
	// Let the controller handle showing the dialog
	if (m_controller.ShowGroundWaterOptionsDialog(this)) {
		// Update UI after dialog is closed
		std::wstring groundWaterOption = m_controller.GetGroundWaterModel().GetSelectedOption();
		if (!groundWaterOption.empty()) {
			m_groundwaterLabel.SetWindowText(groundWaterOption.c_str());
		}
	}
}

void CMainDlg::OnShowThermalOptionsDialog()
{
	// Let the controller handle showing the dialog
	if (m_controller.ShowThermalOptionsDialog(this)) {
		// Update UI after dialog is closed
		std::wstring thermalOption = m_controller.GetThermalModel().GetSelectedOption();
		if (!thermalOption.empty()) {
			m_thermalLabel.SetWindowText(thermalOption.c_str());
		}
	}
}