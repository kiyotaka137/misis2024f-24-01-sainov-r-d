#include <cstddef>
#include <memory>
#include<stdexcept>
class ArrayT {
public:
	ArrayT() = default;
	ArrayT(const ArrayT&);
	ArrayT(const std::ptrdiff_t size);
	~ArrayT() = default;
	ArrayT& operator=(const ArrayT&);
	std::ptrdiff_t Size() const noexcept;
	void Resize(const std::ptrdiff_t size)
private:
	std::ptrdiff_t capacity = 0;
	std::ptrdiff_t size_ = 0;
	std::unique_ptr<T[]> data_;
};