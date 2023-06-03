#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
class word
{
public:
    string a;
    void get()
    {
        getline(cin,a);
    }
    void put()
    {
        int b;
        b=a.length();
        for(int i=0,d=-1,e=0;i<b;i++)
        {
            if(a[i]==' ')
            {
                e=i-d-1;
                d=i;
                cout<<e<<' ';
            }
            else if(a[i+1]=='.')
            {
                e=i-d;
                cout<<e;
            }
        }
    }
};
int main()
{
    word w;
    w.get();
    w.put();
    system("pause");
    return 0;
}
