/*#pragma once
#ifndef QUEUEL_H
#define QUEUEL_H
#include <cstddef>
#include <cstdint>
class QueueL final {
public:
	using T = std::uint8_t;
	QueueL() = default;
	QueueL(const QueueL& scr);
	QueueL(QueueL&& scr) noexcept;
	~QueueL() = default;
	QueueL& operator=(const QueueL& scr);
	QueueL& operator=(QueueL&& scr) noexcept;
	void Pop() noexcept;
	void Push(const T value);
	bool IsEmpty() const noexcept;
	T& Top();
	const T& Top() const;
	void Clear() noexcept;
private:
	struct Node {
		T val = T();
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr
};
#endif*/