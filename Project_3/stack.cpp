#include "stack.h"

using namespace std;

STACK::STACK(int m) : max(m), elem(new int[m])
{
    this->pos = 0;
}
STACK::STACK(const STACK &S) : max(S.max), elem(new int[S.max])
{
    pos = S.pos;
    for (int i = 0; i < pos; i++)
    {
        elem[i] = S.elem[i];
    }
    cout << "STACK(const STACK &S)" << endl;
}
int STACK::size() const
{
    return this->max;
}

STACK::operator int() const
{
    return pos;
}

STACK &STACK::operator<<(int e)
{
    if (this->pos == this->max)
    {
        cout << "Õ»ÒÔÂú" << endl;
        return *this;
    }
    this->elem[this->pos] = e;
    this->pos++;
    return *this;
}

STACK &STACK::operator>>(int &e)
{
    if (pos == 0)
    {
        cout << "Õ»Îª¿Õ" << endl;
        return *this;
    }
    pos--;
    e = elem[pos];
    return *this;
}

STACK &STACK::operator=(const STACK &s)
{
}

void STACK::print() const
{
    int i;
    cout << "\n-----------all elements -----------------------\n"
         << endl;
    for (i = 0; i < (pos); i++)
        cout << elem[i] << " ";
    cout << "\n------------------ end ------------------------\n"
         << endl;
}

STACK::~STACK()
{
    if (elem)
    {
        delete[] elem;
        (int *)elem = 0;
    }
}
