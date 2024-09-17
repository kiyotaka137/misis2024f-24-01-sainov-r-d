#include <iostream>
#include<algorithm>
int main()
{
    int n = 0;//кол-во ресторанов
    int k = 0;//выделенное время
    int f = 0;
    int t = 0;
    int mx = -100000000000000000;
    std::cin >> n >> k;
    while (n--)
    {
        std::cin >> f >> t;
        if (k<t)
        {
            f -= t - k;
        }
            mx = std::max(mx, f);
 
    }
    std::cout << mx;
}
