#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
class key
{
public:
    string str1;
    int k;
    void set()
    {
        getline(cin, str1);
    }
    void format()
    {
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]>='a'&&str1[i]<='z')
            {
                str1[i]=str1[i]-32;
            }
            if(str1[i]=='-')
            {
                for(int j=i;j<str1.length();j++)
                {
                    str1[j]=str1[j+1];
                }
            }
        }
    }
    void finish()
    {
        int a=0;
        a=(str1.length()-1)%k;
        if(a!=0)
        {
            for(int i=a;i<str1.length()-1;i=i+k+1)
            {
                str1.insert(i,"-");
            }
        }
        if(a==0)
        {
            for(int i=k;i<str1.length()-1;i=i+k+1)
            {
                str1.insert(i,"-");
            }
        }
    }
};
int main()
{
    key k1;
    k1.set();
    cin>>k1.k;
    k1.format();
    k1.finish();
    cout<<k1.str1<<endl;
    system("pause");
    return 0;
}
