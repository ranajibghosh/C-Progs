#include <memory>
#include <iostream>
using namespace std;

class ABC{
    public:
    virtual void show()=0;
};
class A:public ABC{
    public:
    void show(){cout<<"CLASS A"<<endl;}
};
class B:public ABC{
    public:
    void show(){cout<<"CLASS B"<<endl;}
};
class C:public ABC{
    public:
    void show(){cout<<"CLASS C"<<endl;}
}; 
class Factory{
    public:
    static ABC *ptr_abc;
    static ABC * createObject(char className){
        switch(className){
            case 'A': ptr_abc =new A();
            break;
            case 'B': ptr_abc =new B();
            break;
            case 'C': ptr_abc =new C();
            break;
        }
        return ptr_abc;
    }
};
ABC *Factory::ptr_abc=nullptr;

int main(){
    ABC *ptr_a = Factory::createObject('A');
    ptr_a->show();
    ABC *ptr_b = Factory::createObject('B');
    ptr_b->show();
    ABC *ptr_c = Factory::createObject('C');
    ptr_c->show();
    return 0;
}