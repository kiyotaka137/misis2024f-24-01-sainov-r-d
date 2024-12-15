#pragma once
#ifndef STACKL_HPP
#define STACK_HPP
#include <cstddef>
#include <cstdint>
class StackL final {
	using T = uint8_t;
	Stackl() = default;
	StackL(const StackL& src);
	StackL(StackL&& src) noexcept;
	~StackL();
	StackL& operator=(const StackL& src);
	StackL& operator=(StakL&& src) noexcept;
	[[nodiscard]] bool IsEmpty() const noexcept;
	void Pop() noexcept;
	void Push(const T val);

	[[nodiscard]] T& Top()&;

	[[nodiscard]] const T& Top() const&;

	void Clear() noexcept;

private:
	struct Node {
		T val = T();
		Node* next = nullptr;
	};

	Node* head_ = nullptr;   
};
#endif
