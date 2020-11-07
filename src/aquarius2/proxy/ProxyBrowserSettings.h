#pragma once
#include "../def/def.h"
#include <functional>

/** 水星浏览器设置, 提供浏览器初始化设置。 */
class AQUADLL ProxyBrowserSettings : public refcounted {
public:
    ProxyBrowserSettings(void* ptr);
    ~ProxyBrowserSettings();

public:

    /** 是否有效, 检查本类型持有对象实例是否有效。 */
    bool IsValid();

    /**
     *  置标准字体, 设置标准字体。
     *
     *  @param font_family,字体名称 设置字体名称。
    */
    void SetStandardFontFamily(const char* font_family);

    /**
     *  置等宽字体, 设置等宽字体。
     *
     *  @param font_family,字体名称 设置字体名称。
    */
    void SetFixedFontFamily(const char* font_family);

    /**
     *  置衬线字体, 设置衬线字体。
     *
     *  @param font_family,字体名称 设置字体名称。
    */
    void SetSerifFontFamily(const char* font_family);

    /**
     *  置无衬线字体, 设置无衬线字体。
     *
     *  @param font_family,字体名称 设置字体名称。
    */
    void SetSansSerifFontFamily(const char* font_family);

    /**
     *  置手写字体, 设置手写线字体。
     *
     *  @param font_family,字体名称 设置字体名称。
    */
    void SetCursiveFontFamily(const char* font_family);

    /**
     *  置艺术字体, 设置艺术字体。
     *
     *  @param font_family,字体名称 设置字体名称。
    */
    void SetFantasyFontFamily(const char* font_family);

    /**
     *  置默认字体大小, 设置默认字体大小。
     *
     *  @param default_font_size,字体大小 默认的字体大小。
    */
    void SetDefaultFontSize(int default_font_size);

    /**
     *  置默认等宽字体大小, 设置默认等宽字体大小。
     *
     *  @param default_fixed_font_size,字体大小 默认的字体大小。
    */
    void SetDefaultFixedFontSize(int default_fixed_font_size);

    /**
     *  置字体最小大小, 设置字体最小大小。
     *
     *  @param minimum_font_size,最小大小 字体最小大小。
    */
    void SetMinimumFontSize(int minimum_font_size);

    /**
     *  置字体最小合理大小, 设置字体最小合理大小。
     *
     *  @param minimum_logical_font_size,最小合理大小 字体最小合理大小。
    */
    void SetMinimumLogicalFontSize(int minimum_logical_font_size);

    /**
     *  置默认编码, 设置字体默认编码。默认缺省值为: \\\"ISO-8859-1\\\", 也可以使用\\\"default-encoding\\\"命令行开关进行配置。
     *
     *  @param default_encoding,编码名称 字体编码名称。
    */
    void SetDefaultEncoding(const char* default_encoding);

    /**
     *  允许加载远程字体源, 设置是否允许从远程字体源加载字体。
     *
     *  @param remote_fonts,状态值  0 = 使用默认设置, 1 = 允许加载, 2 = 禁止加载。
    */
    void SetRemoteFonts(int remote_fonts);

    void SetJavascript(int value);
    void SetJavascriptCloseWindow(int value);
    void SetJavascriptAccessClipboard(int value);
    void SetJavascriptDomPaste(int value);
    void SetPlugins(int value);
    void SetUniversalAccessFromFileUrls(int value);
    void SetFileAccessFromFileUrls(int value);
    void SetWebSecurity(int value);
    void SetImageLoading(int value);
    void SetImageShrinkStandaloneToFit(int value);
    void SetTextAreaResize(int value);
    void SetTabToLinks(int value);
    void SetLocalStorage(int value);
    void SetDataBase(int value);
    void SetApplicationCache(int value);
    void SetWebGL(int value);
    void SetBackgroundColor(int color);
    void SetAcceptLanguageList(const char* values);

public:
    PRIME_IMPLEMENT_REFCOUNTING(ProxyBrowserSettings);
    AQUA_DECL_PUBLIC_ORIGIN;

private:
    void* _rawptr;
};