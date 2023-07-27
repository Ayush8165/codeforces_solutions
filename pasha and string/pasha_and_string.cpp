#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int temp)
{
    int i = temp - 1;
    int j = s.length() - temp;

    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
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
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int freq[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < max + 1; i++)
    {
        if (freq[i] % 2 != 0)
        {
            solve(s, i);
        }
    }

    cout << s;

    return 0;
}