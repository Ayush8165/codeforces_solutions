#include <bits/stdc++.h>
using namespace std;

void fillfreq(string s, int length, int arr[], int n)
{
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '?')
        {
            continue;
        }

        int temp = s[i] - 97;
        arr[temp]++;
    }
}

int check_max_avaiable(int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            flag = i;
        }
    }
    arr[flag]++;
    return flag;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n] = {0};

    string s;
    cin >> s;
    int length = s.length();
    fillfreq(s, length, arr, n);

    for (int i = 0, j = length - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
        {
            if (s[i] != '?' && s[j] != '?')
            {
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
            else if (s[i] == '?' or s[j] == '?')
            {
                if (s[i] == '?')
                {
                    s[i] = s[j];
                    int temp = s[j] - 97;
                    arr[temp]++;
                }
                else
                {
                    s[j] = s[i];
                    int temp = s[i] - 97;
                    arr[temp]++;
                }
            }
        }
    }

    char ch;
    if (length % 2 == 0)
    {
        for (int i = (length / 2) - 1, j = i + 1; i >= 0, j < length; i--, j++)
        {
            if (s[i] == s[j] and s[i] == '?')
            {
                ch = check_max_avaiable(arr, n) + 97;
                s[i] = s[j] = ch;
            }
        }
    }
    else
    {
        ch = check_max_avaiable(arr, n) + 97;
        if (s[length / 2] == '?')
        {
            s[length / 2] = ch;
        }
        for (int i = (length / 2) - 1, j = i + 2; i >= 0, j < length; i--, j++)
        {
            if (s[i] == s[j] and s[i] == '?')
            {
                char ch = check_max_avaiable(arr, n) + 97;
                s[i] = s[j] = ch;
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            flag = false;
        }
        
    }
    
    if (flag == true)
    {
        cout << s;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }
}