#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    public:
    // canonical orthodox form
        Fixed(void);
        Fixed(Fixed const & src);
        Fixed & operator=(Fixed const & rhs);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif