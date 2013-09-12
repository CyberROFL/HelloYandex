/*
    @author Ilnaz Nizametdinov

    @project HelloYandex

    @description
        –
 */

#ifndef __GUI_MIXINS_WND_ICON_H__
#define __GUI_MIXINS_WND_ICON_H__

template <class T, UINT nResID>
class CWindowIcon
{
public:
    BEGIN_MSG_MAP(CWindowIcon)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        T* _this = static_cast<T*>(this);

        HICON hIcon = (HICON)::LoadImage(
            _Module.GetResourceInstance(),
            MAKEINTRESOURCE(nResID), IMAGE_ICON,
            ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON),
            LR_DEFAULTCOLOR);
        _this->SetIcon(hIcon, TRUE);

        HICON hIconSmall = (HICON)::LoadImage(
            _Module.GetResourceInstance(),
            MAKEINTRESOURCE(nResID), IMAGE_ICON,
            ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON),
            LR_DEFAULTCOLOR);
        _this->SetIcon(hIconSmall, FALSE);

        return TRUE;
    }
};

#endif // __GUI_MIXINS_WND_ICON_H__
