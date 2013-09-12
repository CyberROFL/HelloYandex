/*
    @author Ilnaz Nizametdinov

    @project HelloYandex

    @description
        Implementation of the CMainDlg class.
 */

#include "stdafx.h"

#include "resource/resource.h"
#include "main_dlg.h"

#include <stdlib.h> // srand, rand
#include <time.h>

LPTSTR g_lpszNames[3] = { _TEXT("Поиск"), _TEXT("Диск"), _TEXT("Деньги")};

LRESULT CMainDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    WindowIcon_Init();
    DlgResize_Init();

	CenterWindow();

    CButton buttonAdd = GetDlgItem(IDADD);
    CButton buttonDel = GetDlgItem(IDDEL);

    buttonAdd.SetIcon(LoadImage<HICON, IMAGE_ICON>(IDI_ADD, SM_CXSMICON, SM_CYSMICON));
    buttonDel.SetIcon(LoadImage<HICON, IMAGE_ICON>(IDI_DEL, SM_CXSMICON, SM_CYSMICON));

    _list.SubclassWindow(GetDlgItem(IDC_LIST));
    // Initialize with 4 columns and 5 rows
    _list.AddColumn(_TEXT("Column 1"), 0);
    _list.AddColumn(_TEXT("Column 2"), 1);
    _list.AddColumn(_TEXT("Column 3"), 2);
    _list.AddColumn(_TEXT("Column 4"), 3);

    // Initialize random generator
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            CCustomListCtrl::Item item;

            int magic = rand() % 3;

            item.bText = rand() % 2;
            item.hBmp  = LoadBitmap(_Module.GetResourceInstance(),
                MAKEINTRESOURCE(IDB_IMG_BASE + magic));
            item.lpszText = g_lpszNames[magic];

            _list.AddItem(i, j, item);
        }
    }
    _list.Update();

    // Force redraw to update the list
    DlgResize_UpdateLayout(0, 0);

    return TRUE;
}

LRESULT CMainDlg::OnAdd(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    int nItem = _list.GetSelectedIndex();

    nItem = (-1 == nItem) ? _list.GetItemCount() : nItem + 1;

    for (int j = 0; j < 4; ++j)
    {
        CCustomListCtrl::Item item;

        int magic = rand() % 3;

        item.bText = rand() % 2;
        item.hBmp  = LoadBitmap(_Module.GetResourceInstance(),
            MAKEINTRESOURCE(IDB_IMG_BASE + magic));
        item.lpszText = g_lpszNames[magic];

        nItem = _list.AddItem(nItem, j, item);
    }
    _list.Update();
    _list.EnsureVisible(nItem, FALSE);

    return 0;
}

LRESULT CMainDlg::OnDelete(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    int nItem = _list.GetSelectedIndex();

    if (-1 != nItem)
    {
        _list.DeleteItemMy(nItem);
        _list.Update();
    }

    return 0;
}
