#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;
 
 mutex mu;

int counter =0;
 void print(){
    
    for(int i=1; i<=5; ++i){
         mu.lock();
        ++ counter;
        cout<<i<<":"<<this_thread::get_id()<<" : "<<counter<<endl;
       
        this_thread::sleep_for(std::chrono::seconds(1/2));
         mu.unlock();
    }
    
 }
    
int main(){
 
 thread t1(print);
 thread t2(print);
 //thread t3(print);
 
 t1.join();
 t2.join();
// t3.join();
 

 return 0;
 
} 