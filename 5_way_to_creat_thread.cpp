#include <iostream>
#include <thread>
using namespace std;


// 1. non static member function

/*
class Base{
     public:
     void fun(int x){
         while(x-- > 0){
             cout<<x<<endl;
         }
     }
};

int main(){
     Base b;
     std::thread t(&Base::fun,&b,10);
     t.join();
    return 0;
}

*/


// 2. static member function


/*
class Base{
     public:
     static void fun(int x){
         while(x-- > 0){
             cout<<x<<endl;
         }
     }
};

int main(){
    
     std::thread t(&Base::fun,10);
     t.join();
    return 0;
}
*/

// 3. lambda 


/* int main(){
 auto fun=[](int x){
     while(x-- > 0){
             cout<<x<<endl;
         }
 };
 thread t(fun,10);
 t.join();
 return 0;
}
*/

// 4. function pointer

/* void fun(int x){
         while(x > 0){
             x--;
             cout<<x<<endl;
         }
    }
    
int main(){
 
 thread t(fun,10);
 t.join();
 return 0;
 
} */

// 5. Functors

class Base{
     public:
      void operator ()(int x){
         while(x-- > 0){
             cout<<x<<endl;
         }
     }
};
int main(){
 
 thread t(Base(),10);
 t.join();
 return 0;
 
} 

