class Solution {
public:
    //Range sum with i,j inclusive,i<=j
    int S(vector<int> s,int i,int j){
        int sum=0;
        for(int k=i;i<=j;k++){
            sum+=s[k];
        }
        return sum;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty())
            return 0;
        //O(nlog n) solution
        vector<int> sums(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sums[i]=sum;
        }
        
        //Store consecutive sums S([0,i]) with index(0-based)
        vector<vector<int>> s;
        vector<int> temp1;temp1.push_back(0);temp1.push_back(0);
            s.push_back(temp1);
        for(int i=1;i<=nums.size();i++){
            vector<int> temp;
            temp.push_back(sums[i-1]);
            temp.push_back(i);
            s.push_back(temp);
        }
        //Sort s on the basis of first element(i.e the consecutive sums)
        sort(s.begin(),s.end());
        
        //Every range [i,j] can be expressed as [0,j]-[0,i]. This is the heart of the solution
        //For every index j in s, we apply two binary searches to get the i<=j such that
        //S([i,j])   lies within [lower,upper]
        
        //Counter for the required ranges(i.e the solution)
        int count=0;
      
        for(int i=0;i<s.size();i++){
            if(!(s[i][1]==0)){
            int l=0;
            int r=s.size()-1;
            int up=INT_MAX;
            while(l<=r){
                int mid=(l+r)/2;
                if(s[i][0]-s[mid][0]>=lower)
                    l=mid+1;
                else
                    r=mid-1;
            }
            up=l;
            
            //Second search for lower bound
            l=0;
            r=s.size()-1;
            int lo=INT_MAX;
            while(l<=r){
                int mid=(l+r)/2;
                if(s[i][0]-s[mid][0]<=upper)
                    r=mid-1;
                else
                    l=mid+1;
            }     
            lo=r;
            
            //Now, we search through the index range(excluded endpoints) (lo,up) (say index is k) and check for corresponding index in sums to see if k<=i
            for(int k=lo+1;k<up;k++){
                if(s[k][1]<s[i][1]){
                    cout<<s[k][1]<<endl;
                    count++;
                }    
            }
            }    
            
        }

        return count;
        
    }
};