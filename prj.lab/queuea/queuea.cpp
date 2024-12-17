#include <queuea/queuea.h>

#include <algorithm>
#include <stdexcept>

std::ptrdiff_t QueueA::Count() const {
    if (IsEmpty() == true) {
        return 0;
    }
    else {
        return (tail_ + size_ - head_) % size_ +1;
    }
}

QueueA& QueueA::operator=(const QueueA& src) {
    if (this != &src) {
        std::ptrdiff_t count = src.Count();
        if (count ==0) {
            head_ = -1;
        }
        else {
            if (size_ < count) {
                size_ =count + count%4 + 4;
                delete[] data_;
                data_ = new T[size_];
            }
            if (src.head_ < src.tail_) {
                std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
            }
            else {
                std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
                std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
            }
            head_ = 0;
            tail_ = count - 1;
        }
    }
    return *this;
}

QueueA::QueueA(const QueueA& src) {
    if (!src.IsEmpty()) {
        std::ptrdiff_t count = src.Count();
        head_ = 0;
        tail_ = count - 1;
        size_ = count + count % 4 + 4;
        data_ = new T[size_];
        if (src.head_ < src.tail_) {
            std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
        }
        else {
            std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
            std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
        }
        
    }
}

void QueueA::Swap(QueueA&& src) noexcept {
    std::swap(size_, src.size_);
    std::swap(data_, src.data_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
}

QueueA::QueueA(QueueA&& src) noexcept {
    Swap(std::move(src));
}

QueueA& QueueA::operator=(QueueA&& src) {
    if (this != &src) {
        Swap(std::move(src));
    }
    return *this;
}

QueueA::~QueueA() {
    delete[] data_;
}

bool QueueA::IsEmpty() const noexcept {
    return (head_ < 0);
}

void QueueA::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % size_;
        }
        else {
            head_ = -1;
        }
    }
}

void QueueA::Push(const T val) {
    if (data_==nullptr) {
        size_ = 2;
        data_ = new T[size_];
    }
    if (IsEmpty()) {
        head_ = 0;
        tail_ = 0;
    }
    else {
        if (head_ == (tail_ + 1) % size_) {
            T* buffer = new T[size_ * 2];
            std::swap(buffer, data_);
            if (head_ < tail_) {
                std::copy(buffer + head_, buffer + tail_ + 1, data_);
            }
            else {
                std::copy(buffer + head_, buffer + size_, data_);
                std::copy(buffer, buffer + tail_ + 1, data_ + tail_ - head_);
            }
            delete[] buffer;
            size_ *= 2;
            tail_ = Count();
        }
        else {
            tail_ = (tail_ + 1) % size_;
        }
    }
    data_[tail_] = val;
}

QueueA::T& QueueA::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueA is empty");
    }
    return data_[head_];
}

const QueueA::T& QueueA::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueA is empty");
    }
    return data_[head_];
}

void QueueA::Clear() noexcept {
    head_ = -1;
}