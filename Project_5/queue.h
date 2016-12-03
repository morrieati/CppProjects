#include "stack.h"

class QUEUE
{
  STACK s1, s2;

public:
  QUEUE(int m);                             //初始化队列：最多m个元素
  QUEUE(const QUEUE &s);                    //用队列s拷贝初始化队列
  virtual operator int() const;             //返回队列的实际元素个数pos
  virtual QUEUE &operator<<(int e);         //将e入队列,并返回队列
  virtual QUEUE &operator>>(int &e);        //出队列到e,并返回队列
  virtual QUEUE &operator=(const QUEUE &s); //赋s给队列,并返回被赋值的队列
  virtual void print() const;               //打印队列
  virtual ~QUEUE();                         //销毁队列
};