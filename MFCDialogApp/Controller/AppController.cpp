#include "pch.h"
#include "AppController.h"

AppController::AppController()
{
	// Constructor implementation
}

AppController::~AppController()
{
	// Destructor implementation
}

void AppController::InitializeModels()
{
	// Initialize ground water model
	m_groundWaterModel.SetTitle(L"Groundwater Analysis Options");
	m_groundWaterModel.SetLabelText(L"Select Groundwater Model:");
	m_groundWaterModel.SetOptions({
			L"Confined Aquifer",
			L"Unconfined Aquifer",
			L"Leaky Aquifer"
		});

	// Initialize thermal model
	m_thermalModel.SetTitle(L"Thermal Analysis Options");
	m_thermalModel.SetLabelText(L"Select Thermal Analysis Type:");
	m_thermalModel.SetOptions({
			L"Steady State Analysis",
			L"Transient Analysis",
			L"Coupled Analysis"
		});
}

DialogModelBase& AppController::GetGroundWaterModel()
{
	return m_groundWaterModel;
}

DialogModelBase& AppController::GetThermalModel()
{
	return m_thermalModel;
}

bool AppController::ShowGroundWaterOptionsDialog(CWnd* pParent)
{
	return ShowOptionsDialog(m_groundWaterModel, pParent);
}

bool AppController::ShowThermalOptionsDialog(CWnd* pParent)
{
	return ShowOptionsDialog(m_thermalModel, pParent);
}

bool AppController::ShowOptionsDialog(DialogModelBase& model, CWnd* pParent)
{
	// Create the options dialog
	COptionsDlg dlg(pParent);

	// Configure dialog using model data
	dlg.SetDialogTitle(model.GetTitle().c_str());
	dlg.SetLabelText(model.GetLabelText().c_str());
	dlg.SetComboOptions(model.GetOptions());
	dlg.SetSelectedIndex(model.GetSelectedIndex());

	// Show dialog
	dlg.DoModal();

	// Update model if OK pressed
	model.SetSelectedIndex(dlg.GetSelectedIndex());

	return true;
}