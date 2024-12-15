#include <queuea/queuea.h>

QueueA::QueueA(T size): size_(size), tail(0), head(0)
{
	data_ = new int[size_];
}

QueueA::QueueA(const QueueA& scr)
{
	
}
QueueA::QueueA(QueueA&& scr) noexcept
{
}
~QueueA() { delete[] data_; }