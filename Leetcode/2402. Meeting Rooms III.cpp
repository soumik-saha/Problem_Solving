class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> room_availability_time(n, 0);
        vector<int> meeting_count(n, 0);
        sort(meetings.begin(), meetings.end());

        for(auto& meeting:meetings) {
            int start = meeting[0], end = meeting[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;

            for(int i=0; i<n; i++) {
                if(room_availability_time[i]<=start) {
                    foundUnusedRoom = true;
                    meeting_count[i]++;
                    room_availability_time[i] = end;
                    break;
                }

                if(minRoomAvailabilityTime > room_availability_time[i]) {
                    minRoomAvailabilityTime = room_availability_time[i];
                    minAvailableTimeRoom = i;
                }
            }

            if(!foundUnusedRoom) {
                room_availability_time[minAvailableTimeRoom] += end - start;
                meeting_count[minAvailableTimeRoom]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingRoom = 0;
        for(int i=0; i<n; i++) {
            if(meeting_count[i]>maxMeetingCount) {
                maxMeetingCount = meeting_count[i];
                maxMeetingRoom = i;
            }
        }

        return maxMeetingRoom;
    }
};
