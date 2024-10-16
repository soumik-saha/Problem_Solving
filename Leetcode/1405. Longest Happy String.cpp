class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int, char>> pq;
        if(a!=0)    pq.push({a, 'a'});
        if(b!=0)    pq.push({b, 'b'});
        if(c!=0)    pq.push({c, 'c'});

        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();

            if(ans.size()>=2){
                string x = ans.substr(ans.size()-2);
                if((x=="aa" && tp.second=='a') || (x=="bb" && tp.second=='b') || (x=="cc" && tp.second=='c')) {
                    pair<int, char> tp2;
                    if(!pq.empty()){ 
                        tp2 = pq.top();
                        pq.pop();
                    }
                    else    return ans;
                    ans.push_back(tp2.second);
                    if(tp2.first-1>0)
                        pq.push({tp2.first-1, tp2.second});
                    
                    pq.push({tp.first, tp.second});
                }
                else {
                    ans.push_back(tp.second);
                    if(tp.first-1>0)
                        pq.push({tp.first-1, tp.second});
                }
            }
            else {
                ans.push_back(tp.second);
                if(tp.first-1>0)
                    pq.push({tp.first-1, tp.second});
            }
        }

        return ans;
    }
};
