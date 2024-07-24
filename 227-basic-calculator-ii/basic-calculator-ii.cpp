class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        int n = s.length();
        long long currNum=0;
        long long lastNum=0;
        char oper = '+';
        

        int i=0;;
        while(i<n){
            char ch = s[i];

            if(isdigit(ch)){
                currNum = currNum*10 + (ch-'0');
            }

            if((!isdigit(ch) and !isspace(ch)) or i==n-1){
                if(oper=='+'){
                    st.push(currNum);
                }
                else if(oper=='-'){
                    st.push(-currNum);
                }
                else if(oper=='*'){
                    lastNum = st.top();
                    st.pop();
                    st.push(lastNum*currNum);
                }
                else if(oper=='/'){
                    lastNum = st.top();
                    st.pop();
                    st.push(lastNum/currNum);
                }

                currNum=0;
                oper=ch;
            }
            i++;
        }
        long long ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};