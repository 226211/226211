#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
class number
{
public:
    int a,b[31];
    void set()
    {
            cin >> a;
    }
    void transform()
    {
            for(int i=31;i>=0;i--)
            {
                b[i]=a/pow(10,i);
                a=a-b[i]*pow(10,i);
            }
    }
    void output()
    {
        for(int i=0;i<=31;i++)
        {
            cout<<b[i];
        }
    }
    
};
int main()
{
    number fir;
    fir.set();
    fir.transform();
    fir.output();
    system("pause");
    return 0;

}