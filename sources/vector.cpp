#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	std::size_t size_ = 0;
	std::size_t capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
        for(size_t i=0;i<size_;++i)
                elements_[i]=other.elements_[i];
}//dim=size

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this != &other)
        {
                delete[] elements_;
                for (size_t i=0; i <= size_; ++i)
                        elements_[i]=other.elements_[i];
        }
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if(size_ != other.size_)
		return false;
	else
		return true;
	//return false;
}

vector_t::~vector_t()
{
	delete[] elements_;
}

std::size_t vector_t::size() const
{
	return size_;
    //return 0;
}

std::size_t vector_t::capacity() const
{
	return capacity_;
    //return 0;
}

void vector_t::push_back(int value)
{
	if(size_ > capacity_)
		capacity_ *= 2;
	size_++;
	elements_[size-1]=value;
	return;
}

void vector_t::pop_back()
{
	if(size_ != 0)
	size_ -= 1;
	else
		return;
	if((4 * size_) == capacity_)
		capacity_ /= 2;
	
}

int & vector_t::operator [](std::size_t index)
{
	if (index <= size_)
                return elements_[index];
        else
               return 0;
	//return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	if (index <= size_)
                return 1;
	return 1;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if(lhs.size_ != rhs.size_)
		return true;
	else
		return false;
	return true;
}
