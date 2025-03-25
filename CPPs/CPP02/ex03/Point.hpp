#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point();
        Point(Point const & src);
        ~Point();
        Point & operator=(Point const & rhs);

        Point(float x, float y);
        Fixed const &getX(void) const;
        Fixed const &getY(void) const;
        void setX(Fixed const x);
        void setY(Fixed const y);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif