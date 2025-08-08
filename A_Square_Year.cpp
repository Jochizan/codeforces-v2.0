#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

void solve() {
  int year;
  cin >> year;

  double a = sqrt(year);
  double b = (int) sqrt(year);
  if (b != a) {
    cout << -1 << '\n';
    return;
  }

  cout << b << " " << 0 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}