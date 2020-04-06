// ramp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Display.h"
#include "Pallete.h"

// Check argument validity
int argchk(char *argv, int &arg)
{
    try
    {
        arg = atoi(argv);

        if (arg < 0 || arg > 65535)
        {
            std::cout << "Argument Out of Range: " << argv;

            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid Command Line Argument: " << e.what();

        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Need At Least 2 Parameters";

        return 1;
    }

    uint16_t col[Pallete::cornerCount];

    int arg;

    if (argchk(argv[1], arg))
    {
        return 2;
    }

    col[Pallete::tl] = col[Pallete::bl] = (uint16_t)arg;

    if (argchk(argv[2], arg))
    {
        return 2;
    }

    col[Pallete::tr] = col[Pallete::br] = (uint16_t)arg;

    if (argc > 3)
    {
        if (argchk(argv[3], arg))
        {
            return 2;
        }

        col[Pallete::bl] = arg;
    }

    if (argc > 4)
    {
        if (argchk(argv[4], arg))
        {
            return 2;
        }
            
        col[Pallete::br] = arg;
    }

    const std::string displayName = "Ramp";

    Display *display = new Display(displayName);

    Dimension dimension = display->size();

    uint16_t width = dimension.width;
    uint16_t height = dimension.height;

    uint16_t *buf = (uint16_t *)malloc(width * height * sizeof(uint16_t));

    Pallete *pallete = new Pallete(col);

    if (NULL != buf)
    {
        for (uint16_t x = width; 0 != x--;)
        {
            for (uint16_t y = height; 0 != y--;)
            {
                buf[y * width + x] = pallete->Colour(x, y, width, height);
            }
        }

        Point point = { 0, 0 };

        display->draw(point, buf, width * height);

        display->present();

        free((void *)buf);
    }
    else
    {
        std::cout << "Memory Allocation Error...";

        return 4;
    }

    return 0;
}
