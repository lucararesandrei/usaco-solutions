#include <bits/stdc++.h>
using namespace std;

map<int,int> fx, fy;
vector<pair<int,int>> poz;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (fx[a.first] != fx[b.first])
        return fx[a.first] > fx[b.first];
    return fy[a.second] > fy[a.second];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int n, i, x, y;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        poz.push_back({x,y});
        fx[x]++;
        fy[y]++;
    }

    sort(poz.begin(), poz.end(), cmp);
    int cnt = 0;
    set<int> cvx, cvy;
    for (i = 0; i < n; i++) {
        if (cvx.find(poz[i].first) == cvx.end() && cvy.find(poz[i].second) == cvy.end()) {
            cnt++;
            if (fx[poz[i].first] >= fy[poz[i].second])
                cvx.insert(poz[i].first);
            else
                cvy.insert(poz[i].second);
        }
    }
    if (cnt <= 3)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;

}
