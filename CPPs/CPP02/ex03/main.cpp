#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    // implement example of bsp function  

    Point a(3, 6);
    Point b(0, 0);
    Point c(9, 2);
    Point point_1(8, 3);
    Point point_2(4, 3);
    std::cout << "Point is inside the triangle: " << bsp(a, b, c, point_1) << std::endl;
    std::cout << "Point is inside the triangle: " << bsp(a, b, c, point_2) << std::endl;

    return 0;
}