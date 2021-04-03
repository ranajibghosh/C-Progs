#include <iostream>
#include <memory>
using namespace std;

class foo{
    int x;
    public:
    explicit foo(int x):x(x){}
    int getx(){return x;}
    ~foo(){cout<<"Foo Destr :"<<this->x<<endl;}
};

int main(){
    //foo *f = new foo(80);
   // cout<<f->getx()<<endl;
   unique_ptr<foo> p7(new foo(80));
   
   std::unique_ptr<foo> p(new foo(10));
  
   unique_ptr<foo> p2=make_unique<foo>(20);
   
   unique_ptr<foo> p9=make_unique<foo>(9);
   // cout << typeid(p9).name() << endl;
   //p7=p2;// fail, as we can't copy
   std::unique_ptr<foo> p8(new foo(8)); // not allowed
   
    cout<<"P : "<<p->getx()<<" ADDRESS="<<&p<<", SIZE="<<sizeof(p)<<endl;
    p7 = std::move(p9);
    unique_ptr<foo> p3 = std::move(p); // moving ownership allowed
   p = std::move(p8);
   
   cout<<"P : "<<(*p).getx()<<endl;
   cout<<"P2 : "<<(*p2).getx()<<endl;
   cout<<"P3 : "<<(*p3).getx()<<endl;
   cout<<"P7 : "<<(*p7).getx()<<endl;
   
   foo * p0= p3.get();
   
  // cout<<"P3 : "<<(*p3).getx()<<endl;
   cout<<"P0 : "<<p0->getx()<<endl;
   
   foo *p4 = p3.release();
   p2.reset(p4);
   
   //cout<<"P3 : "<<(*p3).getx()<<endl;
    cout<<"P2 : "<<(*p2).getx()<<endl;
   cout<<"P4 : "<<p4->getx()<<endl;
   
    
    return 0;
}