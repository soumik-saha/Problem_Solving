class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if(n%groupSize!=0) {
            return false;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int h:hand) {
            pq.push(h);
        }

        while(!pq.empty()) {
            vector<int> extra;
            vector<int> curr;
            while(!pq.empty() && curr.size()!=groupSize) {
                if(curr.empty()) {
                    curr.push_back(pq.top());
                }
                else {
                    if(curr.back()+1==pq.top()) {
                        curr.push_back(pq.top());
                    }
                    else {
                        extra.push_back(pq.top());
                    }
                }
                pq.pop();
            }
            if(pq.empty() && curr.size()!=groupSize) {
                return false;
            }
            for(int item:extra) {
                pq.push(item);
            }
        }

        return true;
    }
};
