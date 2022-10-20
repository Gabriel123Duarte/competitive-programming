/*input
4
00?000
111000
01000011?1?0
001111110010
???1?1
001010
01
10
110001
000000
001110
111111
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;

int main(){
  int tc;
  cin >> tc;
  for(int T = 1; T <= tc; T++){
    int ans;
    string a, b;
    cin >> a;
    cin >> b;
    if(a.size() != b.size()) {
      ans = -1;
    } else {
      int totalOneA = 0, totalOneB = 0, ones = 0;
      for(auto c : a){
        totalOneA += c=='1';
        ones += c=='1';
      }
      for(auto c : b)
        totalOneB += c=='1';
    
      ans = 0;
      for(int i = 0; i < a.size(); i++) {
        if(a[i] == '?') {
          if(b[i] == '1') {
            if(ones < totalOneB) {
              ones++;
              ans++;
              a[i] = '1';
            }
          } 
        }
      }
      for(int i = 0; i < a.size(); i++) {
        if(a[i] == '?') {
          if(ones != totalOneB) {
            ones++;
            a[i] = '1';
          } else {
            a[i] = '0';
          }
          ans++;
        }
      }
        
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
          diff += a[i] != b[i];
        diff -= max(0, totalOneB-ones);
        ans += diff/2;
        sort(all(a));
        sort(all(b));
        // cout << a << " " << b << " " << ans << endl;
        for(int i = 0; i < a.size(); i++) {
          if(a[i] == '0' && b[i] == '1'){
            a[i] = '1';
          }
        }
        ans = a != b ? -1 : ans + max(0, totalOneB-ones);
    }

    printf("Case %d: %d\n", T, ans);
  }
  return 0;
}