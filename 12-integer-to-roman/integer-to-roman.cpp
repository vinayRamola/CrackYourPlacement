class Solution {
public:
    int search(vector<int> value,int num){
        int id=-1;
        for(int i=value.size()-1;i>=0;i--){
            if(value[i]<=num) id=i;
        }
        return id;
    }
    string intToRoman(int num) {
        string ans = "";
        vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        while(num>0){
            int id = search(value,num);
            int count = num/value[id];
            num -= value[id]*count; 

            while(count--){
                ans+=symbol[id];
            }

        }
        return ans;
    }
};