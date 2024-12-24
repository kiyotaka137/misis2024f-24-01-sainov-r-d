#pragma once
#ifndef STACKL_H
#define STACKL_H
#include <cstddef>
#include <cstdint>
class StackL final {
	using T = uint8_t;
	StackL() = default;
	StackL(const StackL& src);
	~StackL() = default;
	StackL& operator=(const StackL& src);
	bool IsEmpty() const noexcept;
	void Pop() noexcept;
	void Push(const T val);

	T& Top();

	const T& Top() const;

	void Clear() noexcept;

private:
	struct Node {
		T val = T();
		Node* next = nullptr;
	};

	Node* head_ = nullptr;   
};
#endif
