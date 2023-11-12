class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stopToId;
        for(int i=0; i<routes.size(); i++) {
            int id = i;
            vector<int> stops = routes[i];
            for(auto stop : stops) {
                stopToId[stop].push_back(id);
            }
        }

        queue<pair<int, int>> q;
        unordered_map<int, bool> busVis, busStopVis;
        q.push({source, 0});
        busStopVis[source] = true;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int, int> p = q.front();
                q.pop();

                int currStop = p.first;
                int busTravelled = p.second;

                if(currStop == target) {
                    return busTravelled;
                }

                for(auto bus : stopToId[currStop]) {
                    if(!busVis[bus]) {
                        busVis[bus] = true;
                        
                        for(auto busStop : routes[bus]) {
                            if(!busStopVis[busStop]) {
                                busStopVis[busStop] = true;
                                q.push({busStop, busTravelled+1});
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }
};

//  T.C. -> O(N*M)
//  S.C. -> O(N*M)
