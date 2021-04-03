#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main() {
   
 
   array<int, 5> myarray ={1,2,3,4,5};
   vector<int> arr1;
   vector<int> arr2(5,20);
   vector<int> arr3={1,2,3,4,5};
   vector<int> arr4 {1,2,3,4,5};
   
   arr2[3]=10; // if trying to accesss out of the boundary element it gives garbage value
   arr2.at(3) = 10; // exception safe, it throughs an error is we try to access out of boundary element.
   
   
   
   
   vector <int> vec;
   //vec.reserve(1000);// capacity fixed
   vec.reserve(27);
   for(int i=0; i<33; ++i){
       
       vec.push_back(i);
       cout<<"SIZE : "<<vec.size()<<" CAPACITY : "<<vec.capacity()<<" VALUE AT "<<i<<" is = "<<i<<endl;
   }
   
   
   return 0;
}