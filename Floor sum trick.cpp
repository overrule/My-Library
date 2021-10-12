ll floorsum(ll n,ll l, ll r){
    if(l == r){
        return n/l;
    }
    if(r - l == 1){
        return n/l + n/r;
    }
    if(n/l == n/r){
        return (r - l + 1) * (n/l);
    }
    ll mid = (l + r)/2;
    return floorsum(l, mid) + floorsum(mid + 1, r);
}
