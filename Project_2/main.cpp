#include "stack.h"

using namespace std;

int main(int argc, char *argv[])
{
    int choice, m, e;
    STACK *p;
    const STACK *s = new STACK(10);
    do
    {
        do
        {
            system("clear");
            cout << "\n\n----------------Menu for Stack Table On Sequence Structure----------------" << endl;
            cout << "  1.InitStack(STACK *const,int)  2.InitStack(STACK *const,STACK const&)" << endl;
            cout << "  3.size(const STACK *const p)   4.howMany(const STACK *const)" << endl;
            cout << "  5.push(STACK *const, int)      6.pop(STACK *const, int&)" << endl;
            cout << "  7.assign(STACK*const,const STACK&)" << endl;
            cout << "  8.print(const STACK *const)    9.destroySTACK(STACK *const)" << endl;
            cout << "  0.Exix" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "Please input your choice[0-9]: " << endl;
            cin >> choice;
        } while (choice < 0 || choice > 9);
        switch (choice)
        {
        case 1:
            cout << "Please input maximum number of elements in the stack:" << endl;
            cin >> m;
            p = new STACK(m);
            cout << "Init successful!" << endl;
            break;
        case 2:
            p = new STACK(*s);
            cout << "Init successful!" << endl;
            break;
        case 3:
            cout << "The maximum number of elements in the stack is " << p->size() << endl;
            break;
        case 4:
            cout << "The actual number of elements of the stack is " << p->howMany() << endl;
            break;
        case 5:
            cout << "Please push the stack elemente：" << endl;
            cin >> e;
            p->push(e);
            break;
        case 6:
            p->pop(e);
            break;
        case 7:
            p->assign(*s);
            cout << "Stack assignment success!" << endl;
            break;
        case 8:
            p->print();
            break;
        case 9:
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
