#pragma once
#include "../Model/DialogModelBase.h"
#include "../View/Dialogs/OptionsDlg.h"
#include <afxwin.h>

class AppController
{
public:
	// Constructor with parameters for models
	AppController();
	~AppController();

	// Initialize models with default values
	void InitializeModels();

	// Getters for models
	DialogModelBase& GetGroundWaterModel();
	DialogModelBase& GetThermalModel();

	// Methods to show dialogs through the controller
	bool ShowGroundWaterOptionsDialog(CWnd* pParent);
	bool ShowThermalOptionsDialog(CWnd* pParent);

private:
	// Model instances
	DialogModelBase m_groundWaterModel;
	DialogModelBase m_thermalModel;

	// Helper method to configure dialog with model data
	bool ShowOptionsDialog(DialogModelBase& model, CWnd* pParent);
};