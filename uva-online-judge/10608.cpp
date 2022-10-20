/*input
1
10 5
1 2
2 3
4 5
5 7
3 4
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
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
      p[i] = i;

    memset(sz, 0, sizeof(sz));
    int u, v;
    while(m--) {
      cin >> u >> v;
      merge(u-1, v-1);
    }
    for(int i = 0; i < n; i++)
      sz[find(i)]++;
    
    cout << *max_element(sz, sz+n) << endl;
  }
  return 0;
}