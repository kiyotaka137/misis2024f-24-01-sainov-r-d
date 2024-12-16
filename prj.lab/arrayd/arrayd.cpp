#include<cstddef>
#include<iostream>
#include<cstring>
#include<stdexcept>

#include "arrayd/arrayd.h"


ArrayD::ArrayD(const std::ptrdiff_t n) : size_(n), capacity_(n) {
	if (size_ < 0) {
		throw std::invalid_argument("non positive size");
		data_ = new double[n];
	}
}

ArrayD::ArrayD(const ArrayD& arrd){
	capacity_ = arrd.size_;
	size_ = arrd.size_;
	data_ = new double[size_];
	for (std::ptrdiff_t i = 0; i < arrd.size_; i++) {
		data_[i] = arrd.data_[i];
	}
}

ArrayD& ArrayD::operator=(const ArrayD & rhs) {
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
	return *(data_ + ind);
}

double ArrayD::operator[](std::ptrdiff_t ind) const {
	if (ind < 0 || size_ <= ind) throw (std::exception("ArrayD::operator[] - invalid argument"));
	return data_[ind];
}

std::ptrdiff_t ArrayD::Size() const {
	return size_;
}

void ArrayD::Resize(std::ptrdiff_t size) {
	if (size_ <= 0) {
		throw std::invalid_argument("non positive size");
	}
	double* newdata = new double[size];
	for (std::ptrdiff_t i = 0; i < size_; i++) {
		newdata[i] = data_[i];
	}
	delete[] data_;
	size_ = size;
	data_ = newdata;
	capacity_ = size;
	delete[] newdata;
}

void ArrayD::Insert(std::ptrdiff_t ind, const double& elem){
	if (ind > size_) {
		throw(std::exception("out of range"));
	}

	if (size_ == capacity_) {
		(*this).Resize(capacity_ * 2);
	}

	
}

void ArrayD::Remove(const std::ptrdiff_t ind)
{
	if (ind > size_) throw(std::exception("out of range"));
	for (ptrdiff_t i = ind; i < size_ - 1; i++) {
		data_[i] = data_[i + 1];
	}
	size_ -= 1;
}
