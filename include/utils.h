#pragma once
#include <iostream>
struct vector3
{
    int x,y,z;

    vector3(const int _x, const int _y, const int _z)
    :x(_x), y(_y), z(_z)
    {
        std::cout << "Vector has been created\n";
    }

};