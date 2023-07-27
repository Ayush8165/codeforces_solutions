#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    long long a, b, n;
    cin >> a >> b >> n;
    if (a % n == 0)
    {
        a = a / n;
    }
    else
    {
        a = a / n + 1;
    }

    if (b % n == 0)
    {
        b = b / n;
    }
    else
    {
        b = b / n + 1;
    }
    cout<<a*b;

    return 0;
}