class Solution {
public:
    int n;
    vector<vector<int>> Ans;

    void Count(int pos, vector<int> v){
        int left=0, right=n-1;
        while (left<pos && pos<right){
            if (v[left]+v[right]==-v[pos]){
                vector<int> tmp={v[left], v[pos], v[right]};
                Ans.push_back(tmp);
                left++;
            } else if(v[left]+v[right]<-v[pos]) left++;
            else right--;
        }
    }

    vector<vector<int>> threeSum(vector<int>& v) {
        n=v.size();
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++) Count(i, v);
        set<vector<int>> se;
        for (vector<int> tmp:Ans) se.insert(tmp);
        Ans.clear();
        for (vector<int> tmp:se) Ans.push_back(tmp);
        return Ans;
    }
};
