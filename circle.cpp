#include<iostream>
#include<windows.h>
#define PI 3.14
using namespace std;
class circle
{
    public:
    int r,c,s;
    circle(int a)
    {
        r=a;
    }
    void perimeter()
    {
        c=2*PI*r;
        cout<<"�ܳ�=="<<c<<endl;
    }
    void area()
    {
        s=PI*r*r;
        cout<<"���=="<<s<<endl;
    }

};
int main()
{
    int a;
    cin>>a;
    circle first(a);
    cout<<"ֱ��=="<<2*a<<endl;
    first.perimeter();
    first.area();
    system("pause");
}