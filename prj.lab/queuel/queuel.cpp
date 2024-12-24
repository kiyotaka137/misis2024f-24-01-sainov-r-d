#include <queuel/queuel.hpp>
#include<algorithm>






QueueL::QueueL(const QueueL& src)
{
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

QueueL& QueueL::operator=(const QueueL& src)
{
	if (this == &src) {
		return *this;
	}

	Clear();

	Node* current = src.head_;
	while (current != nullptr) {
		Push(current->val);
		current = current->next;
	}
	return *this;
}

void QueueL::Pop() noexcept{
	if (!IsEmpty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
}

void QueueL::Push(const float value){	
	Node* newNode = new Node{ value, nullptr };
	if (tail_ == nullptr) {
		head_ = newNode;
		tail_ = newNode;
	}
	else {
		tail_->next = newNode;
		tail_ = newNode;
	}
}

bool QueueL::IsEmpty() const noexcept
{
	return (head_ == nullptr && tail_== nullptr);
}

float& QueueL::Top(){
	if (IsEmpty()) {
		throw(std::exception("Top - queue is Empty"));
	}
	return head_->val;
}

const float& QueueL::Top() const{
	if (IsEmpty()) {
		throw(std::exception("Top - queue is Empty"));
	}
	return head_->val;
}

void QueueL::Clear() noexcept
{
	while (!IsEmpty()) {
		Pop();
	}
}

