#include<iostream>
#include<windows.h>
using namespace std;
class point
{
    public:
    int a[100][100],b[100],c[100];
    point():b{0},a{0}{}
    void set(int m,int n)
    {
        cin>>a[m][n];
        if(m==0&&n==0)
        {
            b[m]=a[m][n];
            c[n]=a[m][n];
        }
        if(b[m]<a[m][n])
        {
            b[m]=a[m][n];
        }
        if(c[n]>a[m][n])
        {
            c[n]=a[m][n];
        }
        cout<<a[m][n]<<' '<<b[m]<<' '<<c[n]<<endl;
    }
    void compare(int m,int n)
    {
        if(a[m][n]==b[m]&&a[m][n]==c[n])
        {
            cout<<m<<' '<<n<<endl;
        }
    }
};
int main()
{
    point f;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        f.c[i]=1000;
    }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                f.set(i, j);
            }
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f.compare(i,j);
        }
    }
    system("pause");
}