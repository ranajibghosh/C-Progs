#include <iostream>
using namespace std;

class MyInt{
    int *data;
    public:
    explicit MyInt(int *p=nullptr){
        cout<<"In CONST"<<endl;
        data=p;
    }
    int &operator * (){
        cout<<"operator fun"<<endl;
        return *data;
    }
    ~MyInt(){
        cout<<"In DESTR"<<endl;
        delete data;
    }
};

int main() {
    int *p = new int(10);
    MyInt myint=MyInt(p);
    cout<<*myint<<endl;
    return 0;
  
}