class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>visi(n,0);
        vector<set<int>>v(n,set<int>());
        if(n<=2)
        {
            if(n==1)
            {
                ans.push_back(0);
            }
            if(n==2)
            {
                ans.push_back(0);
                ans.push_back(1);
            }
            return ans;
        }
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i][0]].insert(edges[i][1]);
            v[edges[i][1]].insert(edges[i][0]);
        }
        vector<int>q;
        
        while(n>2)
        {
            for(int i=0;i<v.size();i++)
            {
                if(v[i].size()==1)
                {
                    q.push_back(i);
                    n--;
                }
               
                
                
            }
            int xx=q.size();
            
           // n=n-xx;
            for(int j=0;j<xx;j++)
            {
                auto it=v[q[j]].begin();
                
                if(n>2)
                {
                    v[*it].erase(q[j]);
                }

                v[q[j]].erase(it);
               // q.erase(q.begin());
                
            }
            q.clear();
            
        }
        
    
    for(int i=0;i<v.size();i++)
    {
        if(v[i].size()!=0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
};
