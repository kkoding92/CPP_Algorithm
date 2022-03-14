#include <iostream>
using namespace std;

int a, b, c;
int dp[21][21][21];

int W(int a, int b, in c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);
    else if (a < b && b < c)
    {
        if (dp[a][b][c] != 0) return dp[a][b][c];
        else return dp[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
    }
    else
    {
        if (dp[a][b][c] != 0) return dp[a][b][c];
        else return dp[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
    }
}

int main()
{
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << '\n';
    }
}
