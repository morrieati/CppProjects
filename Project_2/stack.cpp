#include "stack.h"

using namespace std;

STACK::STACK(int m) : elems(new int[m]), max(m), pos(0) {}

STACK::STACK(const STACK &s) : elems(new int[s.max]), max(s.max), pos(s.pos)
{
    for (int i = 0; i < pos; i++)
    {
        elems[i] = s.elems[i];
    }
}

int STACK::size() const
{
    return max;
}

int STACK::howMany() const
{
    return pos;
}

STACK &STACK::push(int e)
{
    // TODO: 在此处插入 return 语句
    if (pos == max)
    {
        cout << "栈满咧" << endl;
        return *this;
    }
    elems[pos] = e;
    pos++;
    cout << "Push successful!" << endl;

    return *this;
}

STACK &STACK::pop(int &e)
{
    // TODO: 在此处插入 return 语句
    pos--;
    if (pos < 0)
    {
        pos = 0;
        cout << "The stack is empty, pop fail!" << endl;
    }
    else
    {
        e = elems[pos];
        cout << "Pop success! the element is " << e << endl;
    }

    return *this;
}

STACK &STACK::assign(const STACK &s)
{
    // TODO: 在此处插入 return 语句
    delete[] elems;

    *(int **)&elems = new int[s.max];
    *(int *)&max = s.max;
    pos = s.pos;

    for (int i = 0; i < s.pos; i++)
    {
        elems[i] = s.elems[i];
    }

    return *this;
}

void STACK::print() const
{
    for (int i = 0; i < pos; i++)
    {
        cout << elems[i] << endl;
    }
}

STACK::~STACK()
{
    delete[] elems;
    pos = 0;
}
