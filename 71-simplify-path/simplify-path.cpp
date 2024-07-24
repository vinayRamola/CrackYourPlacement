class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> st;

        int i=0;

        while(i<n){
            string temp="";
            while(i<n and path[i]=='/') i++;

            while(i<n and path[i]!='/'){
                temp+=path[i];
                i++;
            }

            if(temp==".."){
                if(!st.empty() and st.top()!= ".."){
                    st.pop();
                }
            } 
            else if(temp!="" and temp!="."){
                st.push(temp);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        // Handle the case where the path is empty (root)
        if (ans.empty()) {
            ans = "/";
        }
        
        return ans;    }
};