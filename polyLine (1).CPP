#include <iostream>
#include <vector>
#include <conio>
using namespace std;
class Point{
 			public:
			int x;
			int y;
         Point():x(0),y(0){}
         void getcoordinate(){
           cout<<"Enter Value of X :";
           cin>>x;
           cout<<"Enter Value of Y :";
           cin>>y;

         }
          void show(){
           cout<<" X="<<x<<",Y="<<y;
         }
			bool operator ==(Point const& p) const{
               if((x == p.x) && (y == p.y) )
               	return true;
               return false;
         }



};

class Polyline{
				vector < Point > pl;
            public:
				void AddPoint(const Point p){
					pl.push_back(p);
				}

            void PrintPolyline();

				void DeletePoint(const Point &p);
            bool CheckIfPolygon();
           // class Point;

};
void Polyline :: PrintPolyline(){
				  //	int s = pl.size();
               vector<Point>::iterator ptr;
               cout<<"----- Points in PolyLine -----------"<<endl;
				   for(ptr = pl.begin(); ptr < pl.end(); ptr++){
               	cout<<"X="<<ptr->x<<" ,Y="<<ptr->y<<endl;
               //for(int i=0; i<s; i++ ){
               //cout<<pl[i].x<<endl; //error, can't able to print
               //cout<<i<<endl;//loop count
               }

  cout<<endl;
				}
void Polyline :: DeletePoint(const Point &p){
            	int s = pl.size();
               //Point temp;
					bool bIfPointFound = false;
               int i;
					for( i=0; i<s; i++){
						if(p == pl[i]){
							bIfPointFound = true;
							break;
						}
					}
					if(true == bIfPointFound ){
						for(int j=i;j<pl.size()-1;j++){
                     pl[j] = pl[j+1];
						}
						pl.pop_back();
					}else{
                 cout<<"No such point exists in the polyline"<<endl;
               }
				}


bool Polyline :: CheckIfPolygon(){
				  Point duplicate;
              bool dIfPointFound = false;
              int s = pl.size();
              int i;
					for( i=0; i<s; i++){
                duplicate = pl[i];
                for(int j=i+1;j<s;j++){
						if(duplicate == pl[j]){
							dIfPointFound = true;
							break;
                     }
						}
					}
               return  dIfPointFound;
				}

int main(){
Polyline objPoly;
//Point *p;
char ch;
int option;

     do{
     Point p;
     cout<<"--------Select -----------"<<endl;
     cout<<"Enter 1 to add element in polyline"<<endl;
     cout<<"Enter 2 to delete element from polyline"<<endl;
     cout<<"Enter 3 to check whether polygon or not"<<endl;
     cout<<"Enter your choice : ";
     cin>>option;
     cout<<"-------------------"<<endl;
     switch(option){
     	 case 1:
					p.getcoordinate();
      			//p->show();
					objPoly.AddPoint(p);
      			objPoly.PrintPolyline();
       break;
       case 2:
       			cout<<"Enter the vaue of x,y to delete from poyline : "<<endl;
               p.getcoordinate();
               objPoly.DeletePoint(p);
               objPoly.PrintPolyline();

       break;
       case 3:  if(objPoly.CheckIfPolygon()){
       				cout<<"It is a polygon"<<endl;
       			 }else{
                  cout<<"It is not a polygon"<<endl;
                }
       break;
       default: cout<<"No such options."<<endl;break;

     }
      cout<<"Do you want to continue (Y/N):" ;
      cin>>ch;
    
      }while((ch=='Y')||(ch=='y'));



 getch();

return 0;
}