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
            for(int j=0;j<n-1-i;j++)//�ȶ�n�����������򣬰�n���������������ŵ���һλ��Ȼ���ٶ�n-1�������������ٰ�n-1�����������ŵ��ڶ�λ���Դ�����
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