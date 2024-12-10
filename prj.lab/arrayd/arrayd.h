#ifndef ARRAYD_H
#define ARRAYD_H

class ArrayD {
private:
	std::ptrdiff_t size_{ 0 };
	std::ptrdiff_t capacity_{ 0 };
	double* data_{ nullptr };
public:
	ArrayD() = default;
	ArrayD(const std::ptrdiff_t n);
	ArrayD(const ArrayD& d) = default;
	ArrayD& operator=(const ArrayD& d) = default;
	~ArrayD();

	double& operator[](std::ptrdiff_t ind);
	double operator[](std::ptrdiff_t ind) const;

	std::ptrdiff_t Size() const;

	void Resize(std::ptrdiff_t size);
	void Insert(std::ptrdiff_t ind, const double& elem);
	void Remove(const std::ptrdiff_t ind);
};

#endif

