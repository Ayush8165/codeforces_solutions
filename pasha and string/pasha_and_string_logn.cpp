#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int n;
    cin >> n;

    int arr[n];
    int pre[(s.length() / 2) + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pre[arr[i] - 1]++;
        pre[(s.length() / 2)]--;
    }
    // print(pre, (s.length() / 2) + 1);

    for (int i = 1; i < (s.length() / 2) + 1; i++)
    {
        pre[i] = pre[i - 1] + pre[i];
    }
    // print(pre, (s.length() / 2) + 1);

    for (int i = 0; i < (s.length() / 2); i++)
    {
        if (pre[i] % 2 == 1)
        {
            swap(s[i], s[s.length() - 1 - i]);
        }
    }

    cout << s;

    return 0;
}