/*input
3
.*..***.***.
.*....*...*.
.*..***.***.
.*..*.....*.
.*..***.***.
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
  string v[5];
  for(int i = 0; i < 5; i++)
    cin >> v[i];

  for(int i = 0; i < n*4; i += 4) {
    if(v[0][i] == '.'){
      cout << 1;
    } else if(v[3][i] == '*'){
      cout << 2;
    } else {
      cout << 3;
    }
  }
  cout << endl;
  return 0;
}