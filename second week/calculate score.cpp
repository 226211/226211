#include<iostream>
#include<iomanip>
#include<windows.h>
#include<string>
using namespace std;
class student
{
    public:
    char name[100];
    float  daily,terminal,general;
    student(){}
    student(char a[100],float b,float c)
    {
        strcpy(name, a);
        daily = b;
        terminal = c;
    }
    void calculate()
    {
        general = daily * 0.4 + terminal * 0.6;
    }
};
int main()
{
    const int size = 100;
    int i,j,k;
    student stu[size] = {};
    student temp;
    for (i=0;cin>>stu[k].name>>stu[k].daily>>stu[k].terminal;k++)
    {
        stu[k].calculate();
    }
    // 将已经赋值的对象根据general排序
   for(i=0;i<k;i++)
    {
        for (j=i+1;j<k;j++)
        {
            if (stu[i].general < stu[j].general)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    // 打印
    for (i=0;i<k;i++)
    {
        cout<<fixed<<setprecision(2);
        cout << stu[i].name << " " << stu[i].daily << " " << stu[i].terminal << " " << stu[i].general << endl;
    }
    system("pause");
    return 0;   
}                     