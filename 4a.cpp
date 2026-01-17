/* codeforces 4a - watermelon
 * Jan 18, 2026
 */

#include <iostream>

using namespace std;

int main(void)
{
        int w; 
        cin >> w;

        if (!(w % 2) && w > 2)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;

        return 0;
}
