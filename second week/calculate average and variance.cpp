#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;
class outcome
{
    public:
    double num[100];
    double average,variance;
    outcome(){}
    outcome(double *a)
    {
        for (int i=0;i<6;i++)
        {
            num[i] = a[i];
        }
    }
    void calculate()
    {
        double sum = 0;
        for (int i=0;i<6;i++)
        {
            sum += num[i];
        }
        average = sum / 6;
        sum = 0;
        for (int i=0;i<6;i++)
        {
            sum += (num[i] - average) * (num[i] - average);
        }
        variance = sum / 6;
    }
};
int main()
{
    double a[6],n;
    int i;
    outcome variable[100] = {};
    cin>>n;
    for(i=0;i<n;i++)
    {
        for (int j=0;j<6;j++)
        {
            cin >> a[j];
        }
        variable[i] = outcome(a);                  
        variable[i].calculate();
    }
    for(i=0;i<n;i++)
    {
        cout<<fixed<<setprecision(2);
        cout<<variable[i].average<<" "<<variable[i].variance<<endl;
    }
    system("pause");
}
