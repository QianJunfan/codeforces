/* codeforces 71c - round table knights
 * Jan 18, 2026
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) 
                cin >> a[i];

        for (int d = 1; d <= n / 3; ++d) {
                if (!(n % d)) {
                        for (int i = 0; i < d; i++) {
                                bool ok = true;

                                for (int j = i; j < n; j += d) {
                                        if (a[j] == 0) {
                                                ok = false;
                                                break;
                                        }
                                }

                                if (ok) {
                                        cout << "YES" << endl;
                                        return 0;
                                }
                        }
                }
        } 

        cout << "NO" << endl;

        return 0;
}
