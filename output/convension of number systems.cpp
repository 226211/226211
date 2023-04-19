#include<iostream>
#include<windows.h>
using namespace std;
class transform
{
    public:
        int a,b,c[100],m;
        transform(int A,int B)
        {
            a = A;
            b = B;
        }
        int DtoO()
        {
            for (m=0; a > b;a=a/b,m++)
            {
                c[m] = a % b;
            }
            c[m] = a;
        }
        
        
};
int main()
{
        int n, A, B,e;
        cin >> n;
        for (;n>0;n--)
        {
            cin >> A >> B;
            transform first(A,B);
            first.DtoO();
            for (;first.m>=0;first.m--)
            {
                cout << first.c[first.m];
            }
        }
        system("pause");
}