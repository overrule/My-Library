template<int MAXA>
struct LiChaoTree{
    struct Line{
        ll m,c;
        Line(){}
        Line(ll m,ll c) : m(m), c(c) {}
        ll evaluate(ll x){
            return m*x + c;
        }
    };
    struct Node{
        Line top;
        int left=-1, right=-1;
        Node() {}
        Node(ll m, ll c) : top(Line(m,c)) {}
        Node (Line curr) : top(curr) {}
        ll evaluate(ll x){
            return top.evaluate(x);
        }
    };
    vector<Node> Tree;
    const ll INF = 1e18;
    LiChaoTree(){
        Tree.emplace_back(0,INF);
    }
    void addline(ll m,ll c){
        addline(Line(m,c),0,MAXA+1,0);
    }
    void addline(Line toadd,ll l,ll r,int idx){
        ll mid = (l+r)/2;
        Line& top = Tree[idx].top;
        if(top.evaluate(mid) > toadd.evaluate(mid)){
            swap(top, toadd);
        }
        if(r-l <= 1) return;
        if(top.evaluate(l) > toadd.evaluate(l)){
            if(Tree[idx].left == -1){
                Tree[idx].left = Tree.size();
                Tree.emplace_back(top);
            }
            addline(toadd,l,mid,Tree[idx].left);
        }
        else{
            if(Tree[idx].right == -1){
                Tree[idx].right = Tree.size();
                Tree.emplace_back(top);
            }
            addline(toadd,mid,r,Tree[idx].right);
        }
    }
    ll query(ll x){
        return min(Tree[0].evaluate(x), query(x,0,MAXA+1,0));// * (maximum ? 1 : -1);
    }
    ll query(ll x,ll l,ll r,int idx){
        if(idx==-1) return INF;
        if(x<l || x>=r) return Tree[idx].evaluate(x);
        if(r-l <= 1) return Tree[idx].evaluate(x);
        ll mid = (l+r)/2;
        return min({Tree[idx].evaluate(x), query(x,l,mid,Tree[idx].left), query(x,mid,r,Tree[idx].right)});
    }
};
