class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int sz=nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<sz;i++){
            um[nums[i]]++;}
            priority_queue<pair<int,int> >pq;
            for(auto it:um){
                pq.push(make_pair(it.second,it.first));
            }for(int i=0;i<k;i++){
                ans.push_back(pq.top().second);
                pq.pop();
            }return ans;
        }
    
};
