#pragma once
#include <cstddef>
#include <memory>
#include<stdexcept>
class ArrayT { 
public:
	ArrayT() = default;
	~ArrayT() = default;

private:
	std::ptrdiff_t capacity = 0;
	std::ptrdiff_t size_ = 0;
	std::unique_ptr<T[]> data_;
}
