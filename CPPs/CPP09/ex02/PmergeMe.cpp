#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : m_data(other.m_data), m_deq(other.m_deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        m_data = other.m_data;
        m_deq = other.m_deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::setData(const std::vector<double>& data)
{
    m_data = data;
}

void PmergeMe::setDeq(const std::deque<double>& deq)
{
    m_deq = deq;
}

std::vector<double>& PmergeMe::getData()
{
    return m_data;
}

std::deque<double>& PmergeMe::getDeq()
{
    return m_deq;
}
