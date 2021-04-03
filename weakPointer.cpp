#include <iostream>
#include <memory>
using namespace std;


int main(){
   
    auto sptr = std::make_shared<int>(100);
    std::weak_ptr<int> wptr(sptr);
    
    cout<<"Weak pointer use_count() : "<<wptr.use_count()<<endl;
    cout<<"shared pointer use_count() : "<<sptr.use_count()<<endl;
    cout<<"Weak pointer expired ?: "<<wptr.expired()<<endl;
    
    if(std::shared_ptr<int> sptr1 = wptr.lock()){
       cout<<"shares ptr: "<<*sptr<<endl; 
       cout<<"shared pointer 1 use_count() : "<<sptr1.use_count()<<endl;
    }else{
        
        cout<<"Dont get the resource : "<<endl;
    }
    
    wptr.reset();
    
    if(std::shared_ptr<int> sptr1 = wptr.lock()){
       cout<<"shares ptr: "<<*sptr<<endl; 
       cout<<"shared pointer 1 use_count() : "<<sptr1.use_count()<<endl;
    }else{
        
        cout<<"Dont get the resource ! "<<endl;
    }
    
    
     return 0;
}