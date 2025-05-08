// MFCDialogApp.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "MFCDialogApp.h"
#include "View/Dialogs/MainDlg.h"
#include "Controller/AppController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDialogApp

BEGIN_MESSAGE_MAP(CMFCDialogApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


/**
 * CMFCDialogApp construction
 * Initializes application-level resources
 */
CMFCDialogApp::CMFCDialogApp()
{
    // Application initialization is handled in InitInstance
}


// The one and only CMFCDialogApp object
CMFCDialogApp theApp;


/**
 * CMFCDialogApp initialization
 * Sets up the MVC components and launches the main dialog
 */
BOOL CMFCDialogApp::InitInstance()
{
    // Initialize common controls for visual styles
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();

    // Enable support for ActiveX controls
    AfxEnableControlContainer();

    // Create the shell manager for tree/list views
    CShellManager *pShellManager = new CShellManager;

    // Set visual manager for modern look and feel
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

    // Application settings registry key
    SetRegistryKey(_T("Rocscience Engineering Solutions"));

    try {
        // Create the main dialog and set it as the application's main window
        CMainDlg dlg;
        m_pMainWnd = &dlg;
        
        // Show the dialog modally
        INT_PTR nResponse = dlg.DoModal();
        
        // Process dialog response
        switch (nResponse) {
            case IDOK:
                // Optional: Handle OK response
                break;
                
            case IDCANCEL:
                // Optional: Handle Cancel response
                break;
                
            case -1:
                // Handle dialog creation failure
                TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
                TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
                break;
        }
    }
    catch (const std::exception& e) {
        // Handle application-level exceptions
        TRACE(traceAppMsg, 0, "Exception in CMFCDialogApp::InitInstance: %s\n", e.what());
        AfxMessageBox(_T("Application initialization failed."), MB_ICONERROR);
    }

    // Clean up resources
    if (pShellManager != nullptr) {
        delete pShellManager;
    }

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
    ControlBarCleanUp();
#endif

    // Return FALSE to exit the application when the dialog is closed
    return FALSE;
}