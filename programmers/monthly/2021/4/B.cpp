#include <string>
#include <vector>
#include<stack>
#include<algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i=0; i<s.size(); i++) {
      rotate(s.begin(), s.begin() + 1, s.end());
      stack<char> st;
      int j=0;
      for (j=0; j<s.size(); j++) {
          char c = s[j];
          if (c == '[' || c=='{' || c=='(')
            st.push(c);
          else {
            char c2 = st.top();
            st.pop();
            if (!(c2 == '(' && c==')' || c2=='{' && c=='}' || c2=='[' && c==']'))
              break;
          }
      }
      if (st.empty() && j==s.size())
        answer++;
    }
    return answer;
}