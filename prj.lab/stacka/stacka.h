#pragma once
#ifndef StackA_StackA_H_20241203
#define StackA_StackA_H_20241203

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
    StackA operator=()
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