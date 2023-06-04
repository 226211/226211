#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class character
{
    public:
        int mystrstr(char a[100],char b[100])
        {
            char temp[100];
            int m = 0;
            for (int i = 0;i < strlen(b);i++)
            {
                strncpy(temp, a + i, strlen(b));
                if (strcmp(temp, b) == 0)
                {
                    return i;
                    m=m+1;
                }
            }
            if (m == 0)
            {
                return -1;
            }
        }
};
int main()
{
    character a;
    char first[100],second[100];
    cin.getline(first, 100);
    cin.getline(second, 100);
    cout << a.mystrstr(first, second) << endl;
    system("pause");
    return 0;
}