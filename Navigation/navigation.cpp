#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, s, e, w;
    n = s = e = w = 0;
    char input;
    while (cin >> input)
    {
        if (input == 'N')
        {
            n++;
        }
        else if (input == 'S')
        {
            s++;
        }
        else if (input == 'E')
        {
            e++;
        }
        else if (input == 'W')
        {
            w++;
        }
    }
    // cout << n << s << e << w << endl;
    int x = n - s;
    int y = w - e;

    if (x > 0)
    {
        while (x--)
        {
            cout << "N";
        }

        // cout << x << "N ";
    }
    else if (x < 0)
    {
        x = (-1) * x;
        while (x--)
        {
            cout << "S";
        }
        // cout << (-1) * x << "S ";
    }
    if (y > 0)
    {
        while (y--)
        {
            cout << "W";
        }
        // cout << y << "W ";
    }
    else if (y < 0)
    {
        y = (-1) * y;
        while (y--)
        {
            cout << "E";
        }
        // cout << (-1) * x << "E ";
    }

    // cout << x << endl
    //      << y;

    return 0;
}