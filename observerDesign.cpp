#include <memory>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class subscriber{
    public:
    string subscriberName;
    virtual void updateNews(const string &st)=0;
};
void subscriber::updateNews(const string &st){cout<<"---NEWS UPDATE--- :"<<st<<endl;}
class subsc1:public subscriber{
    public:
    subsc1( const string &c){subscriberName=c;}
    void updateNews(const string &st){
        cout<<"["<<this->subscriberName<<"]";
        subscriber::updateNews(st);
        
    }
};
class subsc2:public subscriber{
    public:
    subsc2( const string &c){subscriberName=c;}
    void updateNews(const string &st){
         cout<<"["<<this->subscriberName<<"]";
         subscriber::updateNews(st);
        
    }
};
class subsc3:public subscriber{
    public:
    subsc3( const string &c){subscriberName=c;}
    void updateNews(const string &st){
        cout<<"["<<this->subscriberName<<"]";
        subscriber::updateNews(st);
        
    }
};
class publisher{
    vector <subscriber *> pub;
    int subscriberCount;
    
    public:
    publisher():subscriberCount{0}{}
    void addSubscribers(subscriber *s){
        pub.push_back(s);
        ++subscriberCount;
    }
    void notifySubscribers(const string &st){
        for(auto &s:pub){
            s->updateNews(st);
        }
    }
    void delSubscribers(subscriber *s, const string &st){
        for(auto beg = pub.begin(); beg!=pub.end(); beg++){
            if(*beg == s){
                s->updateNews(st);
                pub.erase(beg);
                --beg;
                --subscriberCount;
            }
        }
    }
    void numberOfSubscribers(){cout<<" No. of Subcriber(s) :"<<subscriberCount<<"//Vector Size :"<<pub.size()<<endl;}
};
int main(){
    publisher P;
    subsc1 S0("aaa");
    subsc1 S1("bbb");
    subsc2 S2("ccc");
    subsc3 S3("ddd");
    P.addSubscribers(&S0);
    P.addSubscribers(&S1);
    P.addSubscribers(&S2);
    P.addSubscribers(&S3);
    P.numberOfSubscribers();
    P.notifySubscribers("Your are successfully subscribed");
    P.delSubscribers(&S0, "You are unsubscribed....");
    P.numberOfSubscribers();
    P.notifySubscribers("India beat England by 10 wickets..");
   


    return 0;
}