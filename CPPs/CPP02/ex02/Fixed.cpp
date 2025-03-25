#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return o;
}

bool Fixed::operator>(Fixed const & rhs) const {
    return this->_fixedPointValue > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const {
    return this->_fixedPointValue < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const {
    return this->_fixedPointValue >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const {
    return this->_fixedPointValue <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const {
    return this->_fixedPointValue == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const {
    return this->_fixedPointValue != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const & rhs) const {
    Fixed result;

    result.setRawBits(this->_fixedPointValue + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const & rhs) const {
    Fixed result;

    result.setRawBits(this->_fixedPointValue - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    Fixed result;

    result.setRawBits((this->_fixedPointValue * rhs.getRawBits()) >> this->_fractionalBits);
    return result;
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    Fixed result;

    result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / rhs.getRawBits());
    return result;
}

Fixed & Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);

    operator++();
    return tmp;
}

Fixed & Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);

    operator--();
    return tmp;
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
    return a < b ? a : b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
    return a > b ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
    return a < b ? a : b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
    return a > b ? a : b;
}
