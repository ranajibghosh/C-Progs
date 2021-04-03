#include <iostream>
#include <memory>
#include <thread>
using namespace std;

class foo{
    int x;
    public:
    explicit foo(int x):x(x){}
    int getx(){return x;}
    ~foo(){cout<<"~Foo Destr :"<<this->x<<endl;}
};


void fun(std::shared_ptr<foo> sp){
    cout<<"Fun : "<<sp.use_count()<<endl;
}


int main(){



 
    //foo *f = new foo(1);
    //cout<<f->getx()<<endl;
    //delete f;
    {
    foo *f = new foo(100);
    std::shared_ptr<foo> sp(f);
    std::shared_ptr<foo> sp_other(new foo(99));
    cout<<sp->getx()<<endl;
    cout<<"1. Ref. counter sp :"<<sp.use_count()<<endl;
    
    std::shared_ptr<foo> sp1 = sp;
    std::move(sp1); // No effect.
    {
    std::shared_ptr<foo> sp3;
    cout<<"2. Ref. counter sp:"<<sp.use_count()<<endl;
    cout<<"3. Ref. counter sp1:"<<sp1.use_count()<<endl;
    cout<<"4. Ref. counter sp3:"<<sp3.use_count()<<endl;// no ref. yet
    sp3 = sp;
    //sp_other = sp;
    sp = sp_other;
    cout<<"5. Ref. counter sp3:"<<sp3.use_count()<<endl;
    cout<<"5A. Ref. counter sp_other:"<<sp_other.use_count()<<endl;
    std::shared_ptr<foo> &sp7  = sp;// no effect, has to be copy by value
    cout<<"5AA. Ref. counter sp7:"<<sp7.use_count()<<endl;
    //std::shared_ptr<foo> *sp9  = &sp;// no effect, has to be copy by value
    //delete f;
    }
    cout<<"6. Ref. counter sp:"<<sp.use_count()<<endl;
    cout<<"7. Ref. counter sp1:"<<sp1.use_count()<<endl;
    //cout<<"Ref. counter sp3:"<<sp3.use_count()<<endl;
    }


 cout<<"OUT OF SCOPE:"<<endl;

 std::shared_ptr<foo> sp_1(new foo(200));
  cout<<"_1. Ref. counter :"<<sp_1.use_count()<<endl;
  std::shared_ptr<foo> sp_2 = sp_1;
    cout<<"_1. Ref. counter :"<<sp_1.use_count()<<endl;
    std::shared_ptr<foo> sp_3 = std::move(sp_1);
    cout<<"_1. Ref. counter after move  :"<<sp_1.use_count()<<endl;
    cout<<"_2. Ref. counter :"<<sp_2.use_count()<<endl;
    cout<<"_3. Ref. counter :"<<sp_3.use_count()<<endl;




/*
   
    // using thread
    std::shared_ptr<foo> sp(new foo(100));
    thread t1(fun, sp),t2(fun, sp),t3(fun,sp);
    cout<<"Main : "<<sp.use_count()<<endl;
    t1.join();t2.join();t3.join();
  */  
     return 0;
}