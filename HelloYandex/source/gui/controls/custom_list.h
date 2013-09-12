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
        CDCHandle dc = lpDrawItemStruct->hDC;
        CDC dcMem;

        dc.SaveDC();
        {
            dcMem.CreateCompatibleDC(dc);

            // Load bitmap & associate with in-memory dc
            CBitmap bmp;
            bmp.LoadBitmap(IDB_IMG_1);
            dcMem.SelectBitmap(bmp);

            // Aplha-blend function
            BLENDFUNCTION bf;
            bf.BlendOp = AC_SRC_OVER;
            bf.BlendFlags = 0;
            bf.SourceConstantAlpha = 255;
            bf.AlphaFormat = AC_SRC_ALPHA;

            // Draw bmp with transparency
            dc.AlphaBlend(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top, 32, 32, dcMem, 0, 0, 32, 32, bf);

            dcMem.DeleteDC();
        }
        dc.RestoreDC(-1);
    }

    void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
    {
        lpMeasureItemStruct->itemHeight = 32 + 1;
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
