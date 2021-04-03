#include <iostream>
#include <map>

using namespace std;

int main(){
  map<string, int> dic;
  
  dic["Chotu"] = 90909009;
  dic["Amit"] = 982349819;
  
  dic.insert(make_pair("Bot",782348818));
   
       for(const auto &e2:dic){
           cout<<e2.first<<" "<<e2.second<<endl;
       }
     dic["Chotu"]=0; 
   cout<<dic["Chotu"]<<endl;
   
   return 0;
    
}