#include <stackl/stackl.h>
using T = uint8_t;
StackL::~StackL()
{
}

StackL& StackL::operator=(const StackL& src)
{
	// TODO: �������� ����� �������� return
}

StackL& StackL::operator=(StackL&& src) noexcept
{
	// TODO: �������� ����� �������� return
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
	// TODO: �������� ����� �������� return
}

const T& StackL::Top() const&
{
	// TODO: �������� ����� �������� return
}

void StackL::Clear() noexcept
{
}
