#include "queue.h"

using namespace std;

int main(int argc, char *argv[])
{
    int choice, m, e;
    QUEUE *p;
    const QUEUE *s = new QUEUE(10);
    do
    {
        do
        {
            system("clear");
            cout << "\n\n----------------Menu for Queue Table On Sequence Structure----------------" << endl;
            cout << "\t1.InitQueue(int)               2.InitQueue(QUEUE const&)" << endl;
            cout << "\t3.int()" << endl;
            cout << "\t4.<<                           5.>>" << endl;
            cout << "\t6.=                            7.print(const QUEUE *const)" << endl;
            cout << "\t8.Destroy" << endl;
            cout << "\t0.Exit" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "Please input your choice[0-9]: " << endl;
            cin >> choice;
        } while (choice < 0 || choice > 9);
        switch (choice)
        {
        case 1:
            cout << "Please input maximum number of elements in the queue:" << endl;
            cin >> m;
            p = new QUEUE(m);
            cout << "Init successful!" << endl;
            break;
        case 2:
            p = new QUEUE(*s);
            cout << "Init successful!" << endl;
            break;
        case 3:
            cout << "The actual number of elements of the stack is " << int(*p) << endl;
            break;
        case 4:
            cout << "Please push the stack elemente：" << endl;
            cin >> e;
            *p << e;
            break;
        case 5:
            *p >> e;
            break;
        case 6:
            *p = *s;
            cout << "Queue assignment success!" << endl;
            break;
        case 7:
            p->print();
            break;
        case 8:
            delete p;
            cout << "Destory the stack successfully!" << endl;
            break;
        case 0:
            break;
        }
        cin.get();
        cin.get();
    } while (choice != 0);

    return 0;
}
