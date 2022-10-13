/*input
5
30 1T
48 1T
20 2T
45 2T
50 2T
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
  int n;
  cin >> n;
  while(n--) {
    int o, t;
    scanf("%d %dT", &o, &t);
    int ans = o + (t == 2? 45 : 0) - max(0, o-45);
    printf("%d", ans);
    if(o > 45)
      printf("+%d", o-45);
    cout << endl;
  } 
  return 0;
}