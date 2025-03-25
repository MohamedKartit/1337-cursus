#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
    // canonical orthodox form
        Fixed(void);
        Fixed(Fixed const & src);
        ~Fixed(void);
        Fixed &operator=(Fixed const & rhs);

        Fixed(float const value);
        Fixed(int const value);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif