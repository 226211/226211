#include<iostream>
#include<windows.h>
using namespace std;
class course
{
    public:
    int n,k,a[1000];
    course(int N,int K)
    {
        n=N;
        k=K;
    }
    void set()
    {
        int m=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<=0)
            {
                m=m+1;
            }
        }
        if(m>=k)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }

};
int main()
{
    int n,k;
    cin>>n>>k;
    course c(n,k);
    c.set();
    system("pause");
    return 0;
}