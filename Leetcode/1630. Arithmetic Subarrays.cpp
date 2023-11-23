class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++) {
            vector<int> temp;
            for(int j=l[i]; j<=r[i]; j++) {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            if(temp.size()>2) {
                int diff = temp[1]-temp[0];
                bool tf = true;
                for(int k=2; k<temp.size(); k++) {
                    if(temp[k]-temp[k-1]!=diff) {
                        tf = false;
                        break;
                    }
                }
                ans.push_back(tf);
            }
            else {
                ans.push_back(true);
            }
        }

        return ans;
    }
};
