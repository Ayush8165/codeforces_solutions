#include <bits/stdc++.h>
using namespace std;

int answer;

int solve(int x, int y, int n, int count)
{
    int op1, op2;
    if (x >= n or y >= n)
    {
        return count;
    }

    if (1)
    {
        x = x + y;
        count++;
        op1 = solve(x, y, n, count);
    }
    if (1)
    {
        y = x + y;
        count++;
        op2 = solve(x, y, n, count);
    }
    answer = min(op1, op2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int x = 1, y = 1;

    int arr[] = {1, 1};
    solve(x, y, n, 0);
    cout << answer;

    return 0;
}