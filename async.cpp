#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;



ull findOdd(ull start, ull end){
    ull oddSum =0;
    for(ull i=start; i<=end; ++i){
        if((i%2)==1){
            oddSum +=i;
        }
    }
    return oddSum
}

int main(){
    
    ull start =0, end= 1900000000;
    
    cout<<"thread created if the policy is std::launch::async !! "<<endl;
    
    std::future<ull> oddSum = std::async(std::launch::deferred, findOdd, start, end);
    
    
    cout<<"Waiting for Result !!"<<endl;
    cout<<"oddSum : "<<oddSum.get()<<endl;
    cout<<"Completed !! "<<endl;
    return 0;
    
    
}