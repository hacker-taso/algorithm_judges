#include <string>
#include <vector>

using namespace std;

int countDiv(int n) {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (n%i == 0)
            cnt++;
    }
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i=left; i<=right; i++) {
        if (countDiv(i)%2 == 0) {
            answer += i;
        } else {
            answer -= i;
        }
    }
    return answer;
}