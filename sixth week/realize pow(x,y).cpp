#include<iostream>
#include<windows.h>
#include<stdio.h>
using namespace std;
class solution 
{
public:
    int x,n,m; 
    solution()
    {
        scanf("%d,%d", &x, &n);
    } 
    void solve()
    {
        m=1;
        for(int i=1;i<=n;i++)
        {
            m*=x;
        }
        cout<<m<<endl;
    }
    
};
int main()
{
    solution a;
    a.solve();
    system("pause");
    return 0;
}
