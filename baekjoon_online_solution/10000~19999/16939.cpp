#include<iostream>
#include<vector>
using namespace std;

vector<vector<vector<vector<int>>>> rowcases = 
  {
    {
      {{1,2}, {18, 20}, {11, 12}, {13, 15}},
      {{3,4}, {17, 19}, {9, 10}, {14, 16}}
    },
    {
      {{1,3}, {5, 7}, {9, 11}, {22, 24}},
      {{2,4}, {6, 8}, {10, 12}, {21, 23}}
    },
    {
      {{13,14}, {5, 6}, {17, 18}, {21, 22}},
       {{15,16}, {7, 8}, {19, 20}, {23, 24}}
    }
  };
vector<vector<vector<int>>> planecases = {
  {{5,6,7,8}, {21, 22, 23, 24}},
  {{13,14,15,16}, {17, 18, 19, 20}},
  {{1,2,3,4}, {9, 10, 11, 12}}
};
vector<int> cube(25);

bool solve() {
  for (int caseidx = 0; caseidx<3; caseidx++) {
    auto rs = rowcases[caseidx];
    auto planes = planecases[caseidx];
    bool ok = true;
    for (auto plane: planes) {
      int color = -1;
      for (int cell: plane) {
        if (color == -1)
          color = cube[cell];
        else if (color != cube[cell]) {
          ok = false;
          break;
        }
      }
    }
    if (!ok)
      continue;
    for (int i=0; i<2; i++) {
      ok = true;
      auto r1 = rs[i];
      auto r2 = rs[(i+1)%2];
      for (int j=0; j<4; j++) {
        auto twocell1 = r1[j];
        auto twocell2 = r2[(j+1)%4];
        if (cube[twocell1[0]] != cube[twocell1[1]]
          || cube[twocell2[0]] != cube[twocell2[1]] // inside same
          || cube[twocell1[0]] != cube[twocell2[0]]) { // across same
            ok = false;
            break;
        }
      }
      if (ok)
        return true;
    }
  }
  return false;
}


int main() {
  for (int i=1; i<25; i++)
    cin >> cube[i];
  if (solve())
    cout << 1 << endl;
  else
    cout << 0 << endl;
}
