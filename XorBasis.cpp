struct XorBasis{
    private:
    vector<ll> basis;
    int lg;
    int sz = 0;

    public:
    XorBasis(int lg) : lg(lg){
        basis.resize(lg);
    }
    void add(ll x){
        if(x >= (1ll<<lg)) return;
        for(int i=0;i<lg;i++){
            if(~x&(1ll<<i)) continue;
            if(!basis[i]){
                basis[i] = x;
                ++sz;
            }
            x^=basis[i];
        }
    }
    bool contains(ll x){
        for(int i=0;i<lg;i++){
            if(~x&(1ll<<i)) continue;
            if(!basis[i]){
                return false;
            }
            x^=basis[i];
        }
        return true;
    }
    int size(){
        return sz;
    }
    const vector<ll>::iterator begin(){
        return basis.begin();
    }
    const vector<ll>::iterator end(){
        return basis.end();
    }
};
