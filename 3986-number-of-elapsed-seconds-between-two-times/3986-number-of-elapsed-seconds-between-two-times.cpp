class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {

        int sh = stoi(startTime.substr(0,2));
        int sm = stoi(startTime.substr(3,2));
        int ss = stoi(startTime.substr(6,2));

        int eh = stoi(endTime.substr(0,2));
        int em = stoi(endTime.substr(3,2));
        int es = stoi(endTime.substr(6,2));

        int hours = eh - sh;
        int minutes = em - sm;
        int seconds = es - ss;

        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }

        if (minutes < 0) {
            minutes += 60;
            hours--;
        }

        return hours * 3600 + minutes * 60 + seconds;
    }
};