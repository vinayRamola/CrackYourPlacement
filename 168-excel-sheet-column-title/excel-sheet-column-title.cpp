class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";
        
        while (columnNumber > 0) {
            columnNumber--;  
            title = char(columnNumber % 26 + 'A') + title;
            columnNumber /= 26;
        }
        
        return title;
    }
};