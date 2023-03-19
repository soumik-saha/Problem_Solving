vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_map<int,int> left,right;
        if(N==1) return {0};
        if(N==2) return{-1,0};
        
        for(int i=0;i<N;i++){
            right[A[i]]++;
        }
        vector<int> v;
        
        int i=0;
        while(i<N){
            right[A[i]]--;
            if(right[A[i]]==0) right.erase(A[i]);
            v.push_back(left.size()-right.size());
            left[A[i]]++;
            i++;
        }
        return v;
    }
