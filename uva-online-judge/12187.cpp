/*input
3 4 4 3
0 1 2 0
1 0 2 0
0 1 2 0
0 1 2 2
4 2 3 4
1 0 3
2 1 2
8 4 2 1
0 7
1 6
2 5
3 4
0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;

int n, r, c, k;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool in(int i, int j) {
  return !(i < 0 || i >= r || j < 0 || j >= c);
}

int main(){
  
  while(cin >> n >> r >> c >> k, n+r+c+k) {
    int grid[r][c], aux[r][c];
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        cin >> grid[i][j];


    while(k--) {
      memset(aux, 0xff, sizeof(aux));
      for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
          if(aux[i][j] == -1)
            aux[i][j] = grid[i][j];
          for(int x = 0; x < 4; x++) {
            int ni = i+dx[x], nj = j+dy[x];
            if(in(ni, nj)) {
              if((grid[i][j]+1)%n == grid[ni][nj])
                aux[ni][nj] = grid[i][j];
            }
          }
        }

      for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) 
          grid[i][j] = aux[i][j];
    }

    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(j) cout << " ";
        cout << grid[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}