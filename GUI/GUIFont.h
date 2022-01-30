#pragma once

#include <vector>
#include <string>

#pragma pack(push, 1)
struct GUICharMetric {
    int32_t uLeftSpacing;
    int32_t uWidth;
    int32_t uRightSpacing;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FontData {
    uint8_t cFirstChar = 0;  // 0
    uint8_t cLastChar = 0;   // 1
    uint8_t field_2 = 0;
    uint8_t field_3 = 0;
    uint8_t field_4 = 0;
    uint16_t uFontHeight = 0;  // 5-6
    uint8_t field_7 = 0;
    uint32_t palletes_count = 0;
    uint8_t* pFontPalettes[5]{};
    GUICharMetric pMetrics[256]{};
    uint32_t font_pixels_offset[256]{};
    std::vector<uint8_t> pFontData;  // array of font pixels
//    uint8_t pFontData[0];  // array of font pixels
};
#pragma pack(pop)

class GUIWindow;
class Image;
struct FontData;

class GUIFont {
 public:
    GUIFont () : pData(new FontData()) {}
    static GUIFont *LoadFont(const char *pFontFile, const char *pFontPalette);

    bool IsCharValid(unsigned char c) const;
    unsigned int GetHeight() const;

    unsigned int AlignText_Center(unsigned int width, const std::string &str);

    unsigned int GetLineWidth(const std::string &str);

    unsigned int CalcTextHeight(const std::string &str, unsigned int width,
                                int x_offset, bool return_on_carriage = false);

    std::string GetPageTop(const std::string &pInString, GUIWindow *pWindow,
                      unsigned int uX, int a5);
    void DrawTextLine(const std::string &text, uint16_t uDefaultColor, int uX,
                      int uY, int max_len_pix);
    void DrawText(GUIWindow *pWindow, int uX, int uY, uint16_t uFontColor,
                  const std::string &str, bool present_time_transparency,
                  int max_text_height, int uFontShadowColor);
    int DrawTextInRect(GUIWindow *pWindow, unsigned int uX, unsigned int uY,
                       uint16_t uColor, const std::string &str, int rect_width,
                       int reverse_text);

    std::string FitTextInAWindow(const std::string &inString, unsigned int width, int uX,
                            bool return_on_carriage = false);

    void DrawCreditsEntry(GUIFont *pSecondFont, int uFrameX, int uFrameY,
                          unsigned int w, unsigned int h, uint16_t firstColor,
                          uint16_t secondColor, const std::string &pString,
                          Image *image);
    int GetStringHeight2(GUIFont *secondFont, const std::string &text_str,
                         GUIWindow *pWindow, int startX, int a6);

 protected:
    FontData *pData;

    std::string FitTwoFontStringINWindow(const std::string &pString, GUIFont *pFontSecond,
                                    GUIWindow *pWindow, int startPixlOff,
                                    int a6);
    void DrawTextLineToBuff(uint16_t uColor, uint32_t *uX_buff_pos,
                            const std::string &text, int line_width);
};

extern GUIFont *pAutonoteFont;
extern GUIFont *pSpellFont;
extern GUIFont *pFontArrus;
extern GUIFont *pFontLucida;
extern GUIFont *pBook2Font;
extern GUIFont *pBookFont;
extern GUIFont *pFontCreate;
extern GUIFont *pFontComic;
extern GUIFont *pFontSmallnum;
