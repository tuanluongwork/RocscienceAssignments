#include "pch.h"
#include "../../MFCDialogApp.h"
#include "../Resources/Resource.h"  // Include resource header
#include "OptionsDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(COptionsDlg, CDialog)

/**
 * Constructor for the Options Dialog
 * @param pParent Optional parent window
 */
	COptionsDlg::COptionsDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_OPTIONS_DIALOG, pParent)
{
	// Initialize default values
	m_initialSelection = 0;
	m_selectedIndex = 0;
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
	ON_BN_CLICKED(IDOK, &COptionsDlg::OnOK)
	ON_BN_CLICKED(IDCANCEL, &COptionsDlg::OnCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

BOOL COptionsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set dialog title
	SetWindowText(m_dialogTitle);

	// Set label text
	m_label.SetWindowText(m_labelText);

	// Populate combo box with options
	m_comboBox.ResetContent(); // Clear any existing items
	for (const auto& option : m_comboOptions) {
		m_comboBox.AddString(option.c_str());
	}

	// Set initial selection
	m_comboBox.SetCurSel(m_selectedIndex);

	// Improve combo box appearance
	m_comboBox.SetItemHeight(-1, 16); // Default item height
	m_comboBox.SetDroppedWidth(260);  // Width of dropdown

	// Center dialog on parent
	CenterWindow();

	return TRUE;
}

/**
 * Handler for combo box selection change
 */
void COptionsDlg::OnCbnSelchangeCombo()
{
	// Get the current selection
	int selectedIndex = m_comboBox.GetCurSel();

	// Update selection if valid
	if (selectedIndex != CB_ERR) {
		m_selectedIndex = selectedIndex;
	}
}

/**
 * Handle OK button click
 * Saves current selection and closes dialog with IDOK
 */
void COptionsDlg::OnOK()
{
	// Close dialog with OK result
	EndDialog(IDOK);
}

/**
 * Handle Cancel button click
 * Restores initial selection and closes dialog with IDCANCEL
 */
void COptionsDlg::OnCancel()
{
	//// Restore initial selection
	//m_selectedIndex = m_initialSelection;

	// Close dialog with Cancel result
	EndDialog(IDCANCEL);
}

/**
 * Handle the dialog closing
 */
void COptionsDlg::OnClose()
{
	// Simply end the dialog with IDOK
	EndDialog(IDOK);
}

/**
 * Set the dialog title
 * @param title The title to set
 */
void COptionsDlg::SetDialogTitle(const CString& title)
{
	m_dialogTitle = title;
}

/**
 * Set the label text
 * @param text The label text to set
 */
void COptionsDlg::SetLabelText(const CString& text)
{
	m_labelText = text;
}

/**
 * Set the combo box options
 * @param options The options to populate the combo box with
 */
void COptionsDlg::SetComboOptions(const std::vector<std::wstring>& options)
{
	m_comboOptions = options;
}

/**
 * Set the selected index
 * @param index The index to select
 */
void COptionsDlg::SetSelectedIndex(int index)
{
	m_selectedIndex = index;
	m_initialSelection = index;
}

/**
 * Get the currently selected index
 * @return The selected index
 */
int COptionsDlg::GetSelectedIndex() const
{
	return m_selectedIndex;
}