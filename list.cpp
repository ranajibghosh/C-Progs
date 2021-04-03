#include <iostream>
#include <list>

using namespace std;

int main(){
  list<int> list1={5,2,4,6,2};
  list<int> list2={7,6,1,9};
  
  for(auto &ele : list1)
    cout<<ele<<" ";
  cout<<endl;
  
  list2.sort();
  for(auto &ele : list2)
    cout<<ele<<" ";
  cout<<endl;
  
  list1.merge(list2);
  for(auto &ele : list1)
    cout<<ele<<" ";
  cout<<endl;
  
   return 0;
    
}