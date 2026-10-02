class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }

            else{
                if(st.empty()){
                    return false;
                }
                
                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }

                else if(st.top() == '{' && s[i] == '}'){
                    st.pop();
                }

                else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                }

                else{
                    return false;
                }
            }
        }

        return st.empty();
    }

    void solve(int n, vector<string>& ans, string temp){
        if(n == 0){
            if(isValid(temp)){
                ans.push_back(temp);
            }
            return;
        }

        solve(n-1, ans, temp + '(');
        solve(n-1, ans, temp + ')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(2*n, ans, "");

        return ans;
    }
};