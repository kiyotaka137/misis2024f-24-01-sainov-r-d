#pragma once
#ifndef STACKA_H
#define STACKA_H

#include <cstddef>
#include <cstdint>

class StackA final {
public:
    using T = std::uint8_t;
public:
    StackA() = default;
    StackA(const StackA& src);
    StackA(StackA&& src);
    ~StackA();
    StackA& operator=(const StackA& src);
    StackA& operator=(StackA&& src) noexcept;
    bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const T val);
    void CLear() noexcept;
private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t head_ = -1;
    T* data_ = nullptr;

};
#endif