#include <iostream>
using namespace std;
class Base{
    public:
    Base(){cout<<"Base Constructor:"<<(this)<<endl;}
    
    virtual void fun(){cout<<"Base Fun"<<endl;}
     virtual void fun1()=0;
     
    virtual ~Base(){cout<<"Base Destructor:"<<(this)<<endl;}
   
};
class Derive: public Base{
    public:
    Derive(){cout<<"Derive Constructor:"<<(this)<<endl;}
    
    void fun(){cout<<"Derive Fun"<<endl;}
    void fun1(){cout<<"Derive Fun1"<<endl;};
    
    ~Derive(){cout<<"Derive Destructor:"<<(this)<<endl;}
};
int main(){
   // Base obj;
    //cout<<"Sizeof Base :"<<sizeof(obj)<<endl;
    Base *b = new Derive();
    b->fun();
    b->fun1();
    delete b;
    return 0;
}