#include "stack.h"

STACK::STACK(int m) : elems(new int[m]), max(m), pos(0) {}

STACK::STACK(const STACK & s) : elems(new int[s.max]), max(s.max), pos(s.pos) {}

int STACK::size() const
{
	return max;
}

int STACK::howMany() const
{
	return pos;
}

STACK & STACK::push(int e)
{
	// TODO: �ڴ˴����� return ���
	if (pos)
	{

	}
}

STACK & STACK::pop(int & e)
{
	// TODO: �ڴ˴����� return ���
}

STACK & STACK::assign(const STACK & s)
{
	// TODO: �ڴ˴����� return ���
}

void STACK::print() const
{
}

STACK::~STACK()
{
}
