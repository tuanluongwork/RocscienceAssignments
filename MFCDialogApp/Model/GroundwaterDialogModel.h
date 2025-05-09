#pragma once
#include "DialogModelBase.h"

class GroundwaterDialogModel : public DialogModelBase {
public:
	GroundwaterDialogModel() {
		m_dialogTitle = L"Groundwater Analysis Options";
		m_labelText = L"Select Groundwater Model:";
		m_comboOptions = {
			L"Confined Aquifer",
			L"Unconfined Aquifer",
			L"Leaky Aquifer"
		};
	}

	virtual void SaveCurrentSelection() override {
		// Groundwater-specific save implementation
		DialogModelBase::SaveCurrentSelection();
	}
};