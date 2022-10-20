/*input
3 0
a
b
c

5 4
a
b
c
d
e
b a
c a
b c
c b

0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;

#define maxn 300100
int p[maxn], sz[maxn];

int find(int i) {
  return p[i] == i ? i : p[i] = find(p[i]);
}

void merge(int i, int j) {
  p[find(i)] = p[find(j)];
}

int main(){
  int c, r;
  while(cin >> c >> r, c+r) {
    map<string, int> mp;
    string u, v;
    for(int i = 0; i < c; i++) {
      p[i] = i;
      cin >> u;
      mp[u] = i;
    }
    memset(sz, 0, sizeof sz);
    while(r--){
      cin >> u >> v;
      merge(mp[u], mp[v]);
    }
    for(int i = 0; i < c; i++)
      sz[find(i)]++;
    
    cout << *max_element(sz, sz+c) << endl;
    
  }
  return 0;
}