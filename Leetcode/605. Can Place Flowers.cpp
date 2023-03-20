class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int x) {
        int cnt = 0, n = flowerbed.size();
        if(n==1 && flowerbed[0]==0){
            cnt++;
            if(x<=cnt)
                return true;
            else
                return false;
        }
        for(int i=0; i<n; i++) {
            if(flowerbed[i]==0){
                if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    cnt++;
                }
                else if(i!=0 && i!=n-1 && i+2<n && flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i+2]==0){
                    flowerbed[i+1]=1;
                    cnt++;
                }
                else if(i==n-1 && i-1>=0 && flowerbed[i]==0 && flowerbed[i-1]==0){
                    cnt++;
                    flowerbed[i]=1;
                }
            }
        }
        if(cnt>=x)
            return true;
        else
            return false;
    }
};
