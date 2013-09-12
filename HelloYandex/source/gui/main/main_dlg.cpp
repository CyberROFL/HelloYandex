/*
    @author Ilnaz Nizametdinov

    @project HelloYandex

    @description
        Implementation of the CMainDlg class.
 */

#include "stdafx.h"

#include "resource/resource.h"
#include "main_dlg.h"

LRESULT CMainDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    CWindowIconBase::OnInitDialog(uMsg, wParam, lParam, bHandled);

	CenterWindow();

	return TRUE;
}

LRESULT CMainDlg::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    if (SC_CLOSE == wParam)
    {
        PostQuitMessage(WM_QUIT);
    }

    // Process default action
    bHandled = FALSE;

    return 0;
}
