#include<iostream>
#include<windows.h>
using namespace std;
class firgue
{
    public:
    int a[100];
    int even(const int &n) const
    {
        if(n%2==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    firgue first;
    int m,sum=0;
    first.a[0]=1;
    for(int i=0;;i++)
    {
        if(first.a[i]>0)
        {
            cin>>first.a[i+1];
        }
        else
        {
            m=i-1;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(first.even(first.a[i])==0)
        {
            sum+=first.a[i];
        }
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}