#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i=0; i<numbers.size(); i++) {
      if (numbers[i] == 0) {
        answer.push_back(1);
        continue;
      } else if (numbers[i] == 1) {
        answer.push_back(2);
        continue;
      }

      bool found = false;
      for (int j=0; j<=51; j++) {
        if (numbers[i] <= (1ull<<j)) break;
        if (((numbers[i]>>j) & 1) == 0) {
          long long nv = numbers[i] | (1ull << j);
          if (j != 0)
            nv = nv ^ (1ull << (j-1));
          answer.push_back(nv);
          found = true;
          break;
        }
      }
      if (found) continue;

      for (int j=52; 0<=j; j--) {
        if (((numbers[i]>>j)&1) == 1) {
          answer.push_back(numbers[i]^(1ull<<j)^(1ull<<(j+1)));
          break;
        }
      }
    }
    return answer;
}