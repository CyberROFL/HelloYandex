/*
    @author Ilnaz Nizametdinov

    @project HelloYandex

    @description
        Custom list control.
 */

#ifndef __GUI_CONTROLS_CUSTOM_LIST_H__
#define __GUI_CONTROLS_CUSTOM_LIST_H__

class CCustomListCtrl : public CWindowImpl<CCustomListCtrl, CListViewCtrl>,
                        public COwnerDraw<CCustomListCtrl>
{
public:
    BEGIN_MSG_MAP(CCustomListCtrl)
        CHAIN_MSG_MAP_ALT(COwnerDraw<CCustomListCtrl>, 1)
        DEFAULT_REFLECTION_HANDLER()
    END_MSG_MAP()

    void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
    {
    }

    void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct)
    {
    }

    BOOL DeleteItemMy(int nItem)
    {
        return CListViewCtrl::DeleteItem(nItem);
    }
};

#endif // __GUI_CONTROLS_CUSTOM_LIST_H__
