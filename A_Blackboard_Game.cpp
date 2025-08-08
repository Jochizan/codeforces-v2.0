#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

void solve() {
  int n;
  cin >> n;
  cout << (n % 3 == 0 && n > 3 ? "Bob" : "Alice") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}