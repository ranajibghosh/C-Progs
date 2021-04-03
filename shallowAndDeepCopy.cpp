#include <iostream>
using namespace std;
class Base{
    
    int val;
    int *ptr;
    public:
    Base():val{0},ptr{new int(0)}{}
    Base(const Base& temp){
        //shallow copy , which is supplied by the compiler if we not define it explicitly
        //val = temp.val;
        //ptr = temp.ptr;
        // deep copy
        int *ptr1 = new int(0);
        val = temp.val;
        *ptr = *temp.ptr;
    }
    void setVal(int v){val=v;}
    void setPtr(int p){*ptr=p;}
    int getVal(){return val;}
    int getPtr(){return *ptr;}
};
int main() {
    Base b;
    b.setVal(15);
    b.setPtr(10);
    
    Base b1 = b;
    
    // in below case default assignment operator is called 
    //Base b1;
    //b1 = b;
    
    b1.setPtr(90000);
    
    cout<<"b.val: "<<b.getVal()<<endl;
    cout<<"b.ptr: "<<b.getPtr()<<endl;
    
    cout<<"b1.val: "<<b1.getVal()<<endl;
   cout<<"b1.ptr: "<<b1.getPtr()<<endl;
    
	return 0;
}
