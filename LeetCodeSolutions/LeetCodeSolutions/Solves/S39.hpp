#include <vector>
using namespace std;
class S39 {
    vector<vector<int> >ans;
    vector<int>pa;
    int summ;
    int tar;
    void dfs(int cur,vector<int> &c)
    {
        summ+=c[cur];
        pa.push_back(c[cur]);
        
        if(summ==tar)
        {
            ans.push_back(pa);
        }
        else if(summ<tar)
        {
            for(int i=cur;i<c.size();i++)
            {
                dfs(i,c);
            }
        }
        summ-=c[cur];
        pa.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        summ=0;tar=target;
        for(int i=0;i<candidates.size();i++)
            dfs(i,candidates);
        return ans;
    }
};