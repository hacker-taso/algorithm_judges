// start from 12:24AM, Jan 16, 2018
// complete at 12:39AM, Jan 16, 2018
// First time, I considered using format string.
// But I couldn't find appropriate way.
// I think we can use sprintf http://www.cplusplus.com/reference/cstdio/sprintf/.
#include<iostream>
using namespace std;
class FormatAmt {
    public:
    string amount(int dollars, int cents) {
        string dollarS = to_string(dollars);
        string centS = to_string(cents);
        if (centS.size() == 1) centS = "0" + centS;
        string ret = "." + centS;
        while (!dollarS.empty()) {
            if (dollarS.size() <= 3) {
                ret = dollarS + ret;
                dollarS = "";
            } else {
                ret = "," + dollarS.substr(dollarS.size()-3, 3) + ret;
                dollarS = dollarS.substr(0, dollarS.size()-3);

            }
        }
        ret = "$"+ret;
        return ret;
    }
};
