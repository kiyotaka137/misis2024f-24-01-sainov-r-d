#include "queuel.h"

QueueL::QueueL(const QueueL& scr)
{
	if (!scr.IsEpmty()) {
		head_ = new Node{ src.head_->val };
		Node* p_src = src.head_;
		Node* p_dst = head_;
		while (p_src->next) {
			p_dst->next = new Node{ p_src->next->val };
			tail_ = p_dst;
			p_src = p_src->next;
			p_dst = p_dst->next;
		}
	}
}

QueueL::QueueL(QueueL&& scr) noexcept // не доделал
{
	std::swap(head_, scr.head_);
	std::swap(tail_, scr.tail_);
}


QueueL& QueueL::operator=(const QueueL& scr) //не доделал 
{
	if (this != &src) {
		if (src.IsEmpty()) {
			Clear();
		}
		else {
			Node* p_src = src.head_;
			if (IsEmpty()) {
				head_ = new Node{ src.head_->val };
				tail_ = head_;
			}
			else {
				head_->val = src.head_->val;
				tail_ = head_;
			}
			Node* p_dst = head_;

		}
}
& QueueL::operator=(QueueL&& scr) noexcept
{
	std::swap(head_, src.head_); 
	std::swap(tail_, src.tail_);
	return *this;
}

void QueueL::Pop() noexcept
{
	if (!IsEmpty()) {
		Node* deleted = head_;
		head_ = head_->next;
		delete deleted;
	}
}

void QueueL::Push(const T value)
{	
	if (IsEmpty()) {
		head_.val = value;
		tail_ = new Node{ value, head_ };
	}
	tail_ = new Node{ value, tail_ };
}

bool QueueL::IsEmpty() const noexcept
{
	return (head_ == nullptr && tail_== nullptr);
}

T& QueueL::Top()
{
	if (IsEmpty()) {
		throw(std::exception("Top - queue is Empty"));
	}
	return head_->val;
}

const T& QueueL::Top() const
{
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

