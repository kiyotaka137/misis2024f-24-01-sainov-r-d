#ifndef QUEUEA_HPP
#define QUEUEA_HPP
#include <cstddef>
#include <cstdint>
class QueueA final {
public:
	using T = std::uint8_t;
	QueueA(T size);
	QueueA(const QueueA& scr);
	QueueA(QueueA&& scr) noexcept;
	~QueueA();
	QueueA& operator=(const QueueA& scr);
	QueueA& operator=(QueueA&& scr);
	void Pop() noexcept;
	void Push(const T value);
	T& Top();
	const T& Top() const;
	void Clear() noexcept;
private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t head_ = -1;
	std::ptrdiff_t	tail_ = -1;
	T* data_ = nullptr;
	std::ptrdiff_t Count() const;
	void Swap(QueueA&& src) noexcept;

};
#endif
