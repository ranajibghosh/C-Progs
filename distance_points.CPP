 #include <iostream>
 #include <conio.h>
 #include <math.h>
 class distance{
     				int cod_x,cod_y;
     				public:
               distance(int x=0, int y=0):cod_x(x),cod_y(y){}
               ~distance(){}
               float operator-(distance d);
               void show();
 };
 float distance:: operator-(distance d){
                  float dis;
                  dis = sqrt(pow(d.cod_x - cod_x, 2) + pow(d.cod_y - cod_y, 2));
                  return dis;
}
void distance :: show(){ cout<<" x = "<<cod_x<<", y ="<<cod_y<<endl;}
 int main(){

   distance d1(-2,8), d2(8,6);
   d1.show();
   d2.show();
   cout<<" Distance b/w them =" <<(d2-d1)<<endl;
   getch();
   return 0;
 }