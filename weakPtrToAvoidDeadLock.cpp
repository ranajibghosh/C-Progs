#include <iostream>
#include <memory>
using namespace std;

struct son;
struct daughter;

struct mother{
    ~mother(){
        cout<<"Mother gone"<<endl;
    }
    void setSon(const weak_ptr<son> s){
        mySon=s;
    }
    void setDaughter(const weak_ptr<daughter> d){
        myDaughter=d;
    }
   // shared_ptr<son> mySon;
    weak_ptr<son> mySon;
    weak_ptr<daughter> myDaughter;
};

struct son{
    son(shared_ptr<mother> m):myMother(m){}
    ~son(){ cout<<"Son gone"<<endl;}
    shared_ptr<const mother> myMother;
};


struct daughter{
    daughter(shared_ptr<mother> m):myMother(m){}
    ~daughter(){ cout<<"Daughter gone"<<endl;}
    shared_ptr<const mother> myMother;
};
int main(){
   shared_ptr<mother> mom= shared_ptr<mother> (new mother); 
   shared_ptr<son> sn= shared_ptr<son> ( new son(mom) );
   shared_ptr<daughter> dr= shared_ptr<daughter> (new daughter(mom)); 
   
   mom->setSon(sn);
   mom->setDaughter(dr);
    return 0;
}