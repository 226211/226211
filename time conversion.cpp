#include<iostream>
#include<windows.h>
using namespace std;
class time
{
    public:
    int hour,minute,general;
    time(int a)
    {
        general = a;
        if(a>=100)
        {
            hour = a / 100;
            minute = a % 100;
        }
        else
        {
            hour = 0;
            minute = a;
        }
    }
    void transform()
    {
        if(hour>=8)
        {
            hour-=8;
        }
        else
        {
            hour+=16;
        }
    }

};
int main()
{
    int a;
    cin >> a;
    time first(a);
    first.transform();
    if(first.hour==0)
    {
        cout<<first.minute<<endl;
    }
    else
    {
        cout<<first.hour<<first.minute<<endl;
    }
    system("pause");

}