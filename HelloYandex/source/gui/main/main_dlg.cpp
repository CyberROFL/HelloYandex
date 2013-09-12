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

    _buttonAdd = GetDlgItem(IDC_ADD);
    _buttonDel = GetDlgItem(IDC_DEL);

    _buttonAdd.SetIcon((HICON)::LoadImage(
        _Module.GetResourceInstance(),
        MAKEINTRESOURCE(IDI_ADD), IMAGE_ICON,
        16, 16,
        LR_LOADTRANSPARENT | LR_LOADMAP3DCOLORS));
    _buttonDel.SetIcon((HICON)::LoadImage(
        _Module.GetResourceInstance(),
        MAKEINTRESOURCE(IDI_DEL), IMAGE_ICON,
        16, 16,
        LR_LOADTRANSPARENT | LR_LOADMAP3DCOLORS));

    return TRUE;
}
