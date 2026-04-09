/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startTime, endTime;
        for(auto it : intervals){
            startTime.push_back(it.start);
            endTime.push_back(it.end);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int i = 0, j = 0;
        int rooms = 0, ans = 0;
        while(i < startTime.size()){
            if(startTime[i] < endTime[j]){
                rooms++;
                i++;
            } else {
                rooms--;
                j++;
            }
            ans = max(ans, rooms);
        }
        return ans;
    }
};
