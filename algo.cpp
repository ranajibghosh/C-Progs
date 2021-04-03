#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
using namespace std;

int main() {
   
   vector<int> vec{7,3,5,2,6,4};
 // find  
  vector<int>::iterator it = find(vec.begin(),vec.end(), 4);
  
  if(it==vec.end())
     cout<<"NOT FOUND"<<endl;
    else
    cout<<"found"<<endl;
    
  // sort  
  cout<<"SORTING"<<endl;
    vector<int> vec1{5,4,6,7,3,2,8,9,1};
    std::sort(std::execution::par, vec1.begin(),vec1.end());
    
    for(auto ele:vec1){
        cout<<ele<<" ";
    }
    
   
   return 0;
    
}