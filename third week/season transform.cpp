#include<iostream>
#include<windows.h>
using namespace std;
class season
{
public:
    void setseason(int a)
    {
        if(a==1)
        {
            cout<<"spring"<<endl;
        }
        else if(a==2)
        {
            cout<<"summer"<<endl;
        }
        else if(a==3)
        {
            cout<<"autumn"<<endl;
        }
        else
        {
            cout<<"winter"<<endl;
        }
        
    }
};
int main()
{
    season s;
    int a;
    cin>>a;
    s.setseason(a);
    system("pause");
    return 0;
}