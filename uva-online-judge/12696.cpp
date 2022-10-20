/*input
4
51.23 40.12 21.20 3.45
60.00 30.00 20.00 7.00
52.03 41.25 23.50 7.01
50.00 45.00 30.10 6.02
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
  int cnt = 0;
  while(n--) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a <= 56 && b <= 45 && c <= 25 || (a+b+c) <= 125) && d <= 7) {
      cout << "1\n";
      cnt++;
    } else {
      cout << "0\n";
    }
  }
  cout << cnt << endl;
  return 0;
}