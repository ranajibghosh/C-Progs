#include <iostream>
#include <conio>
//using namespace std;
template <class T>
class MyInt{
    T *data;
    public:
    explicit MyInt(T *p=NULL){
        cout<<"In CONST"<<endl;
        data=p;
    }
    T &operator * (){
        cout<<"operator * fun"<<endl;
        return *data;
    }
    ~MyInt(){
        cout<<"In DESTR"<<endl;
        delete data;
    }
};

int main() {
   if(1){
    int *p = new int(10);
    MyInt<int> myint(p);
    cout<<*myint<<endl;
    }
    getch();
    return 0;
  
}