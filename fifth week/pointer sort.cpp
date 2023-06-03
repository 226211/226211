#include<iostream>
#include<windows.h>
using namespace std;
class figure
{
    public:
    void sort(int *num,int n)
    {
        int temp;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)//先对n个数进行排序，把n个数里面的最大数排到第一位，然后再对n-1个数进行排序，再把n-1里面的最大数排到第二位，以此类推
            {
                if(num[j]>num[j+1])
                {
                    temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp;
                }
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    figure f;
    f.sort(num,n);
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    system("pause");
    return 0;
}