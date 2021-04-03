#include <iostream>
#include <vector>

using namespace std;

int main(){
   vector<vector<int>> tree;
   int edge,n1,n2;
   
   cout<<"Enter No. edges : "<<endl;
   cin>>edge;
   tree.resize(edge);
   
   for(int i=0; i<edge; ++i){
       cout<<"Enter Source Node :";
       cin>>n1;
       cout<<"Enter Destination Node :";
       cin>>n2;
       tree[n1].push_back(n2);
   }
   
   for(const auto &e1:tree){
       for(const auto &e2:e1){
           cout<<e2;
       }
       cout<<endl;
   }
   return 0;
    
}