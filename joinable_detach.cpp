#include <iostream>
#include <thread>
#include <chrono>
using namespace std;



void fun(int x){
         while(x -- > 0)
             cout<<x<<endl;
         std::this_thread::sleep_for(chrono::seconds(3));
    }
    
int main(){
 
 thread t(fun,10);
 cout<<"MAIN()"<<endl;
 t.join();
 //t.join(); // terminate the prog
 if(t.joinable())// now prog 
   t.join();     // will not terminate 
 cout<<"MAIN() after"<<endl;
 return 0;
 
} 