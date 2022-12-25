class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> answer(queries.size(), 0);
        for(int j=0; j<queries.size(); j++){
            int sum = 0;
            for(int i=0; i<nums.size(); i++){
                sum += nums[i];
                if(sum <= queries[j]){
                    answer[j]++;
                }
                else
                    break;
            }
        }
        return answer;
    }
};
