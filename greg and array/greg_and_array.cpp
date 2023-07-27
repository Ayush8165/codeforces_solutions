// n m k
// array   (indexing from 1)
// op1     l,r,d from l to r add d
// op2
// op3
// q1      x,y  aplly op from x to y
// q2
// q3

#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l[m], r[m], d[m];
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    // creating prefix array for queries
    int pref_qu[m + 1] = {0};
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        pref_qu[x - 1]++;
        pref_qu[y]--;
    }
    for (int i = 1; i < m + 1; i++)
    {
        pref_qu[i] = pref_qu[i - 1] + pref_qu[i];
    }
    // print(pref_qu, m + 1);

    // creating prefix array for operations
    int pref_op[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        pref_op[l[i] - 1] = pref_op[l[i] - 1] + d[i] * pref_qu[i];
        pref_op[r[i]] = pref_op[r[i]] + d[i] * pref_qu[i] * (-1);
    }
    for (int i = 1; i < n + 1; i++)
    {
        pref_op[i] = pref_op[i - 1] + pref_op[i];
    }
    // print(pref_op, n + 1);

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] + pref_op[i];
    }
    print(arr, n);

    return 0;
}