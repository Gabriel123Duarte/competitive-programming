/*input
10 3
1 1:33:298 1:34:545 1:33:909 
16 1:34:878 1:34:001 1:33:897
11 1:35:309 1:35:091 1:34:981
63 1:35:109 1:34:671 1:34:988
55 1:36:001 1:35:450 1:34:545
44 1:36:500 1:36:871 1:35:020
4 1:36:381 1:36:209 1:35:345
31 1:37:340 1:36:999 1:35:988
77 1:38:987 1:37:209 1:36:091
14 1:33:298 1:34:545 1:33:909 
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;

struct st{
  int id, total, best, timeBest;
};

bool operator<(const st &a, const st &b) {
  return a.total < b.total;
}

int convert(string s) {
  int id = 0;
  int num = 0;
  int ans = 0;
  for(auto c : s){
    if(c == ':') {
      if(id == 0) {
        ans += 60*1000*num;
      } else {
        ans += 1000*num;
      }
      num = 0;
      id++;
    } else{
      num = num*10 + (c-'0');
    }
  }
  return ans + num;

}

int main(){
  int n, v;
  scanf("%d %d", &n, &v);
  
  int id, m, s, ms;
  int best = 1<<30;
  st pilots[n];
  string aux;
  for(int i = 0; i < n; i++) {
    scanf("%d ", &pilots[i].id);
    
    pilots[i].total = 0;
    pilots[i].best = 1<<30;

    getline(cin, aux);
    stringstream ss(aux);
    string value;
    while(ss >> value){
      int val = convert(value);
      pilots[i].total += val;
      if(val < pilots[i].best) {
        pilots[i].timeBest = pilots[i].total;
        pilots[i].best = val;
      }
    }
    best = min(best, pilots[i].best);
  }

  

  sort(pilots, pilots+n);
  int lessTBest = 1<<30;
  int idAns = -1;

  set<int> topTen;
  for(int i = 0; i < n && topTen.size() < 10; i++) {
    topTen.insert(pilots[i].total);
  }

  for(int i = 0; i < n; i++){
    if(topTen.find(pilots[i].total) != topTen.end() && pilots[i].best == best) {
      if(pilots[i].timeBest < lessTBest){
        lessTBest = pilots[i].timeBest;
        idAns = pilots[i].id;
      }
    }
  }
  if(idAns != -1) {
    printf("%d\n", idAns);
  } else {
    puts("NENHUM");
  }
  
  return 0;
}