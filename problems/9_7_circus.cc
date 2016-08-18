#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
//(65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)

typedef pair<int, int> Circus;
bool compare(const Circus& c1, const Circus& c2) { return c1.first < c2.first; }

void PrintCircus(const vector<Circus>& c) {
  for (vector<Circus>::const_iterator it = c.begin(); it != c.end(); ++it) {
    cout << "(" << it->first << ", " << it->second << ")";
    if (it + 1 == c.end()) {
      cout << endl;
    }
  }
}
void ValidateCircus(vector<Circus>* c) {
  sort(c->begin(), c->end(), compare);
  for (vector<Circus>::const_iterator it = c->begin(); (it + 1) != c->end();
       ++it) {
    if (it->second > (it + 1)->second) {
      c->erase(it);
    }
  }
}

int main() {
  vector<Circus> circuses;
  Circus c(65, 120);
  circuses.push_back(c);
  c = make_pair(70, 150);
  circuses.push_back(c);
  c = make_pair(56, 90);
  circuses.push_back(c);
  c = make_pair(75, 190);
  circuses.push_back(c);
  c = make_pair(60, 95);
  circuses.push_back(c);
  c = make_pair(68, 110);
  circuses.push_back(c);

  PrintCircus(circuses);
  ValidateCircus(&circuses);
  cout << circuses.size() << " circuses are valid." << endl;
  PrintCircus(circuses);
  return 0;
}