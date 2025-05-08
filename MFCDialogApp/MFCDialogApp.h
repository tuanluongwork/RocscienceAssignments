#pragma once
#include "Controller/AppController.h"

/**
 * @class CMFCDialogApp
 * @brief Main application class
 */
class CMFCDialogApp : public CWinApp
{
public:
    CMFCDialogApp();

    // Overrides
public:
    virtual BOOL InitInstance();

    // Implementation
    DECLARE_MESSAGE_MAP()
};

extern CMFCDialogApp theApp;