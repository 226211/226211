#include<iostream>
#include<windows.h>
using namespace std;
class decimal
{
    public:
    int m,n,c;
    int calculate(int a,int b)
    {
        if(a>b)
        {
            c=a/b;
            m=a%b;
        }
        else
        {
            c=10*a/b;
            m=a*10%b;
        }
        return c;
    }
};
int main()
{
    decimal d;
    cin >> d.m;
    cin.ignore();
    cin >> d.n;
    cout <<"0.";
    for(int i=0;i<200;i++)
    {
        cout << d.calculate(d.m,d.n);
    }
    system("pause");
}