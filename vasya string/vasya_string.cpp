#include <iostream>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int solve(string &s, int k, char x)
{
    int i = 0, j = 0; // pointers of window j->start & i->end of window
    int maximum_substring = 0;
    int count = 0; // no of changes

    for (i = 0; i < s.length(); i++)
    {
        if (s[i] != x)
        {
            /* hum maan lenge ki iss window mai apko yeh character
            dusre m change krna pdega */
            count++;
        }

        while (count > k and j <= i)
        {
            if (s[j] != x)
            {
                count--;
            }
            j++;
        }

        maximum_substring = max(i - j + 1, maximum_substring);
    }
    return maximum_substring;
}

int main()
{
    init_code();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans1 = solve(s, k, 'a');
    int ans2 = solve(s, k, 'b');

    cout << max(ans1, ans2);
    return 0;
}