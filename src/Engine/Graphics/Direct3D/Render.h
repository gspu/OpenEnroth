#pragma once
#include <d3d.h>
#include <ddraw.h>
#include <string>

#include <GdiPlus.h>
#undef DrawText

#include <memory>

#include "Engine/Graphics/RenderBase.h"

struct ODMFace;
class RenderD3D;
class Image;
class Nuklear;

struct BatchTriangles;

void BatchTriSort();
bool SortByTransThenTex(const BatchTriangles* lhs, const BatchTriangles* rhs);

class Render : public RenderBase {
 public:
    Render(
        std::shared_ptr<Application::GameConfig> config,
        DecalBuilder* decal_builder,
        LightmapBuilder* lightmap_builder,
        SpellFxRenderer* spellfx,
        std::shared_ptr<ParticleEngine> particle_engine,
        Vis* vis,
        Logger* logger
    );
    virtual ~Render();

    virtual bool Initialize() override;

    virtual bool NuklearInitialize(struct nk_tex_font *tfont);
    virtual bool NuklearCreateDevice();
    virtual bool NuklearRender(enum nk_anti_aliasing AA, int max_vertex_buffer, int max_element_buffer);
    virtual void NuklearRelease();
    virtual struct nk_tex_font *NuklearFontLoad(const char *font_path, size_t font_size);
    virtual void NuklearFontFree(struct nk_tex_font *tfont);
    virtual struct nk_image NuklearImageLoad(Image *img);
    virtual void NuklearImageFree(Image *img);

    virtual Texture *CreateTexture_Paletted(const std::string &name) override;
    virtual Texture *CreateTexture_ColorKey(const std::string &name, uint16_t colorkey) override;
    virtual Texture *CreateTexture_Solid(const std::string &name) override;
    virtual Texture *CreateTexture_Alpha(const std::string &name) override;

    virtual Texture *CreateTexture_PCXFromFile(const std::string &name) override;
    virtual Texture *CreateTexture_PCXFromIconsLOD(const std::string &name) override;
    virtual Texture *CreateTexture_PCXFromNewLOD(const std::string &name) override;
    virtual Texture *CreateTexture_PCXFromLOD(LOD::File *pLOD, const std::string &name) override;

    virtual Texture *CreateTexture_Blank(unsigned int width, unsigned int height,
        IMAGE_FORMAT format, const void *pixels = nullptr) override;

    virtual Texture *CreateTexture(const std::string &name) override;
    virtual Texture *CreateSprite(const std::string &name, unsigned int palette_id,
                                  unsigned int lod_sprite_id) override;

    virtual void ClearBlack() override;
    virtual void PresentBlackScreen() override;

    virtual uint8_t *ReadScreenPixels() override;
    virtual void SaveWinnersCertificate(const char *a1) override;
    virtual void ClearTarget(unsigned int uColor) override;
    virtual void Present() override;

    virtual bool InitializeFullscreen() override;

    virtual void CreateZBuffer() override;
    virtual void Release() override;

    virtual bool SwitchToWindow() override;

    virtual void BeginLines2D() override;
    virtual void EndLines2D() override;
    virtual void RasterLine2D(int uX, int uY, int uZ, int uW, uint16_t uColor) override;

    virtual void ClearZBuffer() override;
    virtual void RestoreFrontBuffer() override;
    virtual void RestoreBackBuffer() override;
    virtual void BltBackToFontFast(int a2, int a3, Recti *pSrcRect) override;
    virtual void BeginSceneD3D() override;

    virtual unsigned int GetActorTintColor(int DimLevel, int tint, float WorldViewX, int a5, RenderBillboard *Billboard) override;

    virtual void DrawPolygon(struct Polygon *a3) override;
    virtual void DrawTerrainPolygon(struct Polygon *a4, bool transparent,
                                    bool clampAtTextureBorders) override;
    virtual void DrawIndoorPolygon(unsigned int uNumVertices,
                                   struct BLVFace *a3, int uPackedID,
                                   unsigned int uColor, int a8) override;

