/* leetcode l1 - two sum
 * Jan 19, 2026
 */

vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int, int> hash;

        for (int i = 0; i < n.size(); ++i) {
                int c = t - n[i];
                if (hash.find(c) != hash.end())
                        return {hash[c], i};

                hash[n[i]] = i;
        }

        return {};
}
