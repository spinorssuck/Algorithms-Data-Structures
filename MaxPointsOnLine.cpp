class Solution {
public:

    int maxPoints(vector<vector<int>>& points){
        if (points.size()==0) return 0;
         
        int out = 1;
         
        for (int i=0;i<points.size();i++) {
            int local = 1;
            unordered_map<double,int> m;
            int duplicate = 0;
            for (int j=i+1;j<points.size();j++) {
                 
                double k;
                 
                if (points[i][0] == points[j][0] && points[i][1]==points[j][1]) {
                    duplicate++;
                    continue;
                }
                     
                else if (points[i][0]==points[j][0])
                    k = double(INT_MAX);
                else
                    k = (1.0*(points[j][1]-points[i][1]))/(points[j][0]-points[i][0]);
                     
                if (m.find(k) == m.end()) {
                    m[k] = 2;
                } else 
                    m[k]++;
                
                 
                local = max(local,m[k]);
            }
             
            out = max(out, local + duplicate);
              
        }
        return out;
    }
};