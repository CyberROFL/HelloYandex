/*
    @author Ilnaz Nizametdinov

    @project HelloYandex

    @description
        Interface of the CMainDlg class.
 */

#ifndef __GUI_MAIN_DLG_H__
#define __GUI_MAIN_DLG_H__

#include "gui/mixins/wnd_icon.h"
#include "gui/mixins/closable_dlg.h"

class CMainDlg : public CDialogImpl<CMainDlg>,
                 public CWindowIcon<CMainDlg, IDI_MAIN>,
                 public CClosableDlg<CMainDlg>
{
    typedef CWindowIcon<CMainDlg, IDI_MAIN> CWindowIconBase;
    typedef CClosableDlg<CMainDlg> CClosableDlgBase;

public:
	enum { IDD = IDD_MAIN };

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        CHAIN_MSG_MAP(CClosableDlgBase)
	END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
};

#endif // __GUI_MAIN_DLG_H__
