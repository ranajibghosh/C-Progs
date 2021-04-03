#include <iostream>
using namespace std;

int binarySearch(int *a, int low, int high, int key){
    
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==key){
            return mid;
        }else if(a[mid]>key){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

    return -1;
}
//recursive function
int binarySearchRec(int *a, int low, int high, int key){
    
   if(low>high)
        return -1;
        
    int mid = (low+high)/2;
        if(a[mid]==key){
            return mid;
        }else if(a[mid]<key){
                binarySearchRec(a, mid+1, high, key);
            }else{
               binarySearchRec(a, low, mid-1, key);
            }
 }

int main(){
   int val, arr[]={1,4,6,9,21,76,78};
   cout<<"Enter the value to find : "<<endl;
   cin>>val;
   
   auto x =binarySearchRec(arr, 0, 7, val);
   
     if(x!=-1)
        cout<<"Found at : "<<x<<" position"<<endl;
     else
        cout<<"Not Found !! "<<endl;
    return 0;
}