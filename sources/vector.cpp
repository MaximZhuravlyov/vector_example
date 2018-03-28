#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;	
}

vector_t::vector_t(vector_t const & other)
{
	size_= other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
        for(size_t i=0;i<size_;++i)
                elements_[i]=other.elements_[i];
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this->elements_ == other.elements_)
	return *this;
	if (this != &other)
        {
                delete[] elements_;
		size_ = other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
                for (size_t i = 0; i <= size_; ++i)
                        elements_[i] = other.elements_[i];
		return *this;
        }
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size_ != other.size_)
		return false;
	else {
		for (size_t i = 0 ; i < size_; i++)
		if (elements_[i] != other.elements_[i])
			return false;
	}
	return true;
}

vector_t::~vector_t()
{
	if (elements_ != nullptr)
	delete [] elements_;
	size_ = 0;
	capacity_ = 0;
}

std::size_t vector_t::size() const
{
	return size_;
}

std::size_t vector_t::capacity() const
{
	return capacity_;
}

void vector_t::push_back(int value)
{
	if ((capacity_ == size_) && (size_ !=0))
	{
	int *vector_copy = new int [capacity_ * 2];
	capacity_ *= 2;
	for (size_t i = 0; i< size_; i++)
		vector_copy[i] = elements_[i];
	size_++;
	vector_copy[size_ - 1] = value;
	delete [] elements_;
	elements_ = new int [capacity_];
	for (size_t i = 0; i < size_; i++)
		elements_[i] = vector_copy[i];
	delete [] vector_copy;
	return;
	}
	if (size_ == 0)
	{
		size_ = 1;
		elements_ = new int [1];
		capacity_ = 1;
		elements_[0] = value;
		return;
	}
	size_++;
	elements_ [size_ - 1] = value;
	return;
}

void vector_t::pop_back()
{
	if (size_==0)
	return;
	if (size_==1)
	{
		size_=0;
		capacity_=1;
		return;
	}
	size_--;
	if (capacity_ == (4 * size_))
	{
	int *vector_copy = new int [capacity_ / 2];
	capacity_ /= 2;
	for (size_t i = 0; i< size_; i++)
		vector_copy[i] = elements_[i];
	delete [] elements_;
	elements_ = new int [capacity_];
	for (size_t i = 0; i < size_; i++)
		elements_[i] = vector_copy[i];
	delete [] vector_copy;
	return;
	}
}

int & vector_t::operator [](std::size_t index)
{
	if (index <= size_)
		return elements_[index];
        else
               return elements_[size_ - 1];
}

int vector_t::operator [](std::size_t index) const
{
	if (index <= size_)
                return elements_[index];
	else
		return elements_[size_ - 1];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if (lhs.size() != rhs.size()) 
		return false;
	else 
		for (unsigned int i=0; i< lhs.size(); i++)
		      if (lhs[i] !=rhs[i])
			     return false;
	return true;
}
