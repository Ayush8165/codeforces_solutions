#include <bits/stdc++.h>
using namespace std;

bool checksum(int sum)
{
    if (sum % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_left(int arr[], int n, int sum, int max, int freq[])
{
    int s = sum / 2;
    int ls = 0;
    int target;
    for (int i = 0; i < n; i++)
    {
        ls += arr[i];
        target = ls - s;
        if (freq[target] > 0)
        {
            cout << "Possible\n";
            return true;
        }
    }
    return false;
}

bool check_right(int arr[], int n, int sum, int max, int freq[])
{
    int s = sum / 2;
    int rs = 0;
    int target;
    for (int i = n - 1; i > -1; i++)
    {
        rs += arr[i];
        target = rs - s;
        if (freq[target] > 0)
        {
            cout << "Possible\n";
            return true;
        }
    }
    return false;
}

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

    int n;
    cin >> n;

    int sum = 0;
    int max = INT_MIN;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    if (checksum(sum) == true)
    {
        int freq[max + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }

        if (check_left(arr, n, sum, max, freq) == true)
        {
            return 0;
        }
        else if (check_right(arr, n, sum, max, freq) == true)
        {
            return 0;
        }
        else
        {
            cout << "Not Possible";
        }
    }
    else
    {
        cout << "Not Possiblee\n";
    }

    return 0;
}