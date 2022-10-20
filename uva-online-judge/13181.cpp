/*input
.X.X.
.X...X.
.X....X.
...X
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
  string s;
  while(cin >> s) {
    s = "." + s + ".";
    int n = s.size();
    int left[n], right[n];
    left[0] = 1<<30;
    right[n-1] = 1<<30;
    for(int i = 1; i < n; i++) {
      if(s[i] == 'X')
        left[i] = 0;
      else {
        if(s[i-1] == '.')
          left[i] = left[i-1] + 1;
        else
          left[i] = 0;
      }
    }

    for(int i = n-2; i >= 0; i--) {
      if(s[i] == 'X')
        right[i] = 0;
      else {
        if(s[i+1] == '.')
          right[i] = right[i+1] + 1;
        else 
          right[i] = 0;
      }
    }
    int ans = 0;
    for(int i = 1; i < n-1; i++)
      ans = max(ans, min(left[i], right[i]));
    cout << ans << endl;
  }
  return 0;
}