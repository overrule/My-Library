template<typename T>
struct RangeUpdate{ //requires commutativity and associativity
    int n;
    vector<T> segtree;
    function<T(const T&, const T&)> join;
    T base;
    RangeUpdate(int n, function<T(const T&,const T&)> join, T base) : n(n), join(join), base(base){
        segtree.resize(n<<1, base);
    }
    RangeUpdate(vector<T> &seq, function<T(const T&,const T&)> join, T base) : n(seq.size()), join(join), base(base){
        segtree.resize(n<<1, base);
        for(int i=0;i<n;i++){
            segtree[n+i] = seq[i];
        }
    }
    T query(int pos){
        pos+=n;
        T ans = segtree[pos];
        pos>>=1;
        while(pos){
            ans = join(ans, segtree[pos]);
            pos>>=1;
        }
        return ans;
    }
    void update(int l,int r,T val){
        l+=n;
        r+=n+1;
        while(l < r){
            if(l&1){
                segtree[l] = join(segtree[l], val);
                ++l;
            }
            if(r&1){
                --r;
                segtree[r] = join(segtree[r], val);
            }
            l>>=1;
            r>>=1;
        }
    }
};
