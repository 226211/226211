#include<iostream>
#include<windows.h>
using namespace std;
class score
{
    public:
    int a;
    void getscore()
    {
        cin>>a;
        if(0<=a&&a<=100)
        {
            if(90<=a&&a<=100)
            {
                cout<<"A";
            }
            else if(80<=a&&a<=89)
            {
                cout<<"B";
            }
            else if(70<=a&&a<=79)
            {
                cout<<"C";
            }
            else if(60<=a&&a<=69)
            {
                cout<<"D";
            }
            else if(0<=a&&a<=59)
            {
                cout<<"E";
            }
        }
        else
        {
            cout<<"error";
        }
    }
};
int main()
{
    score first;
    first.getscore();
    system("pause");
    return 0;
}