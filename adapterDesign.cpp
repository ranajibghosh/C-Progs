#include <iostream>
#include <memory>
#include <string>
using namespace std;
class INDIANSocket{
    public:
    virtual void indiancharger(char )=0;
};
class USASocket{
    public:
    void usacharger(){cout<<"USA plug is charging"<<endl;}
};
class GermanSocket{
    public:
    void germancharger(){cout<<"GERMAN plug is charging"<<endl;}
};

class socketAdapter: public INDIANSocket,public USASocket, public GermanSocket{
    public:
    void indiancharger( char ch){
        switch(ch){
            case 'U':
                usacharger();
                break;
            case 'G':
                germancharger();
                break;
            default:
                break;
        }
    }
};

int main(){
    unique_ptr<INDIANSocket> socket = make_unique<socketAdapter>();
    //unique_ptr<INDIANSocket> socket1 = make_unique<socketAdapter>();
    socket->indiancharger('U');
    socket->indiancharger('G');
    return 0;
}