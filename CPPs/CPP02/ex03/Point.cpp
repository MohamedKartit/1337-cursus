#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(float x, float y) : _x(x), _y(y) {
    // std::cout << "Parametric constructor called" << std::endl;
}

Point::Point(Point const & src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Point::~Point() {
    // std::cout << "Destructor called" << std::endl;
}

Point & Point::operator=(Point const & rhs) {
    // std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs) {
        const_cast<Fixed &>(this->_x) = rhs.getX();
        const_cast<Fixed &>(this->_y) = rhs.getY();
    }
    return *this;
}

Fixed const &Point::getX(void) const {
    return this->_x;
}

Fixed const &Point::getY(void) const {
    return this->_y;
}

void Point::setX(Fixed const x) {
    const_cast<Fixed &>(this->_x) = x;
}

void Point::setY(Fixed const y) {
    const_cast<Fixed &>(this->_y) = y;
}