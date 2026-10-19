#include <bits/stdc++.h>
using namespace std;

int nrcif(long long x) {
  int ret = 0;
  while (x) ret++, x/=10;
  return ret;
}

int main() {
  ifstream cin("odometer.in");
  ofstream cout("odometer.out");
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr); cout.tie(nullptr);

  long long a, b, nr;
  set<long long> ans;
  cin >> a >> b;

  int adig, bdig, ndig, dig, tmpdig, onedig, ponedig;
  string tmp;

  adig = nrcif(a);
  bdig = nrcif(b);

  for (ndig = adig; ndig <= bdig; ndig++) {

    for (dig = 0; dig <= 9; dig++) {

      tmp = "";
      tmpdig = ndig;
      while (tmpdig--)
        tmp.push_back(dig+'0');

      for (ponedig = 0; ponedig < (int)tmp.size(); ponedig++) {
        
        for (onedig = 0; onedig <= 9; onedig++) {
          if (onedig == dig)
            continue;
          
          tmp[ponedig] = onedig+'0';
          if (tmp[0] != '0') {
            // the set isnt really needed after this check
            nr = stoll(tmp);

            if (a <= nr && nr <= b) {
              ans.insert(nr);
              
            }
          }
          tmp[ponedig] = dig+'0';
        }

      }

    }

  }

  cout << (int)ans.size() << '\n';

  return 0;
}
