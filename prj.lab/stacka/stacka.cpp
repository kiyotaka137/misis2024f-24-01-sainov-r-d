#include <stacka/stacka.hpp>
#include<memory>
#include<stdexcept>
#include<algorithm>
StackA::StackA(const StackA& src)
{
	data_ = new T[src.size_];
	std::copy(src.data_, src.data_ + src.head_, data_);
}

StackA::~StackA()
{
	delete[] data_;
}

StackA& StackA::operator=(const StackA& src) {
	if (this == &src) {
		return *this; 
	}

	if (data_ != nullptr) {
		delete[] data_;
		data_ = nullptr;
	}

	size_ = src.size_;
	head_ = src.head_;

	if (size_ > 0) {
		data_ = new T[size_];
		std::copy(src.data_, src.data_ + size_, data_);
	}
	else {
		data_ = nullptr;
	}

	return *this;
}


bool StackA::IsEmpty() const noexcept
{
	return head_ == -1;
}

void StackA::Pop() noexcept
{
	if (!IsEmpty()) {
		*(data_ + head_) = -1;
		head_ -= 1;
	}
}

void StackA::Push(const T val)
{
	if (data_ == nullptr) {
		size_ = 2;
		data_ = new T[size_];
		head_ = 0;
		data_[head_] = val;
	}
	if (IsEmpty()) {
		head_ = 0;
		data_[head_] = val;
	}
	else {
		if (head_ == size_) {
			T* buffer = new T[size_ * 2];
			std::swap(data_, buffer);
			std::copy(buffer, buffer + head_, data_);
			delete[] buffer;
			size_ *= 2;
			head_ += 1;
			data_[head_] = val;
		}
		else {
			head_ += 1;
			data_[head_] = val;
		}
	}
}

void StackA::CLear() noexcept
{
	head_ = -1;
}

