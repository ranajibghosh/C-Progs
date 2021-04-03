#include <iostream>
#include <conio>
//using namespace std;
template <class T>
class MyInt{
    T *data;
    public:
    static int counter;
    explicit MyInt(T *p=NULL){
        counter++;
        cout<<"In CONST : counter : "<<counter<<endl;
        data=p;
    }
    T &operator * (){
        cout<<"Operator * fun"<<endl;
        return *data;
    }
    T* operator->() {
    	 cout<<"Operator -> fun"<<endl;
    	 return data;
    }
    ~MyInt(){
        cout<<"In DESTR"<<endl;
        if(counter==1){
        		cout<<"Deleted"<<endl;
        		delete data;
            }
        else{
        		counter--;
            cout<<"counter : "<<counter<<endl;
        }
    }
};
template <class T>
int MyInt<T>::counter =0;
class area{
	double length, width;
   public:
   area(double a=0, double b=0):length(a), width(b){}
   void showData(){
   	cout<<"Length="<<length<<endl;
      cout<<"Width="<<width<<endl;
   }
   void result(){cout<<"Area="<<length*width<<endl;}
};
int main() {
	area *q = new area(5.8,6);
   MyInt<area> myint(q);
   if(1){
    area *p = new area(5,6);
    MyInt<area> myint(p);
    myint->showData();
    //myint->result();
    (*myint).result();
    }
    getch();
    return 0;
}