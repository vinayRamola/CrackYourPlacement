class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            char ch = s[i];

            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else if(st.empty() and (ch=')' || ch=='}' || ch==']')) return false;
            else if((ch==')' and st.top()=='(')|| (ch=='}' and st.top()=='{') || (ch==']' and st.top()=='[')) st.pop();
            else return false; 
        }
        return st.empty();
    }
};