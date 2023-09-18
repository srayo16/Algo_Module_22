// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int val[N], w[N];
int dp[1005][1005];

int knapsack(int n, int s)
{
    if (n <= 0 || s <= 0)
        return 0;

    if (dp[n][s] != 0)
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
        int op2 = knapsack(n - 1, s);

        return dp[n][s] = op2;
    }
}

int main()
{
    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> val[i];
    }
    cout << knapsack(n, s) << endl;

    return 0;
}