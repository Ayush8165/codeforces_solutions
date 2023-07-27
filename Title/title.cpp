#include <bits/stdc++.h>
using namespace std;

void filling(string s, int length, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        int temp = s[i] - 97;
        arr[temp]++;
    }
}

int max_char(int arr[], int k)
{
    int flag = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == 0)
        {
            flag = i;
        }
    }
    return flag;
}

bool check_empty(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == 0)
        {
            return true;
        }
    }
    return false;
}

bool check_panindrome(string s)
{
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    int arr[26] = {0};

    string s;
    cin >> s;
    int length = s.length();

    filling(s, length, arr);

    for (int i = 0, j = length - 1; i <= j; i++, j--)
    {
        if (s[i] == '?' and s[j] != '?')
        {
            s[i] = s[j];
            int temp = s[i] - 97;
            arr[temp]++;
        }
        else if (s[i] != '?' and s[j] == '?')
        {
            s[j] = s[i];
            int temp = s[j] - 97;
            arr[temp]++;
        }
    }

    char ch;
    if (length % 2 == 0)
    {
        for (int i = (length / 2) - 1, j = i + 1; i >= 0, j < length; i--, j++)
        {
            if (s[i] == s[j] and s[i] == '?')
            {
                ch = max_char(arr, k) + 97;
                s[i] = s[j] = ch;
                arr[max_char(arr, k)]+=2;
                // arr[max_char(arr, k)]++;
            }
        }
    }
    else
    {
        if (s[length / 2] == '?')
        {
            ch = max_char(arr, k) + 97;
            s[length / 2] = ch;
            arr[max_char(arr, k)]++;
        }
        for (int i = (length / 2) - 1, j = i + 2; i >= 0, j < length; i--, j++)
        {
            if (s[i] == s[j] and s[i] == '?')
            {
                ch = max_char(arr, k) + 97;
                s[i] = s[j] = ch;
                arr[max_char(arr, k)]++;
            }
        }
    }

    if (check_empty(arr, k) == false)
    {
        if (check_panindrome(s) == true)
        {
            cout << s;
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}