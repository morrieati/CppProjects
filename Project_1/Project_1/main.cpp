//
//  main.cpp
//  Project_1
//
//  Created by 刘义盟 on 19/10/2016.
//  Copyright © 2016 刘义盟. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"

typedef struct _stack{
    int *elems;	                                                                //申请内存用于存放栈的元素
    int max;                                                                    //栈能存放的最大元素个数
    int pos;                                                                    //栈实际已有元素个数，栈空时pos=0;
}STACK;

void initSTACK(STACK *const p, int m);	//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, const STACK &s); //用栈s初始化p指向的栈
int  size (const STACK *const p);		//返回p指向的栈的最大元素个数max
int  howMany (const STACK *const p);	//返回p指向的栈的实际元素个数pos
STACK *const push(STACK *const p, int e); 	//将e入栈，并返回p
STACK *const pop(STACK *const p, int &e); 	//出栈到e，并返回p
STACK *const assign(STACK *const p, const STACK &s); //赋s给p指的栈,并返回p
void print(const STACK *const p);			//打印p指向的栈
void destroySTACK(STACK *const p);		//销毁p指向的栈

int main(int argc, char const *argv[]) {
    printf("Hello World\n");
    return 0;
}

void initSTACK(STACK *const p, int main) {
    
}

void initSTACK(STACK *const p, const STACK &s) {
    
}

int size(const STACK *const p) {
    return 0;
}
