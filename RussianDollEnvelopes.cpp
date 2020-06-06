class Solution {
public:
    
    vector<pair<int,int>> makepairs(vector<vector<int>> envelopes){
        vector<pair<int,int>> A;
        for(int i=0;i<envelopes.size();i++){
            A.push_back(make_pair(envelopes[i][0],envelopes[i][1]));
        }
        return A;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int max=1;
        vector<pair<int,int>> envs=makepairs(envelopes);
        //Sorting on the basis of first element
        sort(envs.begin(),envs.end());
        //Now, apply Longest Increasing subsequence(O(N log N))
        int M[envs.size()+1];
        int L=0;
        for(int i=0;i<envs.size();i++){
            int lo=1;
            int hi=L;
            while(lo<=hi){
                int mid=ceil((lo+hi)/2);
                if(envs[M[mid]].second < envs[i].second)
                    lo=mid+1;
                else
                    hi=mid-1;
            }
            
            M[lo]=i;
            if(lo>L)
                L=lo;
            
        }
        return L;
    }
};