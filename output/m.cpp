#include<iostream>
#include<windows.h>
using namespace std;
class date
{
    public:
       int year,month,day,num;
       date(int y,int m,int d)
       {
           year = y;
           month = m;
           day = d;
       }
       void number()//2023--04--15
       { 
            int a,y,m,num1,num2;
            for(y=1990,a=0;y<year;y++)
            {
                if(y%4==0)
                {
                    if(y%100==0)
                    {
                        if(y%400==0)
                        {
                            a=a+1;
                        }
                    }
                    else
                    {
                        a=a+1;
                    }
                }
            }
            num1=366*a+365*(year-1990-a);
            cout << num1 << endl;
            for(m=1;m<month;m++)
            {
                if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
                {
                    num2=num2+31;
                }
                else if(m==2)
                {
                    if(year%4==0)
                    {
                        if(year%100==0)
                        {
                            if(year%400==0)
                           {
                                num2=num2+29;
                            }
                            else 
                            {
                            num2=num2+28;
                            }
                        } 
                        else
                        {
                            num2=num2+29;
                        }
                    }
                    else
                    {
                        num2=num2+28;
                    }
                }
                else if(m==4||m==6||m==9||m==11)
                {
                    num2=num2+30;
                }
            
            }
            num=num1+num2+day;
          
       }
       void print()
       {
            int a;
            a = num % 7;
            
            if(a==0)
            {
            cout << "Sunday" << endl;
            }
            if(a==1)
            {
            cout << "Monday" << endl;
            }
            if(a==2)
            {
            cout << "Tuesday" << endl;
            }
            if(a==3)
            {
            cout << "Wednesday" << endl;
            }
            if(a==4)
            {
            cout << "Thursday" << endl;
            }
            if(a==5)
            {
            cout << "Friday" << endl;
            }
            if(a==6)
            {
            cout << "Saturday" << endl;
            }

       }
       
};
int main()
{
    int y,m,d;
    char a[100],b[100];
    cin >> y >> a >> m >> b >> d;
    cout << y << endl;
     cout << m<< endl;
      cout << d<< endl;
    date first(y, m, d);
    first.number();
    first.print();
    system("pause");
    return 0;
}
