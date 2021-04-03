/*
emplace_back() vs push_back()

push_back() copies a string into a vector. First, 
a new string object will be implicitly created initialized with provided char*. 
Then push_back will be called which will copy this string into the vector 
using the move constructor because the original string is a temporary object. 
Then the temporary object will be destroyed. emplace_back() constructs a string in-place, 
so no temporary string will be created but rather emplace_back() 
will be called directly with char* argument. 
It will then create a string to be stored in the vector initialized with this char*. 
So, in this case, we avoid constructing and destroying an unnecessary temporary string object.

*/
#include<iostream>
#include<vector>
#include<thread>
class Point{
    int x;
    int y;
    public:
    Point():x{10},y{10}{}
    Point(int x, int y):x{x},y{y}{}
    ~Point(){}
    int getX(){return x;}
    int getY(){return y;}
};
int main(){
    std::vector<Point> v(2);
    v.reserve(10);
    v.emplace_back(Point(1,2));

    for(auto it = v.begin(); it != v.end(); ++it){
        std::cout<<(*it).getX()<<","<<(*it).getY()<<std::endl;
    }
    v[0].getX();
    std::cout<<v[0].getY()<<std::endl;
    std::cout<<v[v.size()-1].getY()<<std::endl;
    std::cout<<"_________________________________"<<std::endl;
    std::cout<<"sizeof  v:"<<sizeof(v)<<std::endl;
    std::cout<<"CAPACITY OF v:"<<v.capacity()<<std::endl;
    std::cout<<"SIZE OF v:"<<v.size()<<std::endl;
    std::cout<<"_________________________________"<<std::endl;


    std::cout<<"_________________________________"<<std::endl;
    //std::vector<int> arr2{5,20}; // size is 2; arr2[0] = 5, arr2[1] = 20.
    std::vector<int> arr2(5,20); // size is 5; arr2[0] = 20,....., arr2[4] = 20.
    std::cout<<"SIZE OF arr2:"<<arr2.size()<<std::endl;
    for (int i=0; i<arr2.size(); i++) 
        std::cout << arr2[i] << std::endl;
    std::cout<<"_________________________________"<<std::endl;


    std::cout<<"_________________________________"<<std::endl;
    std::vector<std::pair<char, int>> vect;
    vect.emplace_back('a', 24);
    //vect.push_back('b', 25); //would not compile 
    std::cout<<"SIZE OF VECT:"<<vect.size()<<std::endl;
    for (int i=0; i<vect.size(); i++) 
        std::cout << vect[i].first << " " << vect[i].second << std::endl;
    std::cout<<"_________________________________"<<std::endl;

     return 0;
}

/*

// C++ code to demonstrate difference between 
// emplace_back and insert_back 
In C++, all containers (vector, stack, queue, set, map, etc) 
support both insert and emplace operations.
The advantage of emplace is, it does in-place insertion and avoids an unnecessary copy of object.
 For primitive data types, it does not matter which one we use. But for objects, 
 use of emplace() is preferred for efficiency reasons.


#include<bits/stdc++.h> 
using namespace std; 
    
int main() 
{ 
    // declaring priority queue 
    vector<pair<char, int>> vect; 
        
    // using emplace() to insert pair in-place 
    vect.emplace_back('a', 24); 
        
    // Below line would not compile 
    // vect.push_back('b', 25);     
        
    // using push_back() to insert 
    vect.push_back(make_pair('b', 25));     
        
    // printing the vector 
    for (int i=0; i<vect.size(); i++) 
        cout << vect[i].first << " " << vect[i].second 
             << endl; 
   
    return 0; 
} 
Output:

a 24
b 25

*/