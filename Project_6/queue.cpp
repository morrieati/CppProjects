#include "queue.h"

using namespace std;

QUEUE::QUEUE(int m) : STACK(m), s2(m) {}
QUEUE::QUEUE(const QUEUE &q) : STACK(q), s2(q.s2) {}

QUEUE::operator int() const
{
    return STACK::operator int();
}

QUEUE &QUEUE::operator<<(int e)
{
    // TODO: 在此处插入 return 语句
    if (pos == max)
    {
        cout << "队列满咧" << endl;
        return *this;
    }
    STACK::operator<<(e);
    cout << "Enqueue successful!" << endl;

    return *this;
}

QUEUE &QUEUE::operator>>(int &e)
{
    // TODO: 在此处插入 return 语句
    int temp = 0;
    int temPos = pos - 1;
    for (int i = 0; i < temPos; i++)
    {
        STACK::operator>>(temp);
        s2 << temp;
    }
    STACK::operator>>(e);
    for (int i = 0; i < temPos; i++)
    {
        s2 >> temp;
        STACK::operator<<(temp);
    }
    cout << "Dequeue success! the element is " << e << endl;

    return *this;
}

QUEUE &QUEUE::operator=(const QUEUE &q)
{
    STACK::operator=(q);
    s2 = *(new STACK(q.s2));

    return *this;
}

void QUEUE::print() const
{
    STACK::print();
}

QUEUE::~QUEUE()
{
    delete &s2;
}
