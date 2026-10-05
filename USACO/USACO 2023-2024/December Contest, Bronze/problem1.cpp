// USACO 2023-2024 December Bronze
// Problem 1 - Candy Cane Feast
#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e5;
long long a[NMAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, m, i, j, x, dif, l;
  cin >> n >> m;

  for (i = 0; i < n; i++)
    cin >> a[i];

  for (i = 0; i < m; i++) {
    cin >> x;
    l = j = 0;

    while (j < n && l < x) {
      dif = max(0, (int)min( a[j], 1LL*x ) - l);
      a[j] += dif;
      l += dif;
      j++;
    }

  }
  for (i = 0; i < n; i++)
    cout << a[i] << '\n';

  return 0;
}