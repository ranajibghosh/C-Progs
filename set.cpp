#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class Person{
    public:
    float age;
    string name;
    bool operator<(const Person& rhs) const{
        return age<rhs.age;
    }
     bool operator>(const Person& rhs) const{
        return age>rhs.age;
    }
};

int main() {
 
 /*  
   set <int> setvar={1,2,5,4,3,1,2,3,4,5};
 
   for(const auto& e:setvar){
       cout<<""<<e<<endl;
   }
  //output : 12345
  */ 
  
  set<Person> per={{30,"Rupesh"},{25,"Hitesh"},{22,"John"}};
  //set<Person, std::greater<Person>> per={{30,"Rupesh"},{25,"Hitesh"},{22,"John"}};
  //set<Person, std::less<>> per={{30,"Rupesh"},{25,"Hitesh"},{22,"John"}};
  
  for(const auto& e:per){
       cout<<"Age : "<<e.age<<" Name : "<<e.name<<endl;
  }
   
   return 0;
}