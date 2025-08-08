#include <bits/stdc++.h>
using namespace std;

#define ar array
const int INF = 1e9;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = "L" + s + "L";  // agregar orillas

  vector<int> min_swim(n + 2, INF);
  deque<ar<int, 2>> q;

  min_swim[0] = 0;
  q.push_front({0, 0});  // pos, swim

  while (!q.empty()) {
    auto [pos, swim] = q.front(); q.pop_front();
    if (s[pos] == 'C') continue;

    // Ya no podemos nadar
    if (swim > k) continue;

    // Ya llegamos
    if (pos == n + 1) {
      cout << "YES\n";
      return;
    }

    // Si estamos en el agua, solo nadamos 1 adelante
    if (s[pos] == 'W') {
      if (s[pos + 1] != 'C' && swim + 1 < min_swim[pos + 1]) {
        min_swim[pos + 1] = swim + 1;
        q.push_back({pos + 1, swim + 1});
      }
    } else {
      // Estamos en la orilla o tronco, saltamos
      for (int j = 1; j <= m; j++) {
        int nxt = pos + j;
        if (nxt > n + 1) break;
        if (s[nxt] == 'C') continue;
        if (swim < min_swim[nxt]) {
          min_swim[nxt] = swim;
          q.push_front({nxt, swim});  // sin nadar
        }
      }
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) solve();
}
