#include <iostream>
 
int main()
{
    const int n = 5;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == 1) {
                std::cout << abs(i - 2) + abs(j - 2);
            }
        }
    }
    return 0;
}
