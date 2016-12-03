#include "queue.h"

using namespace std;

QUEUE::QUEUE(int m) : elems(new int[m]), max(m), pos(0) {}
QUEUE::QUEUE(const QUEUE &q) : elems(new int[q.max]), max(q.max), pos(q.pos)
{
    for (int i = 0; i < pos; i++)
    {
        elems[i] = q.elems[i];
    }
}

QUEUE::operator int() const
{
    return pos;
}

QUEUE &QUEUE::operator<<(int e)
{
    // TODO: 在此处插入 return 语句
    if (pos == max)
    {
        cout << "队列满咧" << endl;
        return *this;
    }
    elems[pos] = e;
    pos++;
    cout << "Enqueue successful!" << endl;

    return *this;
}

QUEUE &QUEUE::operator>>(int &e)
{
    // TODO: 在此处插入 return 语句
    pos--;
    if (pos < 0)
    {
        pos = 0;
        cout << "The queue is empty, pop fail!" << endl;
    }
    else
    {
        e = elems[0];
        for (int i = 0; i < pos; i++)
        {
            elems[i] = elems[i + 1];
        }
        cout << "Dequeue success! the element is " << e << endl;
    }

    return *this;
}

QUEUE &QUEUE::operator=(const QUEUE &q)
{
    delete[] elems;

    *(int **)&elems = new int[q.max];
    *(int *)&max = q.max;
    pos = q.pos;

    for (int i = 0; i < q.pos; i++)
    {
        elems[i] = q.elems[i];
    }

    return *this;
}

void QUEUE::print() const
{
    for (int i = 0; i < pos; i++)
    {
        cout << elems[i] << endl;
    }
}

QUEUE::~QUEUE()
{
    if (elems)
    {
        delete[] elems;
        pos = 0;
    }
}
