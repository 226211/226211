#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class number
{
public:
    int a[100];
    string str;
    void transform()
    {
        for(int i=0;i<7;i++)
        {
            if(str[i]=='A'||str[i]=='B'||str[i]=='C')
            {
                a[i]=2;
            }
            else if(str[i]=='D'||str[i]=='E'||str[i]=='F')
            {
                a[i]=3;
            }
            else if(str[i]=='G'||str[i]=='H'||str[i]=='I')
            {
                a[i]=4;
            }
            else if(str[i]=='J'||str[i]=='K'||str[i]=='L')
            {
                a[i]=5;
            }
            else if(str[i]=='M'||str[i]=='N'||str[i]=='O')
            {
                a[i]=6;
            }
            else if(str[i]=='P'||str[i]=='R'||str[i]=='S')
            {
                a[i]=7;
            }
            else if(str[i]=='T'||str[i]=='U'||str[i]=='V')
            {
                a[i]=8;
            }
            else if(str[i]=='W'||str[i]=='X'||str[i]=='Y')
            {
                a[i]=9;
            }
            else
            {
                a[i]=str[i]-'0';
            }
        }
    }
};
int main()
{
    number n;
    cin>>n.str;
    n.transform();
    for(int i=0;i<7;i++)
    {
        cout<<n.a[i];
    }
    system("pause");
    return 0;
}
