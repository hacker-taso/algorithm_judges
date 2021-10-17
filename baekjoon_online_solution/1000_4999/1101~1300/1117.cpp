// 문제 잘못읽음
// 1. 좌우로 여러번 접는줄
// 2. 오른쪽넘어가게 접힐 수 있는줄 모름
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
#include<map>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
long long W, H, f, c;
long long x1, y1, x2, y2;
void init() {
  cin >> W >> H;
  cin >> f >> c;
  cin >> x1 >> y1 >> x2 >> y2;
}

long long solve() {
  long long nw = W - f; // 0~f: horifold*vertifold
  long long horifold = 2;
  long long nh = H / (c+1);
  long long vertifold = c+1;
  // horifold * vertifold or vertifold 
  long long colorh = y2-y1;
  long long bigw = 0, smallw = 0;
  f = min(W-f, f);
  if (f <= x1) {
    smallw = x2-x1;
  } else if (x2 <= f) {
    bigw = x2-x1;
  } else {
    bigw = f-x1;
    smallw = x2-f;
  }
  return W*H - (vertifold * horifold * bigw * colorh + vertifold * smallw * colorh);
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() << endl;
}
