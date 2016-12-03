#include "queue.h"

using namespace std;

QUEUE::QUEUE(int m) : s1(m), s2(m) {}
QUEUE::QUEUE(const QUEUE &q) : s1(q.s1), s2(q.s2) {}

QUEUE::operator int() const
{
    return s1.pos;
}

QUEUE &QUEUE::operator<<(int e)
{
    // TODO: 在此处插入 return 语句
    if (s1.pos == s1.max)
    {
        cout << "队列满咧" << endl;
        return *this;
    }
    s1 << e;
    cout << "Enqueue successful!" << endl;

    return *this;
}

QUEUE &QUEUE::operator>>(int &e)
{
    // TODO: 在此处插入 return 语句
    s1.pos--;
    s2.pos--;
    if (s1.pos < 0)
    {
        s1.pos = 0;
        cout << "The queue is empty, pop fail!" << endl;
    }
    else
    {
        e = s1.elems[0];
        int temp = 0;
        for (int i = 0; i < pos; i++)
        {
            s1 >> temp;
            s2 << temp;
        }
        s1 >> temp;
        for (int i = 0; i < pos; i++)
        {
            s2 >> temp;
            s1 << temp;
        }
        cout << "Dequeue success! the element is " << e << endl;
    }

    return *this;
}

QUEUE &QUEUE::operator=(const QUEUE &q)
{
    delete s1;
    delete s2;

    s1 = new STACK(q.s1);
    s2 = new STACK(q.s2);

    return *this;
}

void QUEUE::print() const
{
    for (int i = 0; i < pos; i++)
    {
        cout << s1.elems[i] << endl;
    }
}

QUEUE::~QUEUE()
{
    if (s1 && s2)
    {
        delete s1;
        delete s2;
    }
}
