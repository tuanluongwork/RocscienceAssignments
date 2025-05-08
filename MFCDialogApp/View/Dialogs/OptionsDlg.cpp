#include "pch.h"
#include "../../MFCDialogApp.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(COptionsDlg, CDialog)

/**
 * Constructor for the Options Dialog
 * @param model Reference to the DialogModel provided by the controller
 * @param pParent Optional parent window
 */
	COptionsDlg::COptionsDlg(DialogModel& model, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_OPTIONS_DIALOG, pParent), m_model(model)
{
	// No need to save current selection as we'll update immediately
}

COptionsDlg::~COptionsDlg()
{
	// Destructor - nothing to clean up
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	// Link member variables to dialog controls
	DDX_Control(pDX, IDC_STATIC_LABEL, m_label);
	DDX_Control(pDX, IDC_COMBO_OPTIONS, m_comboBox);
}

BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_OPTIONS, &COptionsDlg::OnCbnSelchangeCombo)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

BOOL COptionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set dialog title from model
	CString dialogTitle(m_model.GetDialogTitle().c_str());
	SetWindowText(dialogTitle);

	// Set label text from model
	CString labelText(m_model.GetLabelText().c_str());
	m_label.SetWindowText(labelText);

	// Populate combo box with options from model
	const auto& options = m_model.GetComboOptions();
	m_comboBox.ResetContent(); // Clear any existing items
	for (const auto& option : options) {
		m_comboBox.AddString(option.c_str());
	}

	// Set initial selection from model
	m_comboBox.SetCurSel(m_model.GetSelectedIndex());

	// Improve combo box appearance
	m_comboBox.SetItemHeight(-1, 16); // Default item height
	m_comboBox.SetDroppedWidth(260);  // Width of dropdown

	// Center dialog on parent
	CenterWindow();

	return TRUE;
}

/**
 * Handler for combo box selection change
 * Updates the model with the newly selected option immediately
 */
void COptionsDlg::OnCbnSelchangeCombo()
{
	// Get the current selection
	int selectedIndex = m_comboBox.GetCurSel();

	// Update model if selection is valid
	if (selectedIndex != CB_ERR) {
		// Update model directly - changes take effect immediately
		m_model.SetSelectedIndex(selectedIndex);
		m_model.SaveCurrentSelection(); // Save the selection
	}
}

/**
 * Handle the dialog closing
 * We'll use this instead of OK/Cancel buttons
 */
void COptionsDlg::OnClose()
{
	// Simply end the dialog with IDOK to trigger updates in MainDlg
	EndDialog(IDOK);
}