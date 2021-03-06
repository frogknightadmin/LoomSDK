/*
 * ===========================================================================
 * Loom SDK
 * Copyright 2011, 2012, 2013
 * The Game Engine Company, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ===========================================================================
 */

#pragma once

#include <math.h>
#include "loom/graphics/gfxTexture.h"
#include "loom/engine/loom2d/l2dRectangle.h"
#include "loom/engine/loom2d/l2dMatrix.h"
#include "loom/common/utils/utTypes.h"
struct NSVGimage;

namespace GFX
{

struct VectorLineCaps {
    enum Enum {
        NONE,
        ROUND,
        SQUARE,
    };
};

struct VectorLineJoints {
    enum Enum {
        MITER,
        ROUND,
        BEVEL,
    };
};

struct VectorLineScaleMode {
    enum Enum {
        NORMAL,
        NONE,
    };
};

struct VectorWinding {
    enum Enum {
        CCW = 1,
        CW  = 2,
    };
};

/*
class VectorFont {
protected:
    int id;

public:
    utString fontName;

    VectorFont(utString fontName, utString filePath);
};
*/

class VectorTextFormat {
protected:
    static utHashTable<utHashedString, utString> loadedFonts;

public:
    enum TextAlign {
        // Horizontal align
        ALIGN_LEFT = 1 << 0,    // Default, align text horizontally to left.
        ALIGN_CENTER = 1 << 1,    // Align text horizontally to center.
        ALIGN_RIGHT = 1 << 2,    // Align text horizontally to right.
        // Vertical align
        ALIGN_TOP = 1 << 3,    // Align text vertically to top.
        ALIGN_MIDDLE = 1 << 4,    // Align text vertically to middle.
        ALIGN_BOTTOM = 1 << 5,    // Align text vertically to bottom.
        ALIGN_BASELINE = 1 << 6, // Default, align text vertically to baseline.
    };

    enum FontId {
        FONT_UNDEFINED = -1,
        FONT_NOTFOUND = -2,
        FONT_DEFAULTMISSING = -3,
        FONT_DEFAULTMEMORY = -4,
        FONT_REPORTEDERROR = -5
    };

    // Restore all the previously loaded fonts (on NVG context loss / quality change)
    static void restoreLoaded();

    // Load a font with the specified font name and path
    static void load(utString fontName, utString filePath);

    static VectorTextFormat defaultFormat;

    VectorTextFormat(int color = -1, float size = NAN) :
        fontId(FONT_UNDEFINED),
        font(""),
        color(color),
        size(size),
        align(VectorTextFormat::ALIGN_TOP | VectorTextFormat::ALIGN_LEFT),
        letterSpacing(NAN),
        lineHeight(NAN)
    {};

    void merge(VectorTextFormat* source);
    void ensureFontId();

    int fontId;
    utString font;
    inline const char* getFont() const { return font.c_str(); }
    void setFont(const char* t) { font = utString(t); }

    int color;
    inline int getColor() const { return color; }
    void setColor(int t) { color = t; }

    float size;
    inline float getSize() const { return size; }
    void setSize(float t) { size = t; }

    int align;
    inline int getAlign() const { return align; }
    void setAlign(int t) { align = t; }

    float letterSpacing;
    inline float getLetterSpacing() const { return letterSpacing; }
    void setLetterSpacing(float t) { letterSpacing = t; }

    float lineHeight;
    inline float getLineHeight() const { return lineHeight; }
    void setLineHeight(float t) { lineHeight = t; }

};

class VectorSVG {
protected:
    utString path;
    utString units;
    float dpi;

    NSVGimage* image;

    void reset();
    void resetInfo();
    void resetImage();
    void parse(const char* input, const char* units, float dpi);
public:
    float getWidth() const;
    float getHeight() const;

    VectorSVG();
    ~VectorSVG();
    static void onReload(void *payload, const char *name);
    void reload();
    void loadFile(utString path, utString units = utString("px"), float dpi = 96.0f);
    void loadString(utString svg, utString units = utString("px"), float dpi = 96.0f);
    void render(float x, float y, float scale, float lineThickness, float alpha);
};

class VectorRenderer
{
    friend class Graphics;

private:
    static utHashTable<utIntHashKey, int> imageLookup;

    static void initialize();

    static void deleteImages();
    static void ensureTextFormat();

    static void initializeGraphicsResources();
    static void destroyGraphicsResources();

public:
    static const uint8_t QUALITY_ANTIALIAS       = 1 << 0;
    static const uint8_t QUALITY_STENCIL_STROKES = 1 << 1;
    static uint8_t quality;
    static uint8_t tessellationQuality;

    static void reset();

    static int frameWidth;
    static int frameHeight;

    static void submit();

    static void setSize(int width, int height);

    static void beginFrame();
    static void endFrame();

    static void preDraw(lmscalar a, lmscalar b, lmscalar c, lmscalar d, lmscalar e, lmscalar f);
    static void postDraw();

    static void setClipRect(int x, int y, int w, int h);
    static void resetClipRect();

    static void clearPath();
    static void renderStroke();
    static void renderFill();

    static void strokeWidth(float size);
    static void strokeColor(float r, float g, float b, float a);
    static void strokeColor(unsigned int rgb, float a);
    static void strokeColor32(unsigned int argb, float a);

    static void lineCaps(VectorLineCaps::Enum caps);
    static void lineJoints(VectorLineJoints::Enum joints);
    static void lineMiterLimit(float limit);

    static void fillColor(float r, float g, float b, float a);
    static void fillColor(unsigned int rgb, float a);
    static void fillColor32(unsigned int argb, float a);
    static void fillTexture(TextureID id, Loom2D::Matrix transform, bool repeat, bool smooth, float alpha);

    static void textFormat(VectorTextFormat* format, lmscalar a);

    static void moveTo(float x, float y);
    static void lineTo(float x, float y);
    static void curveTo(float cx, float cy, float x, float y);
    static void cubicCurveTo(float c1x, float c1y, float c2x, float c2y, float x, float y);
    static void arcTo(float cx, float cy, float x, float y, float radius);

    static void circle(float x, float y, float radius);
    static void ellipse(float x, float y, float width, float height);
    static void rect(float x, float y, float width, float height);
    static void roundRect(float x, float y, float width, float height, float ellipseWidth, float ellipseHeight);
    static void roundRectComplex(float x, float y, float width, float height, float topLeftRadius, float topRightRadius, float bottomLeftRadius, float bottomRightRadius);
    static void arc(float x, float y, float radius, float angleFrom, float angleTo, VectorWinding::Enum direction);

    static void textLine(float x, float y, utString* string);
    static void textBox(float x, float y, float width, utString* string);

    static Loom2D::Rectangle textLineBounds(VectorTextFormat* format, float x, float y, utString* string);
    static float textLineAdvance(VectorTextFormat* format, float x, float y, utString* string);
    static Loom2D::Rectangle textBoxBounds(VectorTextFormat* format, float x, float y, float width, utString* string);

    static void svg(VectorSVG* image, float x, float y, float scale, float lineThickness, float alpha);

    static float* getBounds();

};

}
