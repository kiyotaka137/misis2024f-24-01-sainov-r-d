#include "stacka.h"
#include< memory>
#include<stdexcept>
#include<algorithm>
StackA::StackA(const StackA& src)
{
	data_ = new T[src.size_];
	std::copy(src, src + src.head_, data_);
}
StackA::StackA(StackA&& src)
{
	std::move(src);
}
StackA::~StackA()
{
	delete[] data_;
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

