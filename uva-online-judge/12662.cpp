/*input
20
? ? A ? ? ? ? ? ? ? ? ? ? ? ? ? B ? ? ?
20
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20


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
  string v[n];
  for(int i = 0; i < n; i++)
    cin >> v[i];
  int q, x;
  cin >> q;
  while(q--){
    cin >> x;
    x--;
    if(v[x] != "?") {
      cout << v[x] << endl;
      continue;
    }

    int left = -1, right = -1;
    string leftC, rightC;

    for(int i = x-1; i >= 0; i--) {
      if(v[i] != "?"){
        left = x - i;
        leftC = v[i];
        break;
      }
    }

    for(int i = x+1; i < n; i++) {
      if(v[i] != "?"){
        right = i - x;
        rightC = v[i];
        break;
      }
    }
    
    if(right == left) {
      printf("middle of %s and %s\n", leftC.c_str(), rightC.c_str());
    } else if((left < right || right == -1) && left != -1) {
      for(int i = 0; i < left; i++) {
        printf("right of ");
      }
      printf("%s\n", leftC.c_str());
    } else {
      for(int i = 0; i < right; i++) {
        printf("left of ");
      }
      printf("%s\n", rightC.c_str());
    }

  }
  return 0;
}