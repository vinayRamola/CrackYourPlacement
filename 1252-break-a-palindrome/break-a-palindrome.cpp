class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();

        if(n==1) return "";
        bool flag=false;

        int i=0;
        while(i<n/2){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                flag=true;
                break;
            }
            i++;
        }
        if(!flag){
            palindrome[n-1]='b';
        }
        return palindrome;
    }
};