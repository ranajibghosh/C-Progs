#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

std::mutex m;

 int myAmount =0;
 void addMoney(){
     
     m.lock();
     ++myAmount;  // race condition
     m.unlock();
     
 }
    
int main(){
 
 thread t1(addMoney);
 thread t2(addMoney);
 
 t1.join();
 t2.join();
 
 cout<<"MY AMOUNT ="<<myAmount<<endl;

 return 0;
 
} 