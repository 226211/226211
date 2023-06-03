#include<iostream>
#include<windows.h>
using namespace std;
class item
{
    public:  
    int a[100];
    item():a{0}{}
    int  set()
    {
        int c,b;
        cin>>b>>c;
        a[b]=a[b]+c;
        return b;
    }
};
int main()
{
    item f;
    int n,m;
    n=f.set();
    m=n;
    for(;m>0;)
    {
        m=f.set();
    }
    for(int i=n;i>=0;i--)
    {
        if(i==1)
        cout<<f.a[i]<<"x"<<'+';
        else if(i==0)
        cout<<f.a[i]<<endl;
        else
        cout << f.a[i] << "x^" << i << '+';
    }
    system("pause");
}