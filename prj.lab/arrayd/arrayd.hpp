#ifndef ARRAYD_H
#define ARRAYD_H
#include <cstddef>
#include<iostream>
#include<stdexcept>
#include<memory>
class ArrayD {
public:
	ArrayD() = default;
	ArrayD(const std::ptrdiff_t n);
	ArrayD(const ArrayD& arrd);
	ArrayD& operator=(const ArrayD& rhs);
	
	~ArrayD();

	double& operator[](std::ptrdiff_t ind);
	double ArrayD::operator[](const std::ptrdiff_t ind) const;
	[[nodiscard]] std::ptrdiff_t Size() const;

	void Resize(std::ptrdiff_t size);
	void Insert(std::ptrdiff_t index, const double& elem);
	void Remove(const std::ptrdiff_t ind);
private:
	std::ptrdiff_t size_{ 0 };
	std::ptrdiff_t capacity_{ 0 };
	double* data_{ nullptr };
};

#endif

