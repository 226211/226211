#include<iostream>
#include<windows.h>
using namespace std;
class firgue
{
        public:
        int a,b;
        void input()
        {
                cin>>a>>b;
        }
        int gcd(int a,int b)
        {
            if(b==0)
                return a;
            else
                return gcd(b,a%b);
        }
        int lcm(int a,int b)
        {
            return a*b/gcd(a,b);
        }
};
int main()
{
        firgue f;
        int c;
        f.input();
        if(f.a>f.b)
        {
            ;
        }
        else
        {
            c=f.a;
            f.a=f.b;
            f.b=c;
        }
        cout<<f.gcd(f.a,f.b)<<endl;
        cout<<f.lcm(f.a,f.b)<<endl;
        system("pause");
        return 0;
}