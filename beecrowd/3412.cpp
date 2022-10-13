/*input
3
Ava Ricela
6.1 8.2 7.1 9.4
Paulo Rotas
9.1 6.2 3.1 9.4
Gersom Atorio
9.0 5.0 7.3 2.0
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
  scanf(" ");
  while(n--) {
    string name;
    getline(cin, name);
    
    string notes, note;
    getline(cin, notes);
    stringstream SS(notes);
    vector<double> allNotes;
    while(SS >> note) {
      allNotes.pb(stod(note));
    }
    if(allNotes.size() == 1) {
      allNotes.pb(0);
    }
    double media = 0;
    if(allNotes.size() <= 3) {
      media = 0;
      for(double x: allNotes) {
        media += x;
      }
      media /= allNotes.size();
    } else {
      sort(allNotes.begin(), allNotes.begin() + 3);
      allNotes[0] = max(allNotes[0], allNotes[3]);
      for(int i = 0; i < 3; i++) {
        media += allNotes[i];
      }
      media /= 3;        
    }
    cout << name << ": " << fixed << setprecision(1) << media << endl;
  }
  return 0;
}