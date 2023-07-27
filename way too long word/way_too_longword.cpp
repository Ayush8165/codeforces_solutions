#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    char ch, pre;
    int i = 0;
    bool flag;
    cin.get(ch);
    while (n--)
    {
        i = 0;
        flag = false;
        while (cin.get(ch))
        {
            if (i == 0)
            {
                cout << ch;
            }
            else if (ch == '\n')
            {
                cout << i - 2 << pre;
                flag = true;
                break;
            }
            i++;
            pre = ch;
        }
        if (flag == false)
        {
            cout << i - 2 << pre;
            break;
        }

        cout << endl;
    }

    return 0;
}