// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>

#include<image.h>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void medianFilter(const unsigned char input[][HEIGHT], unsigned char output[][HEIGHT], unsigned int width, unsigned int height)
{

    //TODO: put your implementation here
    int i = 0;
    int window_width = 3;
    int window_height = 3;
    char window[window_width * window_height];

    int edgex = window_width / 2;
    int edgey = window_height / 2;

    for (int x = edgex; x <= width - edgex; x++){
        for (int y = edgex; y <= height - edgey; y++){
            i = 0;
            for (int fx = 0; fx < window_width; fx++){
                for (int fy = 0; fy < window_height; fy++){
                    window[i] = input[x + fx - edgex][y + fy - edgey];
                    i++;
                }
            }
            sort(window, window + (window_width * window_height));
            output[x][y] = window[window_width * window_height / 2];
        }
    }

}

