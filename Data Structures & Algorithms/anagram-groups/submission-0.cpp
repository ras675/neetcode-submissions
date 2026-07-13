class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz=strs.size();
        vector < vector < string > >  ans;
        vector <bool>checked(sz,false);
        vector<string> subans;
        for(int i=0;i<sz;i++){
            if(!checked[i]){
                checked[i]=true;
                subans.push_back(strs[i]);
                for(int j=i+1;j<sz;j++){
                    if(!checked[j] && checkAnagram(strs[i],strs[j])){
                        checked[j]=true;
                        subans.push_back(strs[j]);
                    }
                }ans.push_back(subans);
                subans.clear();
            }
        }
        return ans;
    }
    bool checkAnagram(string s1,string s2){
        if(s1.size()!=s2.size()){
            return false;
        }int arr1[26],arr2[26];
        for(int i=0;i<26;i++){
            arr1[i]=0;
            arr2[i]=0;
        }for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])return false;
        }return true;
    }
};