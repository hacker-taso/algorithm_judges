// Start from 01:43 AM Feb 5, 2018.
// End at 01:48 AM Feb 5, 2018. 
#include<iostream>
using namespace std;

class Initials {
private:
    public:
    string getInitials(string name) {
        string acronym = string(1, name[0]);
        for (int i=1; i<name.size(); i++) {
            if (name[i] == ' ') {
                acronym+=name[i+1];
            }
        }
        return acronym;
    }
};
 