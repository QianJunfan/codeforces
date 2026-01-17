/* codeforces 71a - way too long words
 * Jan 18, 2026
 */
#include <iostream>
#include <string>

using namespace std;

void solve()
{
        string s;
        cin >> s;
 
        int n = s.length();

        if (n > 10)
                cout << s[0] << n - 2 << s[n - 1] << endl;
        else
                cout << s << endl;
}

int main(void)
{
        int n;
        
        if (cin >> n) {
                while (n--) {
                        solve();
                }
        }

        return 0;
}

