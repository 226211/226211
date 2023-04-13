#include<iostream>
#include<windows.h>
using namespace std;
class three
{
    public:
    int num,a[100][100];
    three(int n)
    {
        num = n;
    }
    int construct()
    {
        int b,c;
        a[1][1]=1;
        for(b=2;b<=num;b++)
        {
            for(c=1;c<=b;c++)
            {
                a[b][c] = a[b - 1][c - 1] + a[b - 1][c];
            }
        }

    }
    int print()
    {
        int b, c;
        for(b=1;b<=num;b++)
        {
            for(c=1;c<=b;c++)
            {
                cout << a[b][c]<<" ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n,m;
    cin >> n;
    for (; n > 0;n--)
    {
        cin >> m;
        three th(m);
        th. construct();
        th. print();
    }
    system("pause");
}
