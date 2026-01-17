/* codeforces 71b - progress bar
 * Jan 18, 2026
 */

#include <iostream>

using namespace std;

int main(void)
{
        int n, k, t;
        cin >> n >> k >> t;

        int tot = n * k * t / 100;

        for (int i = 0; i < n; ++i) {
                if (tot >= k) {
                        cout << k << " ";
                        tot -= k;
                } else if (tot > 0) {
                        cout << tot << " ";
                        tot = 0;
                } else {
                        cout << 0 << " ";
                }
        }

        cout << endl;

        return 0;
}
