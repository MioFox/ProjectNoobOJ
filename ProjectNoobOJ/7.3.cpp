#include<iostream>
#include <string.h>
using namespace std;
class Mammal
{
protected:
    char name[10];
public:
    virtual void set()
    {
        strcpy(name, "哈哈");
    }
    virtual void speak()
    {
        cout << "这是哺乳动物" << endl;
    }
};

class Dog :public Mammal
{
public:
    void set()
    {
        strcpy(name, "哈哈");
    }
    void speak()
    {
        cout << "这是哺乳动物：狗" << endl;
    }
};

void fun(Mammal& s)
{
    s.speak();
}

void main()
{
    Mammal m1;
    Dog d2;
    fun(m1);
    fun(d2);
}