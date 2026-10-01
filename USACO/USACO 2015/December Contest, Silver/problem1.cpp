// USACO 2015 December Silver
// Problem 1 - Switching on the lights
#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100;
vector<pair<int,int>> s[NMAX+2][NMAX+2];
int a[NMAX+2][NMAX+2], viz[NMAX+2][NMAX+2], n;

int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int R(int i, int j) {
    int cnt = 0, d, idx;
    viz[i][j] = 1;
    for (idx = 0; idx < (int)s[i][j].size(); idx++) {
        int x = s[i][j][idx].first, y = s[i][j][idx].second;
        if (a[x][y] == 0)
            cnt++;
        a[x][y] = 1;
    }

    for (d = 0; d < 4; d++) {
        int tmpi = i+dx[d], tmpj = j+dy[d];
        if (a[tmpi][tmpj] == 1 && viz[tmpi][tmpj] == 0)
            cnt += R(tmpi,tmpj);
    }

    return cnt;
}

int main() {

    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    ios_base::sync_with_stdio(0);
    fin.tie(nullptr); fout.tie(nullptr);

    int m, i, j, x1, y1, x2, y2, cnt;
    fin >> n >> m;

    a[1][1] = 1;
    for (i = 0; i < m; i++) {
        fin >> x1 >> y1 >> x2 >> y2;
        s[x1][y1].push_back({x2, y2});
    }

    cnt = 1;
    while (cnt != 0) {
        memset(viz, 0, sizeof(viz));
        cnt = R(1, 1);
    }

    cnt = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cnt += a[i][j];
        }
    }

    fout << cnt << '\n';

    fin.close();
    fout.close();

    return 0;
}

