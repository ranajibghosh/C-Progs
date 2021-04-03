// singleton class
#include <iostream>
#include <conio>
//#include <lock.h>
//using namespace std;
class GetSetting
{
        static GetSetting* instance;
        int brightness;
        int height;
        int width;
        GetSetting():brightness(75),height(1300),width(786){}
    public:
        static GetSetting* getInstance(){
            cout<<"Getinstance"<<endl;
            if (instance == NULL){
                instance = new GetSetting();
            }
            return instance;
        }
        void setBrightness(int b){ brightness = b;}
        void setWidth(int w){ width = w;}
        void setHeight(int h){ height = h;}

        int getBrightness(){ return brightness;}
        int getWidth(){ return width;}
        int getHeight(){ return height;}
		
		void displaySetting(){
			cout<<"---------------------"<<endl;
			cout<<"Brightness :"<<getBrightness()<<endl;
			cout<<"Width :"<<getWidth()<<endl;
			cout<<"Height :"<<getHeight()<<endl;
			cout<<"---------------------"<<endl;
		}
		
};
GetSetting* GetSetting::instance = NULL;
void someFunction(){
	 GetSetting* n = GetSetting::getInstance();
	 n->displaySetting();
}

int main()
{
    GetSetting* s = GetSetting::getInstance();
    GetSetting* r = GetSetting::getInstance();
    GetSetting* n = GetSetting::getInstance();
	
	s->displaySetting();

    someFunction();
   // GetSetting w; error
    cout << s << endl;
    cout << r << endl;
    cout << n << endl;

    getch();
    return 0;
}
