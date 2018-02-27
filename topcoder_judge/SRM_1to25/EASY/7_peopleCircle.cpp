// start from 11:03PM, Jan 14, 2018
// complete at 11:42PM, Jan 14, 2018
// Retrospection: I took too much time on this problem.
// First time, I misunderstood the problem.
// I think if I read example first, I didn't misunderstand.
#include<iostream>
#include<vector>
using namespace std;
class PeopleCircle {
    public:
    string order(int numMales, int numFemales, int K) {
        int numPeople = numMales + numFemales;
        vector<char> people(numPeople, -1);
        int peopleIdx=-1;
        const int numMove = K;
        for (int i=0; i<numFemales; i++) {
            for (int j=0; j<numMove;) {
                peopleIdx = (1+peopleIdx)%numPeople;
                if (people[peopleIdx%numPeople] != -1) {
                    continue;
                }
                j++;
            }
            people[peopleIdx] = 'F';
        }
        for (int i=0; i<numPeople; i++) {
            if (people[i] == -1)
                people[i] = 'M';
        }
        return string(people.begin(), people.end());
    }
};
