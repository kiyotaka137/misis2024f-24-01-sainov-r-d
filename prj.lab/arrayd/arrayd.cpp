#include<cstddef>
#include<iostream>
#include<cstring>
#include<stdexcept>

#include "arrayd/arrayd.h"


ArrayD::ArrayD(const std::ptrdiff_t n) : size_(n), capacity_(n), data_(new double[n]) {
	if (size_ < 0) {
		throw std::invalid_argument("non positive size");
	}
	data_ = new double[n];
}

ArrayD::ArrayD(const ArrayD& arrd){
	capacity_ = arrd.size_;
	size_ = arrd.size_;
	data_ = new double[size_];
	std::memcpy(data_, arrd.data_, size_ * sizeof(double));
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
	return data_[ind];
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
	if (size <= capacity_) {
		size_ = size;
		return;
	}
	double* newdata = new double[size];
	std::memcpy(newdata, data_, size_ * sizeof(double));
	delete[] data_;
	size_ = size;
	data_ = newdata;
	capacity_ = size;
	delete[] newdata;
}

void ArrayD::Remove(std::ptrdiff_t index) {
	if (index<0 && index>size_) {
		throw std::out_of_range("out of range");
	}
	else {
		double last = data_[size_ - 1];
		this->Resize(size_ - 1);
		double* temp = new double[size_];
		for (std::ptrdiff_t i = 0; i < index; i++) {
			temp[i] = data_[i];
		}
		for (std::ptrdiff_t i = index; i < size_ - 1; i++) {
			temp[i] = data_[i + 1];
		}
		temp[size_ - 1] = last;
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
}

void ArrayD::Insert(std::ptrdiff_t index, const double& elem) {
	if (index<0 && index>size_) {
		throw std::out_of_range("out of range");
	}
	else {
		this->Resize(size_ + 1);
		double* temp = new double[size_];
		for (std::ptrdiff_t i = 0; i < index; i++) {
			temp[i] = data_[i];
		}
		temp[index] = elem;
		for (std::ptrdiff_t i = index + 1; i < size_; i++) {
			temp[i] = data_[i - 1];
		}
		delete[] data_;
		data_ = temp;
		temp = nullptr;
	}
}