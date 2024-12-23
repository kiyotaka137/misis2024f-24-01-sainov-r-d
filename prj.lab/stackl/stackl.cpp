#include <stackl/stackl.h>
#include<memory>
#include<stdexcept>
using T = uint8_t;
StackL::StackL(const StackL& src) {
    if (!src.IsEmpty()) {
        head_ = new Node{ src.head_->val };
        Node* p_src = src.head_;
        Node* p_dst = head_;
        while (p_src->next) {
            p_dst->next = new Node{ p_src->next->val };
            p_src = p_src->next;
            p_dst = p_dst->next;
        }
    }
}
StackL& StackL::operator=(StackL&& src) noexcept {
    std::swap(head_, src.head_);
    return *this;
}

bool StackL::IsEmpty() const noexcept{
    return nullptr == head_;
}
void StackL::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
}
void StackL::Push(const T val) {
    head_ = new Node{ val, head_ };
}

T& StackL::Top()&{
    if (IsEmpty()) {
        throw(std::exception("Top - stack is empty"));
    }
    return head_->val;
}

const T& StackL::Top() const&
{
    if (IsEmpty()) {
        throw(std::exception("Top - stack is empty"));
    }
    return head_->val;
}
void StackL::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}