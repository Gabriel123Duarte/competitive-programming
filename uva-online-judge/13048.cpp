/*input
2
-S-S-S-S-S-S-S-S-S-
-S-S-S-S-S-S-S-S-S
-SSSSSSS-SSSSSSSS-
-S-S-S-S-S-S-S-S-S-
-S--S--S--S--S--S--S--S--S-
-S---B-S---B-S---B-S--B-S---B-S---B-S---B-S---BS-
--BSD--BSD--BSD--BSD-S---BDS--S--D--BSD--BDS-
-B-S-D--B-S-D--B-S-D--B-S-D-B--S-D-B--S-D--B-S-D-
--S--B--S--B--D--B--S--B--
DBS--S--B--D--B--S--BDS
-DBS--DBS--D-DBS--S--BDS-
-BBS--BDS--D-BBS--BS--BSS-
-S--SBS--BDS--BDD--SSB--BBS--DBD--SDD--DBB--SDS--
-B-DS--DB--SD--BD--SB--SS--DD--BB--S-
DSS-B-S-D---BSSD-DBSS--SSBD--DBSBDS--S-D-B-
D
-S-
--B-
--B-S-
D--B-S-D
S--D-B-S
D-----
--------D
S-----
--------S
B-----
--------B
S-----B
S-DDD---BD--B
BBBB-----SSSS
SSSS-----BBBB
SSSS--DDDD---BBBB

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
  int t;
  cin >> t;
  int TC = 1;
  while(t--) {
    string s;
    cin >> s;

    int n = s.size();
    s = "+" + s + "++";
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      if(s[i] != '-')
        continue;
      if(s[i-1] == 'S' || s[i+1] == 'S' || s[i+1] == 'B' || s[i+2] == 'B')
        continue;

      ans++;
    }
    printf("Case %d: %d\n", TC++, ans);
  }
  
  return 0;
}