class Solution {
public:
    vector<int> sieve(int n){
        vector<int> prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }

        for(int i=1;i<=n;i++){
            prime[i] += prime[i-1];
        }

        return prime;
    }
    int nonSpecialCount(int l, int r) {

        int sqrtl = sqrt(l);
        int sqrtr = sqrt(r);

        if((sqrtl*sqrtl)!=l){
            sqrtl++;
        }

        vector<int> prime = sieve(sqrtr);

        int primeNo = prime[sqrtr] - prime[sqrtl-1];
        return (r-l+1) - (primeNo);
    }
};