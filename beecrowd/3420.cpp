/*input
6
10
15
1234567890
1000000000000
1000000000000000
1000000000000000000
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
typedef unsigned long long ll;
typedef pair<int, int> ii;

ll f(ll n) {
  return n%2==0 ? (n/2) * (n+1) : n * ((n+1)/2);
}

int main(){
  int n;
  cin >> n;
  while(n--) {
    ll c;
    cin >> c;
    ll l = 1, r = 816496581; // ans for 10^18
    ll ans = 0;
    while(l <= r) {
      ll mid = (l+r)/2;
      ll val = f(mid)*2 + f(mid-1);
      
      if(val < c) {
        ans = mid;
        l = mid+1;
      } else if(val > c){
        r = mid-1;
      } else {
        ans = mid;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}