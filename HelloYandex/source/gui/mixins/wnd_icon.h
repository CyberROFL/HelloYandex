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
    void WindowIcon_Init()
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
    }
};

#endif // __GUI_MIXINS_WND_ICON_H__
