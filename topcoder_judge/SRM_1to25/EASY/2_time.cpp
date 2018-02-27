// start from 10:18PM, Jan 13, 2018
// complete at 10:28PM, Jan 13, 2018
#include<iostream>
#include<string>
using namespace std;
class Time {
    public:
    string whatTime(int seconds) {
        int h=seconds/3600;
        seconds -= h*3600;
        int m=seconds/60;
        seconds -= m*60;
        int s = seconds;
        string hs = to_string(h);
        string ms = to_string(m);
        string ss = to_string(s);
        return hs + ":" + ms + ":" + ss;
    }
};
