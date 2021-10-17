// 삽입정렬 시간재기 문제와 비슷한 문제라서 Fenwick Tree로 풀어보려했는데 잘 안됐음.
// 답보고 정리(https://leetcode.com/contest/weekly-contest-206/problems/check-if-string-is-transformable-with-substring-sort-operations/)
// (https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/discuss/843917/C%2B%2BJavaPython-O(n))
// s (source)의 특정 숫자는 그 앞에 자기보다 큰 숫자가 있으면 앞으로 옮길 수 있고
// 반대로, 작은 숫자가 있으면 옮길 수 없다.
// t (target)의 맨 앞숫자부터 역으로 추적하여 이 숫자가 이 위치에 있을 수 있는지 확인하여 푼다.
// t의 특정 숫자가 그 위치에 있으려면, s상에서 그 숫자 앞에 그 숫자보다 작은숫자가 없어야한다.
// 단, 이미 사용한 숫자는 t상에서 이미 옮겨진 상태이므로 고려안해도된다.
// t를 맨앞부터 훑으면서 이 숫자보다 작은 숫자의 위치가 s상에서 이 숫자보다 왼쪽에 있는지 확인해가면서 풀면 된다.
class Solution {
public:
    bool isTransformable(string s, string t) {
        FenwickTree tree(1000000);
        // ?
    }

};