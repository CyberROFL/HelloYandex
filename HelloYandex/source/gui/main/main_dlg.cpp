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

    _list.SubclassWindow(GetDlgItem(IDC_LIST));
    CButton buttonAdd = GetDlgItem(IDADD);
    CButton buttonDel = GetDlgItem(IDDEL);

    _list.AddColumn(_TEXT("Column 1"), 0);
    _list.AddColumn(_TEXT("Column 2"), 1);
    _list.AddColumn(_TEXT("Column 3"), 2);
    _list.AddColumn(_TEXT("Column 4"), 3);
    _list.AddItem(0, 0, _TEXT("Item 1"));
    _list.AddItem(1, 0, _TEXT("Item 2"));
    _list.AddItem(2, 0, _TEXT("Item 3"));
    _list.AddItem(3, 0, _TEXT("Item 4"));
    _list.AddItem(4, 0, _TEXT("Item 5"));
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
