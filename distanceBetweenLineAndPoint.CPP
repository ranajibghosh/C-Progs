#include <iostream>
#include <conio>
#include <math>
//using namespace std;
class Line;
class Point{
	public:
    int codX,codY;
    Point(){codX=0;codY=0;}
    void setPoint(){
		int x,y;
		cout<<"Enter coordinate of a point"<<endl;
		cout<<"X= ";
		cin>>x;
		codX = x;
		cout<<"Y= ";
		cin>>y;
		codY = y;
    }
	void getPoint(){
		cout<<" Coordinate of the point is ";
		cout<<"("<<codX<<" ,"<<codY<<")";
    }
	friend double ShortestDistance(Line, Point);
};
class Line{
	Point s,e;
	public:
	Line(){}
	void setLine(){
		int startX,startY,endX,endY;
		cout<<"Enter X coordinate of stating point of a line :";
		cin>>startX;
		s.codX = startX;
		cout<<"Enter Y coordinate of stating point of a line :";
		cin>>startY;
		s.codY = startY;
		cout<<"Enter X coordinate of end point of a line :";
      cin>>endX;
		e.codX = endX;
		cout<<"Enter Y coordinate of end point of a line :";
      cin>> endY;
		e.codY = endY;
	}
	void getLine(){
		cout<<"The line is :";
		cout<<"("<<s.codX<<" ,"<<s.codY<<")-----("<<e.codX<<" ,"<<e.codY<<")";
    }
	friend double ShortestDistance(Line, Point);
};
double  ShortestDistance(Line l, Point p){
	Point AB, AE, BE;
	// vector AB 
	AB.codX = l.e.codX - l.s.codX;
	AB.codY = l.e.codY - l.s.codY;
	// vector AE
	AE.codX = p.codX - l.s.codX;
	AE.codY = p.codY - l.s.codY;
	// vector BE
	BE.codX = p.codX - l.e.codX;
	BE.codY = p.codY - l.e.codY;

	// Variables to store dot product
	double ABtoBE, ABtoAE;

	ABtoBE = (AB.codX*BE.codX + AB.codY*BE.codY);
	ABtoAE = (AB.codX*AE.codX + AB.codY*AE.codY);

	// Minimum distance from point E to the line segment
	double minDistance = 0;

	if(ABtoBE > 0){
      double x,y;
		 x = p.codX - l.e.codX;
		 y = p.codY - l.e.codY;
		minDistance = sqrt(x*x + y*y);
      //cout<<"1st if :"<<x<<y<<minDistance;
	}else if(ABtoAE < 0){
   	int x,y;
		 x = p.codX - l.s.codX;
		 y = p.codY - l.s.codY;
		minDistance = sqrt(x*x + y*y);
      //cout<<"2nd if";

	}else{
		// Finding the perpendicular distance
		double x1,x2,y1,y2;
		x1 = AB.codX;
		y1 = AB.codY;

		x2 = AE.codX;
		y2 = AE.codY;

		double mod = sqrt(x1 * x1 + y1 * y1);
		minDistance = abs(x1 * y2 - y1 * x2) / mod;
      //cout<<"else";
	}
   cout<<"Result:"<<minDistance;
	return minDistance;
}
int main(){
	double res;
	Point p1;
	Line l1;
	l1.setLine();
	p1.setPoint();
	l1.getLine();
	p1.getPoint();
	res = ShortestDistance( l1,  p1);
	cout<<" Minimum distance between the line and the point is :"<<res;
	getch();
	return 0;
}

