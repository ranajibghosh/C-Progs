#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
using namespace std;

class foo{
    int x;
    public:
    explicit foo(int x):x(x){}
    int getx(){return x;}
    ~foo(){cout<<"~Foo Destr :"<<this->x<<endl;}
};


void fun(std::shared_ptr<foo> sp){
    cout<<"Fun : "<<this_thread::get_id()<< ": "<<sp.use_count()<<endl;
    //this_thread::sleep_for(std::chrono::milliseconds(5000));
}


int main(){


   
    // using thread
    std::shared_ptr<foo> sp(new foo(100));
    thread t1(fun, sp),t2(fun, sp),t3(fun,sp);
    cout<<"Main : "<<sp.use_count()<<endl;
    t1.join();t2.join();t3.join();
 
     return 0;
}