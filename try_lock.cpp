#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

std::mutex mtx;

 int counter =0;
 void increaseTheCounterFor100Time(){
     
    for(int i=0; i<200; ++i){
       if(mtx.try_lock()) {
           ++counter;
           cout<<counter<<":"<<this_thread::get_id()<<endl;
           mtx.unlock();
       }
        
    }
 }
    
int main(){
 
 thread t1(increaseTheCounterFor100Time);
 thread t2(increaseTheCounterFor100Time);
 
 t1.join();
 t2.join();
 
 cout<<"Counter could increase upto :"<<counter<<endl;

 return 0;
 
} 