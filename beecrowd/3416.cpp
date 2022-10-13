/*input
15 3 250
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
  int n, l, d;
  cin >> n >> l >> d;
  cout << ceil((n*d)/(l*1000.0))*l << endl;
  return 0;
}