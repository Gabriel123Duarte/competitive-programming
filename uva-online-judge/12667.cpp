/*input
10 7 6
1 2 J No
2 2 B No
3 3 D Yes
4 7 E Yes
6 5 E Yes
6 6 E Yes

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
  int n, t, m;
  cin >> n >> t >> m;
  int hasTime[n][t];
  memset(hasTime, 0, sizeof(hasTime));
  
  ii ans[n];
  for(int i = 0; i < n; i++){
    ans[i] = {-1, -1};
  }

  while(m--) {
    int time, teamId;
    char problem;
    string verdict;
    cin >> time >> teamId >> problem >> verdict;
    teamId--;
    if(hasTime[problem-'A'][teamId]) 
      continue;
    if(verdict == "Yes") {
      if(time >= ans[problem-'A'].fst) {
        ans[problem-'A'] = {time, teamId+1};
      }
      hasTime[problem-'A'][teamId] = 1;
    }
  }


  for(int i = 0; i < n; i++) {
    printf("%c ", i+'A');
    if(ans[i].fst == -1) {
      printf("- -\n");
    } else {
      printf("%d %d\n", ans[i].fst, ans[i].snd);
    }
  }

  return 0;
}