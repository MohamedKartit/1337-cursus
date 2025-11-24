#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &rhs);

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        if (std::distance(begin, end) > static_cast<long>(_maxSize - _numbers.size()))
            throw std::runtime_error("Not enough space to add all elements in range");
        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int getMaxSize() const;
    const std::vector<int> &getNumbers() const;
};

#endif 
