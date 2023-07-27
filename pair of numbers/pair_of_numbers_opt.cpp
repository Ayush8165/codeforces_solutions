#include <bits/stdc++.h>
using namespace std;

int min_steps = INT_MAX;

void path(int x, int y, int count)
{
    if (x == 1 and y == 1)
    {
        min_steps = min(min_steps, count);
        return;
    }

    if (x - y > 0)
    {
        path(x - y, y, count + 1);
    }
    if (y - x > 0)
    {
        path(x, y - x, count + 1);
    }
}

void solve(int n)
{
    if (n == 1)
    {
        min_steps = 0;
        return;
    }

    for (int i = 1; i < n; i++)
    {
        path(i, n - i, 1);
    }

    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    solve(n);
    cout << min_steps;

    return 0;
}