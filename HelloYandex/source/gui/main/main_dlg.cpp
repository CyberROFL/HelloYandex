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
    DlgResize_Init();

	CenterWindow();

	return TRUE;
}
