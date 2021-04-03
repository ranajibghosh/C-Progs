// multi  thread
// find the addition of all odd from 1 to 19000000000 and even also
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
ull oddSum =0;
ull evenSum =0;
void findOdd(ull start, ull end){
    for(ull i=start; i<=end; ++i){
        if((i%2)==0){
            evenSum +=i;
        }
    }
    
}

void findEven(ull start, ull end){
    for(ull i=start; i<=end; ++i){
        if((i%2)==1){
            oddSum +=i;
        }
    }
    
}

int main(){
    
    ull start =0, end= 1900000000;
    
    auto startTime = high_resolution_clock::now();
    
    std::thread t1(findOdd, start, end);
    std::thread t2(evenSum, start, end);
    
    t1.join();
    t2.join();
    
    
    //findOdd(start,end);
   // findEven(start,end);
    
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    
    cout<<"ODDSUM = "<<oddSum<<endl;
    cout<<"EVENSUM = "<<evenSum<<endl;
    
    cout<<"SEC : "<<duration.count()/1000000<<endl;
    return 0;
    
    
}