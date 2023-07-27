#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n, int m)
{
    int answer = -1;
    if (m >= n)
    {
        cout << n;
        exit(0);
    }
    else
    {
        int s = 1, e = 1e10;
        int target = n - m;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int value = (mid * (mid + 1)) / 2;
            if (value >= target)
            {
                answer = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    return answer;
}

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    cout << solve(n, m) + m;

    return 0;
}