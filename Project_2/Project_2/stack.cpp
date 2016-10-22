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
	// TODO: 在此处插入 return 语句
	if (pos)
	{

	}
}

STACK & STACK::pop(int & e)
{
	// TODO: 在此处插入 return 语句
}

STACK & STACK::assign(const STACK & s)
{
	// TODO: 在此处插入 return 语句
}

void STACK::print() const
{
}

STACK::~STACK()
{
}
