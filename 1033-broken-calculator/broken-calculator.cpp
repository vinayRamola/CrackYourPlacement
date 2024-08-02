class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;
        while(target>=startValue){
            if(target==startValue) return operations;
            else if(target%2==1){
                target+=1;
                operations++;
            }
            else{
                if(target<startValue){
                    break;
                }
                target=target/2;
                operations++;
            }
        }
        return operations+=(startValue-target);
    }
};