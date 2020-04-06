#include "Pallete.h"

#include <cstdio>
#include <cstring>

#include "Display.h"

// Ctor
Pallete::Pallete(uint16_t col[])
{
	for (int i = rgbCount; 0 != i--;)
	{
		for (int j = cornerCount; 0 != j--;)
		{
			rgbCorner[i][j] = (col[j] & RGBMSK[i]) >> RGBOFF[i];
		}
	}
}

// Get value in given range
uint16_t Pallete::Range(uint16_t s, uint16_t e, uint16_t d, uint16_t l)
{
	int inc = ((e + 1) - s) * d / l;	// Can be negative

	return (uint16_t)(s + inc);
}

// Get colour at given co-ordinate
uint16_t Pallete::Colour(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	uint16_t ret;

	if ((w - 1) == x)
	{
		if ((h - 1) == y)
		{
			// Bottom left corner
			ret = rgbCorner[red][br] << RGBOFF[red]
				| rgbCorner[grn][br] << RGBOFF[grn]
				| rgbCorner[blu][br] << RGBOFF[blu];
		}
		else
		{
			// Left edge
			ret = Range(rgbCorner[red][tr], rgbCorner[red][br], y, h) << RGBOFF[red]
				| Range(rgbCorner[grn][tr], rgbCorner[grn][br], y, h) << RGBOFF[grn]
				| Range(rgbCorner[blu][tr], rgbCorner[blu][br], y, h) << RGBOFF[blu];
		}
	}
	else if ((h - 1) == y)
	{
		// Bottom edge
		ret = Range(rgbCorner[red][bl], rgbCorner[red][br], x, w) << RGBOFF[red]
			| Range(rgbCorner[grn][bl], rgbCorner[grn][br], x, w) << RGBOFF[grn]
			| Range(rgbCorner[blu][bl], rgbCorner[blu][br], x, w) << RGBOFF[blu];
	}
	else
	{
		// General case
		ret = 0;

		for (int i = rgbCount; 0 != i--;)
		{
			ret |= Range(
				Range(rgbCorner[i][tl], rgbCorner[i][bl], y, h),
				Range(rgbCorner[i][tr], rgbCorner[i][br], y, h), x, w) << RGBOFF[i];
		}
	}

	return ret;
}
