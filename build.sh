#!/bin/bash

read -p "Enter Problem ID: " pid
pid_lower=$(echo "$pid" | tr '[:upper:]' '[:lower:]')

read -p "Enter Problem Name: " pname

echo "Select platform:"
echo "        1) Codeforces"
echo "        2) LeetCode"
read -p "        Enter choice (1 or 2): " platform_choice

case $platform_choice in
1 | "codeforces" | "cf")
  prefix="codeforces"
  ;;
2 | "leetcode" | "lc")
  prefix="leetcode"
  ;;
*)
  echo "        Invalid choice, defaulting to Codeforces"
  prefix="codeforces"
  ;;
esac

read -p "Include IO optimization? (y/n, default: y): " io_opt
io_opt=${io_opt:-y}

curr_date=$(date +"%b %d, %Y")

filename="${pid_lower}.cpp"

cat <<EOF >"$filename"
/* ${prefix} ${pid_lower} - ${pname}
 * ${curr_date}
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _YES cout << "YES" << "\n"
#define _NO  cout << "NO"  << "\n"

int main(void)
{
EOF

if [[ "$io_opt" =~ ^[Yy]$ ]]; then
  cat <<EOF >>"$filename"
        ios::sync_with_stdio(false);
        cin.tie(NULL);

EOF
fi

cat <<EOF >>"$filename"
        return 0;
}
EOF

echo "File ${filename} created successfully for ${prefix}!"

echo "Select editor to open file:"
echo "        1) vim"
echo "        2) nvim"
echo "        3) VSCode (code)"
echo "        4) nano"
echo "        5) Don't open"
read -p "        Enter choice (1-5): " editor_choice

case $editor_choice in
1 | "vim")
  vim "$filename"
  ;;
2 | "nvim")
  nvim "$filename"
  ;;
3 | "code" | "vscode")
  code "$filename"
  ;;
4 | "nano")
  nano "$filename"
  ;;
5 | "none" | *)
  echo "        File created at: $PWD/$filename"
  ;;
esac
