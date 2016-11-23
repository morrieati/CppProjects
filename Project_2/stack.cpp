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
	if (pos == max)
	{
		return nullptr;
	}
	elems[pos] = e;
	pos++;

	return *this;
}

STACK & STACK::pop(int & e)
{
	// TODO: 在此处插入 return 语句
	pos--;
	if (pos < 0) {
		pos = 0;
	} else {
		e = elems[pos];
	}

	return *this;
}

STACK & STACK::assign(const STACK & s)
{
	// TODO: 在此处插入 return 语句
	delete(elems);
	elems = new int[s.max];
	max = s.max;
	pos = s.pos;
	for (int i = 0; i < max; i++) {
		elems[i] = s.elems[i];
	}

	return *this;
}

void STACK::print() const
{
	for (size_t i = 0; i < pos; i++) {
		std::cout << elems[i] << std::endl;
	}
}

STACK::~STACK()
{
	delete(elems);
	max = 0;
	pos = 0;
}
