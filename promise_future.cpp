#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;



void findOdd(std::promise<ull>&& oddSumPromise, ull start, ull end){
    ull oddSum =0;
    for(ull i=start; i<=end; ++i){
        if(i%2==1)
            oddSum +=i;
    }
    oddSumPromise.set_value(oddSum);
}


int main() {
    ull start =0, end= 1900000000;
    
    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();
    
    cout<<"Thread created !! "<<endl;
    std::thread t1(findOdd, std::move(oddSum), start, end);
    
    cout<<"Waiting for result "<<endl;
    
    cout<<"oddSum : "<<oddFuture.get()<<endl;
    
    cout<<"Completed"<<endl;
    
    t1.join();
    return 0;
}
