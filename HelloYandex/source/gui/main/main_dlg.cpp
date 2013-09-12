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
    WindowIcon_Init();
    DlgResize_Init();

	CenterWindow();

    CButton buttonAdd = GetDlgItem(IDADD);
    CButton buttonDel = GetDlgItem(IDDEL);

    buttonAdd.SetIcon(LoadImage<HICON, IMAGE_ICON>(IDI_ADD, SM_CXSMICON, SM_CYSMICON));
    buttonDel.SetIcon(LoadImage<HICON, IMAGE_ICON>(IDI_DEL, SM_CXSMICON, SM_CYSMICON));

    return TRUE;
}

LRESULT CMainDlg::OnAdd(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    return 0;
}

LRESULT CMainDlg::OnDelete(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    return 0;
}
