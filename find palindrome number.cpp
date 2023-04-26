#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
int main()
{
      int m, k, n, original, next, num, outcome[100],N;
      cin >> N;
      for (; N > 0;N--)
      {

         cin >> m >> k;
      original = m;
      next = k;
      num = 0;
      for (n = original; num <= k;n++)
      {
         int b[100], c[100], e, d, f, g, h, i, j;
         for (f = 1,d=n; d >= 10;f++)
         {
            d = d / 10;
         }
         for (e = 0,g=n,i=f; e < f;e++,i--)//正向排列
         {
            h = pow(10, i - 1);
            b[e] = g /h ;
            g = g - b[e] * h;
         }
            for (e = 0, g = n, i = 1; e < f; e++, i++) // 反向排列
            {
               h = pow(10, i);
               c[e] = (g % h) / (h / 10);
               g = g - c[e] * (h / 10);
            }
         for (e = 0; e < f;e++)
         {
            if(b[e]==c[e])
            {
               ;
            }
            else
            {
               break;
            }
         }
         if(e==f)
         {
            outcome[num] = n;
            num = num + 1;
         }
      }
      for (n = 0; n < 5;n++)
      {
         cout << outcome[n] << ' ';
      }
      system("pause");
    }
}