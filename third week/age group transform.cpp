#include<iostream>
#include<windows.h>
using namespace std;
class age
{
    public:
    int a;
    void getage()
    {
        cin>>a;
        if(1<=a&&a<=10)
        {
            cout<<"Children";
        }
        else if(11<=a&&a<=20)
        {
            cout<<"Teenagers";
        }
        else if(21<=a&&a<=40)
        {
            cout<<"Youth";
        }
        else if(41<=a&&a<=50)
        {
            cout<<"middle-aged";
        }
        else if(51<=a&&a<=80)
        {
            cout<<"Elderly";
        }
        else if(81<=a&&a<=100)
        {
            cout<<"Old man";
        }
    }
};
int main()
{
    age first;
    first.getage();
    system("pause");
    return 0;
}