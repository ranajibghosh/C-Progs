#include <iostream>
#include <memory>
using namespace std;
class Child1;
class Child2;
class Parent{

    public:
    //Parent(shared_ptr<Child1> c1,shared_ptr<Child2> c2):ch1{c1},ch2{c2}{}
    //shared_ptr<Child1> ch1;
    weak_ptr<Child1> ch1;
    weak_ptr<Child2> ch2;
    //void setChild1(weak_ptr<Child1> ch){ch1 = ch.lock();}
    void setChild1(shared_ptr<Child1> ch){ch1 = ch;}
    void setChild2(shared_ptr<Child2> ch){ch2 = ch;}
    
    ~Parent(){cout<<"Parent gone"<<endl;}
};
class Child1{
    public:
    shared_ptr<Parent> p_ch;
    Child1(shared_ptr<Parent> p):p_ch{p}{}
    
    ~Child1(){cout<<"Child1 gone"<<endl;}
};
class Child2{
     public:
     shared_ptr<Parent> p_ch;
     Child2(shared_ptr<Parent> p):p_ch{p}{}

    ~Child2(){cout<<"Child2 gone"<<endl;}
};

int main(){
    cout<<"In Main"<<endl;
    {
        shared_ptr<Parent> parent = shared_ptr<Parent>(new Parent);
        shared_ptr<Child1> child1 = shared_ptr<Child1>(new Child1(parent));
        shared_ptr<Child2> child2 = shared_ptr<Child2>(new Child2(parent));

        parent->setChild1(child1);
        parent->setChild2(child2);
    }
    cout<<"End Main"<<endl;
    return 0;
}
