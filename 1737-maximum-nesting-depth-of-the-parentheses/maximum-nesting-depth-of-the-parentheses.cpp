class Solution {
public:
    int maxDepth(string s) {
        int ans=0,curr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                ans++;
            }
            else if(s[i]==')'){
                ans--;
            }
            curr=max(curr,ans);
        }
        return curr;
    }
};