#ifndef PALLETE_H_INCLUDED
#define PALLETE_H_INCLUDED

#include <cstdint>

class Pallete
{
public:
    enum
    {
        tl,
        tr,
        bl,
        br,
        cornerCount
    };

    Pallete(uint16_t col[]);
    ~Pallete() = default;

    // Get colour at given location
    uint16_t Colour(uint16_t, uint16_t, uint16_t, uint16_t);

private:
    enum
    {
        red,
        grn,
        blu,
        rgbCount
    };

    // RGB masks and bit offsets
    const uint16_t RGBMSK[rgbCount] = { 0xf800, 0x07e0, 0x001f };
    const uint16_t RGBOFF[rgbCount] = { 11, 5, 0 };

    // RGB corner values
    uint16_t rgbCorner[rgbCount][cornerCount] = { 0 };

    // Get value in given range
    uint16_t Range(uint16_t, uint16_t, uint16_t, uint16_t);
};

#endif
