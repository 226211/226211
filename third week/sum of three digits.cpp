#include<iostream>
#include<windows.h>
using namespace std;
class number
{
    public:
    int general,hundred,ten,one;
    void getnumber(int n)
    {
        general=n;
        hundred=n/100;
        ten=(n-hundred*100)/10;
        one=n-hundred*100-ten*10;
        cout << hundred+ten+one << endl;
    }
};
int main()
{
    int a;
    number num;
    cin >> a;
    num.getnumber(a);
    system("pause");
}