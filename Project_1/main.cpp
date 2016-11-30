//
//  main.cpp
//  Project_1
//
//  Created by 刘义盟 on 19/10/2016.
//  Copyright © 2016 刘义盟. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"

typedef struct _stack
{
    int *elems; //申请内存用于存放栈的元素
    int max;    //栈能存放的最大元素个数
    int pos;    //栈实际已有元素个数，栈空时pos=0;
} STACK;

void initSTACK(STACK *const p, int m);               //初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, const STACK &s);      //用栈s初始化p指向的栈
int size(const STACK *const p);                      //返回p指向的栈的最大元素个数max
int howMany(const STACK *const p);                   //返回p指向的栈的实际元素个数pos
STACK *const push(STACK *const p, int e);            //将e入栈，并返回p
STACK *const pop(STACK *const p, int &e);            //出栈到e，并返回p
STACK *const assign(STACK *const p, const STACK &s); //赋s给p指的栈,并返回p
void print(const STACK *const p);                    //打印p指向的栈
void destroySTACK(STACK *const p);                   //销毁p指向的栈

int main(int argc, char const *argv[])
{
    int choice, m, e;
    STACK s, p;
    initSTACK(&s, 20);
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
            printf("Please input maximum number of elements in the stack:");
            scanf("%d", &m);
            initSTACK(&p, m);
            printf("Init successful！\n");
            break;
        case 2:
            initSTACK(&p, s);
            printf("Init successful！\n");
            break;
        case 3:
            printf("The maximum number of elements in the stack is %d！\n", size(&p));
            break;
        case 4:
            printf("The actual number of elements of the stack is %d！\n", howMany(&p));
            break;
        case 5:
            printf("Please push the stack elemente：");
            scanf("%d", &e);
            if (push(&p, e))
            {
                printf("Push successful！\n");
            }
            else
            {
                printf("The stack is full, push fail！\n");
            }
            break;
        case 6:
            if (pop(&p, e))
            {
                printf("Pop success! the element is %d\n", e);
            }
            else
            {
                printf("The stack is empty,pop fail！\n");
            }
            break;
        case 7:
            assign(&p, s);
            printf("Stack assignment success！\n");
            break;
        case 8:
            print(&p);
            break;
        case 9:
            destroySTACK(&p);
            printf("Destory the stack successfully！\n");
            break;
        case 0:
            break;
        }
        system("pause");
    } while (choice != 0);

    return 0;
}

void initSTACK(STACK *const p, int m)
{
    p->elems = (int *)malloc(m * sizeof(int));
    p->max = m;
    p->pos = 0;
}

void initSTACK(STACK *const p, const STACK &s)
{
    p->elems = (int *)malloc(s.max * sizeof(int));
    p->max = s.max;
    p->pos = s.pos;
    for (int i = 0; i < p->max; i++)
    {
        p->elems[i] = s.elems[i];
    }
}

int size(const STACK *const p)
{
    return p->max;
}

int howMany(const STACK *const p)
{
    return p->pos;
}

STACK *const push(STACK *const p, int e)
{
    if (p->pos == p->max)
    {
        return nullptr;
    }
    p->elems[p->pos] = e;
    p->pos++;

    return p;
}
STACK *const pop(STACK *const p, int &e)
{
    p->pos--;
    if (p->pos < 0)
    {
        p->pos = 0;
    }
    else
    {
        e = p->elems[p->pos];
    }
    return p;
}
STACK *const assign(STACK *const p, const STACK &s)
{
    p->elems = (int *)realloc(p->elems, s.max * sizeof(int));
    p->max = s.max;
    p->pos = s.pos;
    for (int i = 0; i < p->max; i++)
    {
        p->elems[i] = s.elems[i];
    }
    return p;
}
void print(const STACK *const p)
{
    for (int i = 0; i < p->pos; i++)
    {
        printf("%d ", p->elems[i]);
    }
}
void destroySTACK(STACK *const p)
{
    free(p->elems);
    p->max = 0;
    p->pos = 0;
}
