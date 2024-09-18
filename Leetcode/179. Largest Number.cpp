class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto ele:nums) {
            v.push_back(to_string(ele));
        }
        sort(v.begin(), v.end(), [&](string a, string b) {
            return a+b>b+a;
        });
        string x;
        for(auto s:v) {
            x += s;
        }
        int i=0;
        while(i<x.size() && x[i]=='0') {
            i++;
        }
        x = x.substr(i);
        if(x=="")
           x="0";
        return x;
    }
};
