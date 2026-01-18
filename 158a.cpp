/* codeforces 158a - next round
 * Jan 18, 2026
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _YES cout << "YES" << "\n"
#define _NO  cout << "NO"  << "\n"

int main(void)
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n, k;
        cin >> n >> k; 
        
        int a[50];

        for (int i = 0; i < n; ++i)
                cin >> a[i];

        int ik = a[k - 1];

        int c = 0;
        for (int i = 0; i < n; ++i) {
                if (a[i] >= ik && a[i] > 0)
                        ++c;
                else
                        break;
        }
        
        cout << c << endl;

        return 0;
}
