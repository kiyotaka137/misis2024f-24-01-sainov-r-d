#include <stackl/stackl.h>
using T = uint8_t;
StackL::~StackL()
{
}

StackL& StackL::operator=(const StackL& src)
{
	// TODO: вставьте здесь оператор return
}

StackL& StackL::operator=(StackL&& src) noexcept
{
	// TODO: вставьте здесь оператор return
}

bool StackL::IsEmpty() const noexcept
{
	return false;
}

void StackL::Pop() noexcept
{
}

void StackL::Push(const T val)
{
}

T& StackL::Top()&
{
	// TODO: вставьте здесь оператор return
}

const T& StackL::Top() const&
{
	// TODO: вставьте здесь оператор return
}

void StackL::Clear() noexcept
{
}