    virtual void DrawBillboards_And_MaybeRenderSpecialEffects_And_EndScene() override;
    virtual void BillboardSphereSpellFX(struct SpellFX_Billboard *a1, int diffuse) override;

    virtual void DrawProjectile(float srcX, float srcY, float a3, float a4,
                                float dstX, float dstY, float a7, float a8,
                                Texture *texture) override;
    virtual void RemoveTextureFromDevice(Texture* texture) override;
    virtual bool MoveTextureToDevice(Texture *texture) override;

    virtual void Update_Texture(Texture *texture) override;

    virtual void DeleteTexture(Texture *texture) override;

    virtual void BeginScene() override;
    virtual void EndScene() override;
    virtual void ScreenFade(unsigned int color, float t) override;

    virtual void SetUIClipRect(unsigned int uX, unsigned int uY,
                               unsigned int uZ, unsigned int uW) override;
    virtual void ResetUIClipRect() override;

    virtual void DrawTextureNew(float u, float v, class Image *img, uint32_t colourmask = 0xFFFFFFFF) override;
    virtual void DrawTextureAlphaNew(float u, float v, class Image *) override;
    virtual void DrawTextureCustomHeight(float u, float v, class Image *,
                                         int height) override;
    virtual void DrawTextureOffset(int x, int y, int offset_x, int offset_y,
                                   Image *) override;
    virtual void DrawImage(Image *, const Recti &rect, uint paletteid = 0) override;

    virtual void ZDrawTextureAlpha(float u, float v, Image *pTexture, int zVal) override;
    virtual void BlendTextures(int x, int y, Image *imgin, Image *imgblend,
                               int time, int start_opacity, int end_opacity) override;
    virtual void DrawMonsterPortrait(Recti rc, SpriteFrame *Portrait, int Y_Offset) override;

    virtual void DrawMasked(float u, float v, class Image *img,
                            unsigned int color_dimming_level, uint16_t mask) override;
    virtual void TexturePixelRotateDraw(float u, float v, Image * img, int time) override;
    virtual void DrawTextureGrayShade(float u, float v, class Image *a4) override;
    virtual void DrawTransparentRedShade(float u, float v, class Image *a4) override;
    virtual void DrawTransparentGreenShade(float u, float v,
                                           class Image *pTexture) override;


    virtual void MaskGameViewport() override;

    virtual void DrawTextAlpha(int x, int y, uint8_t *font_pixels, int a5,
                               unsigned int uFontHeight, uint8_t *pPalette,
                               bool present_time_transparency) override;
    virtual void DrawText(int uOutX, int uOutY, uint8_t *pFontPixels,
                          unsigned int uCharWidth, unsigned int uCharHeight,
                          uint8_t *pFontPalette, uint16_t uFaceColor,
                          uint16_t uShadowColor) override;

    virtual void BeginTextNew(Texture *main, Texture *shadow) override;
    virtual void EndTextNew() override;
    virtual void DrawTextNew(int x, int y, int w, int h, float u1, float v1, float u2, float v2, int isshadow, uint16_t colour) override;

    virtual void FillRectFast(unsigned int uX, unsigned int uY,
                              unsigned int uWidth, unsigned int uHeight,
                              unsigned int uColor16) override;

    virtual void DrawBuildingsD3D() override;

    virtual void DrawIndoorSky(unsigned int uNumVertices, unsigned int uFaceID) override;
    virtual void DrawOutdoorSkyD3D() override;

    virtual void PrepareDecorationsRenderList_ODM() override;

    virtual void DrawTerrainD3D() override;

    virtual bool AreRenderSurfacesOk() override;

    virtual Image *TakeScreenshot(unsigned int width, unsigned int height) override;
    virtual void SaveScreenshot(const std::string &filename, unsigned int width,
                                unsigned int height) override;
    virtual void PackScreenshot(unsigned int width, unsigned int height,
                                void *out_data, unsigned int data_size,
                                unsigned int *screenshot_size) override;
    virtual void SavePCXScreenshot() override;

