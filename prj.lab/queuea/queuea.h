#pragma once
#ifndef QUEUEA_H
#define QUEUEA_H
#include <cstddef>
#include <cstdint>
class QueueA final {
public:
	using T = std::uint8_t;
	QueueA() = default;
	QueueA(const QueueA& scr);
	QueueA(QueueA&& scr) noexcept;
	~QueueA();
	QueueA& operator=(const QueueA& scr);
	QueueA& operator=(QueueA&& scr) noexcept;
	void Pop() noexcept;
	void Push(const T value);
	bool IsEmpty() const noexcept;
	T& Top();
	const T& Top() const;
	void Clear() noexcept;
private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t head_ = -1;
	std::ptrdiff_t	tail_ = -1;
	T* data_ = nullptr;
private:
	std::ptrdiff_t Count() const;
	void Swap(QueueA&& src) noexcept;

};
#endif
