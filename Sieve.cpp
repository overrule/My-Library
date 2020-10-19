vector<int> primes;
void sieve(const int n){
    vector<bool> prime(n+1, 1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            primes.pb(i);
            for(int j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
}
