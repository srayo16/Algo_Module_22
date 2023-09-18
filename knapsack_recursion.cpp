#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int val[N], w[N];
int dp[1005][1005];

int knapsack(int n, int s)
{
    if (n <= 0 || s <= 0)
        return 0;

    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }

    if (w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - w[n - 1]) + val[n - 1];
        int op2 = knapsack(n - 1, s);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = knapsack(n - 1, s);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int s;
    cin >> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, s) << endl;
    return 0;
}