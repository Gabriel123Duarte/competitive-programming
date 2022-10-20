/*input
7
3
6
7
8
9
10
1000000000000000000
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;

ll f(ll n) {
  return n&1 ? n*((n+1)/2) : n/2 * (n+1);
}

int main(){
  int n;
  cin >> n;
  while(n--) {
    ll v;
    cin >> v;
    ll ans = 0;
    ll l = 0, r = 1e9;
    while(l <= r) {
      ll mid = (l+r)/2;
      ll val = f(mid);
      if(val <= v) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}