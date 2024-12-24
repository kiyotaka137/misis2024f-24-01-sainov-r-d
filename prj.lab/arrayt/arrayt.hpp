#pragma once
#ifndef ARRAYT_ARRAYT_H_20241202
#define ARRAYT_ARRAYT_H_20241202

#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T>
class ArrayT {
public:
    ArrayT() = default;
    ArrayT(const ArrayT& d);
    ArrayT(std::ptrdiff_t n);
    ArrayT& operator=(const ArrayT& d);

    ~ArrayT() = default;

    T& operator[](std::ptrdiff_t ind);
    T operator[](std::ptrdiff_t ind) const;

    std::ptrdiff_t Size() const noexcept { return size_; }

    void Resize(std::ptrdiff_t size);
    void Insert(std::ptrdiff_t index, const T elem);
    void Remove(const std::ptrdiff_t index);
private:
    std::ptrdiff_t capacity_{ 0 };
    std::ptrdiff_t size_{ 0 };
    std::unique_ptr<T[]> data_{ nullptr };
};


template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& src) : capacity_(src.size_), size_(capacity_) {
    data_.reset(new T[size_]{ T() });
    std::memcpy(data_.get(), src.data_.get(), src.size_ * sizeof(T));
}

template<class T>
ArrayT<T>::ArrayT(std::ptrdiff_t n) : capacity_(n), size_(n) {
    if (n <= 0) throw std::invalid_argument("size<0");
    data_.reset(new T[n]{ T() });
}

template<class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& rhs) {
    if (this != &rhs) {
        Resize(rhs.size_);
        std::copy(rhs.data_.get(), rhs.data_.get() + size_, data_.get());
    }
    return *this;
}

template<class T>
T& ArrayT<T>::operator[](std::ptrdiff_t ind) {
    if (ind < 0 || ind >= size_) throw std::invalid_argument("out of range");
    return *(data_.get() + ind);
}

template<class T>
T ArrayT<T>::operator[](std::ptrdiff_t ind) const {
    if (ind < 0 || ind >= size_) throw std::invalid_argument("out of range");
    return *(data_.get()+ind);
}


template<class T>
void ArrayT<T>::Resize(std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("size<0");
    }

    if (size > capacity_) {
        auto newdata = std::make_unique<T[]>(size);
        std::copy(data_.get(), data_.get() + size_, newdata.get());
        data_.swap(newdata);
        newdata.reset();
        capacity_ = size;
    }
    else {
        if (size > size_) {
            std::fill(data_.get() + size_, data_.get() + size, T());
        }
    }
    size_ = size;
}


template<class T>
void ArrayT<T>::Insert(std::ptrdiff_t index, const T elem) {
    if (index < 0 || index > size_) { 
        throw std::invalid_argument("invalid argument"); 
    }

    Resize(size_ + 1);

    std::memmove(data_.get() + index + 1, data_.get() + index, (size_ - index - 1) * sizeof(T));
    data_[index] = elem;
}


template<class T>
void ArrayT<T>::Remove(const std::ptrdiff_t index) {
    if (index < 0 || index >= size_) throw std::invalid_argument("invalid argument");


    std::memmove(data_.get() + index, data_.get() + index + 1, (size_ - index) * sizeof(T));

    Resize(size_ - 1);
}


#endif
