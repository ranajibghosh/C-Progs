#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  map<string, vector<int>, std::less<>> dic;
  
  dic["Chotu"].push_back(90909009);
  dic["Amit"].push_back(982349819);
  
  dic["Amit"].push_back(9819);
  dic["Amit"].push_back(19);
  
   
       for(const auto &e2:dic){
           cout<<e2.first<<endl;
           for(auto &e1:e2.second){
            cout<<e1<<" ";   
           }
        cout<<endl;
       }
  
   return 0;
    
}