    virtual int GetActorsInViewport(int pDepth) override;

    virtual void BeginLightmaps() override;
    virtual void EndLightmaps() override;
    virtual void BeginLightmaps2() override;
    virtual void EndLightmaps2() override;
    virtual bool DrawLightmap(struct Lightmap *pLightmap,
                              Vec3f *pColorMult, float z_bias) override;

    virtual void BeginDecals() override;
    virtual void EndDecals() override;
    virtual void DrawDecal(struct Decal *pDecal, float z_bias) override;

    virtual void Do_draw_debug_line_d3d(const RenderVertexD3D3 *pLineBegin,
                                        signed int sDiffuseBegin,
                                        const RenderVertexD3D3 *pLineEnd,
                                        signed int sDiffuseEnd, float z_stuff) override;
    virtual void DrawLines(const RenderVertexD3D3 *vertices,
                           unsigned int num_vertices) override;

    virtual void DrawSpecialEffectsQuad(const RenderVertexD3D3 *vertices,
                                        Texture *texture) override;

    virtual void DrawFromSpriteSheet(Recti *pSrcRect, Pointi *pTargetPoint, int a3,
                               int blend_mode) override;

    virtual void ReleaseTerrain() override;
    virtual void ReleaseBSP() override;
    virtual void DrawTwodVerts() override;

    virtual void DrawIndoorFaces() override;

    virtual Sizei GetRenderDimensions() override;
    virtual Sizei GetPresentDimensions() override;
    virtual bool Reinitialize(bool firstInit) override;
    virtual void ReloadShaders() override;

 public:
    virtual void WritePixel16(int x, int y, uint16_t color) override;

    friend void Present_NoColorKey();

    void GetTargetPixelFormat(DDPIXELFORMAT *pOut);

 protected:
    IDirectDraw4 *pDirectDraw4;
    IDirectDrawSurface4 *pFrontBuffer4;
    IDirectDrawSurface4 *pBackBuffer4;

    unsigned int uDesiredDirect3DDevice;
    int *pDefaultZBuffer;
    unsigned int bWindowMode;
    RenderD3D *pRenderD3D;
    unsigned int uTargetRBits;
    unsigned int uTargetGBits;
    unsigned int uTargetBBits;
    unsigned int uNumD3DSceneBegins;
    unsigned int bRequiredTextureStagesAvailable;
    unsigned int uMaxDeviceTextureDim;
    unsigned int uMinDeviceTextureDim;

    // 2D drawing
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::Bitmap *p2DSurface;
    Gdiplus::Graphics *p2DGraphics;

    void DoRenderBillboards_D3D();
    void SetBillboardBlendOptions(RenderBillboardD3D::OpacityType a1);
    unsigned int GetParentBillboardID(unsigned int uBillboardID);
    unsigned int GetBillboardDrawListSize();

    void DrawBorderTiles(struct Polygon *poly);

    unsigned short *MakeScreenshot16(signed int width, signed int height);
    bool CheckTextureStages();
    void ParseTargetPixelFormat();

    void CreateClipper();

    void SavePCXImage16(const std::string &filename, uint16_t *picture_data,
                        int width, int height);
    void SavePCXImage32(const std::string &filename, uint16_t *picture_data,
                        int width, int height);

    Gdiplus::Bitmap *BitmapWithImage(Image *image);

    bool LockSurface_DDraw4(IDirectDrawSurface4 *pSurface,
                            DDSURFACEDESC2 *pDesc, unsigned int uLockFlags);
    void DrawOutdoorSkyPolygon(struct Polygon *pSkyPolygon);
    void DrawIndoorSkyPolygon(int uNumVertices, struct Polygon *pSkyPolygon);

    void BatchTriDraw();
    void DrawIndoorBatched();
};