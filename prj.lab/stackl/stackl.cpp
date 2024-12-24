#include <stackl/stackl.hpp>
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

StackL& StackL::operator=(const StackL& src) {
    if (this == &src) {
        return *this; 
    }

    Clear();

    Node* currentsrc = src.head_;
    Node* tail = nullptr; 

    while (currentsrc != nullptr) {
        Node* newNode = new Node;
        newNode->val = currentsrc->val;
        newNode->next = nullptr;

        if (head_ == nullptr) { 
            head_ = newNode;
            tail = head_; 
        }
        else {
            tail = newNode;
        }
        currentsrc = currentsrc->next;
    }

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

T& StackL::Top() {
    if (IsEmpty()) {
        throw(std::exception("Top - stack is empty"));
    }
    return head_->val;
}

const T& StackL::Top() const {
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