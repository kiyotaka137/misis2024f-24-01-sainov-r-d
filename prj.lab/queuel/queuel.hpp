#pragma once
#ifndef QUEUEL_H
#define QUEUEL_H
#include <cstddef>
#include <cstdint>
class QueueL final {
public:
	QueueL() = default;
	QueueL(const QueueL& src);
	~QueueL() = default;
	QueueL& operator=(const QueueL& src);
	void Pop() noexcept;
	void Push(const float value);
	bool IsEmpty() const noexcept;
	float& Top();
	const float& Top() const;
	void Clear() noexcept;
private:
	struct Node {
		float val = float();
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};
#endif