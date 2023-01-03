//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int N) {

        vector<int>temp;

        temp.push_back(a[0]);

        for(int i=1;i<N;i++)

        {

            if(a[i]>temp.back())

            {

                temp.push_back(a[i]);

            }

            else{

                int idx=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();

                temp[idx]=a[i];

            }

        }

        return N-temp.size();

    }
};
