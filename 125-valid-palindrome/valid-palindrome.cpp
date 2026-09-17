class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        vector<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                char ch = (s[i] - 'A') + 'a';
                st.push_back(ch);
            }

            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                st.push_back(s[i]);
            }

            else{
                continue;
            }
        }

        int i = 0, j = st.size() - 1;
        while(i <= j){
            if(st[i] != st[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};