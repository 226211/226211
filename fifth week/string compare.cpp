#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class character
{
    public:
        string first, second;
        void set()
        {
            getline(cin, first);
            getline(cin, second);
        }
        void compare()
        {
            string temp;
            int m = 0;
            for (int i = 0;i < second.length();i++)
            {
                temp=second.substr(i, first.length());
                if (temp == first)
                {
                    cout << i << endl;
                    m = m + 1;
                }
            }
            if (m == 0)
            {
                cout << -1 << endl;
            }
        }
};
int main()
{
    character a;
    a.set();
    a.compare();
    system("pause");
    return 0;
}