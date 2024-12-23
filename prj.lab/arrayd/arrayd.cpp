#include<cstddef>
#include<iostream>
#include<cstring>
#include<stdexcept>
#include<memory>
#include <arrayd/arrayd.hpp>


ArrayD::ArrayD(const std::ptrdiff_t n)
	:size_(n)
	,capacity_(n){
	if (size_ < 0) {
		throw std::invalid_argument("non positive size");
	}
	if (size_ == 0) {
		data_ = new double[capacity_];
		return;
	}
	data_ = new double[capacity_] {0.0};
}

ArrayD::ArrayD(const ArrayD& arrd):
	size_(arrd.size_)
	,capacity_(arrd.size_)
	,data_(new double[size_]){
	std::memcpy(data_, arrd.data_, size_ * sizeof(*data_));
}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
	if (this != &rhs) {
		Resize(rhs.size_);
		std::memcpy(data_, rhs.data_, size_ * sizeof(*data_));
	}
	return *this;
}

ArrayD::~ArrayD()
{
	delete[] data_;
}

double& ArrayD::operator[](std::ptrdiff_t ind) {
	if (ind < 0 || size_<=ind) throw (std::exception("ArrayD::operator[] - invalid argument"));
	return data_[ind];
}

double ArrayD::operator[](std::ptrdiff_t ind) const {
	if (ind < 0 || size_ <= ind) throw (std::exception("ArrayD::operator[] - invalid argument"));
	return *(data_+ind);
}

std::ptrdiff_t ArrayD::Size() const {
	return size_;
}

void ArrayD::Resize(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("ArrayD::Resize - non positive size");
	}
	if (capacity_ < size) {
		auto data = new double[size] {0.0};
		if (0 < size_) {
			std::memcpy(data, data_, size_ * sizeof(*data_));
		}
		std::swap(data_, data);
		delete[] data;
		capacity_ = size;
	}
	else {
		if (size_ < size) {
			std::memset(data_ + size_, 0, (size - size_) * sizeof(*data_));
		}
	}
	size_ = size;
}

void ArrayD::Remove(std::ptrdiff_t index) {
	if (index<0 && index>size_) {
		throw std::out_of_range("out of range");
	}
	if (index != size_ - 1) {
		std::memmove(data_ + index, data_ + index + 1, (size_ - index) * sizeof(double));
	}
	Resize(size_ - 1);
}

void ArrayD::Insert(std::ptrdiff_t index, const double& elem) {
	if (index < 0 || size_ < index) {
		throw std::invalid_argument("ArrayD::Insert - invalid index");
	}
	Resize(size_ + 1);
	if (index != Size() - 1) {
		std::memmove(data_ + index + 1, data_ + index, (size_ - index - 1) * sizeof(double));
	}
	data_[index] = elem;
}