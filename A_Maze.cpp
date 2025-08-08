#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int n, m, k;
vector<string> grid;
vector<vector<bool>> vis;
vector<pair<int, int>> order;

void dfs(int x, int y) {
  vis[x][y] = true;
  order.push_back({x, y});
  for (int i = 0; i < 4; i++) {
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == '.')
      dfs(nx, ny);
  }
}

void solve() {
  cin >> n >> m >> k;
  grid.resize(n);
  for (int i = 0; i < n; i++) cin >> grid[i];
  vis.assign(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        dfs(i, j);
        goto done;
      }
    }
  }
  done:
    for (int i = 0; i < k; i++) {
      auto [x, y] = order[order.size() - 1 - i];
      grid[x][y] = 'X';
    }
    for (auto &s : grid) cout << s << '\n';
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  // int t;
  // cin >> t;
  // while(t--)
  solve();
}