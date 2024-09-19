class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if(expression.size()==0)    return ans;
        if(expression.size()==1) {
            ans.push_back(stoi(expression));
            return ans;
        }
        if(expression.size()==2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }

        for(int i=0; i<expression.size(); i++) {
            char curr = expression[i];
            if(isdigit(curr))   continue;

            vector<int> left = diffWaysToCompute(expression.substr(0,i));
            vector<int> right = diffWaysToCompute(expression.substr(i+1));

            for(auto l:left) {
                for(auto r:right) {
                    int res = 0;
                    switch(curr) {
                        case '+':
                            res = l+r;
                            break;
                        case '-':
                            res = l-r;
                            break;
                        case '*':
                            res = l*r;
                            break;
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};
