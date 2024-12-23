/*#include <queuel/queuel.hpp>
#include<algorithm>





QueueL& QueueL::operator=(const QueueL& scr) //не доделал 
{
	if (this != &scr) {
		if (scr.IsEmpty()) {
			Clear();
		}
		else {
			Node* p_src = scr.head_;
			if (IsEmpty()) {
				head_ = new Node{ scr.head_->val };
				tail_ = head_;
			}
			else {
				head_->val = scr.head_->val;
				tail_ = head_;
			}
			Node* p_dst = head_;

		}
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
}*/

