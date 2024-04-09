class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int timeTaken = 0;

        int i = 0;
        while(tickets[k]!=0) {
            if(tickets[i%n]!=0){
                tickets[i%n]--;
                timeTaken++;
            }
            i++;
        }
        return timeTaken;
    }
};
