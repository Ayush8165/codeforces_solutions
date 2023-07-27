#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << "NO";
    }
    else
    {
        if (n % 2 != 0)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
    }

    return 0;
}