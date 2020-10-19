struct matrix{
    vector<vector<ll>> mat;
    matrix(int n, int m){
        mat.resize(n,vector<ll>(m));
    }
    matrix operator*(matrix a){
        matrix ans(this->mat.size(),a.mat[0].size());
        for(int i=0;i<this->mat.size();i++){
            for(int j=0;j<a.mat[0].size();j++){
                for(int k=0;k<a.mat.size();k++){
                    ans.mat[i][j]+=this->mat[i][k]*a.mat[k][j];
                    ans.mat[i][j]%=p;
                }
            }
        }
        return ans;
    }
};
matrix matpower(matrix base,ll power){
    matrix ans(base.mat.size(),base.mat.size());
    for(int i=0;i<base.mat.size();i++){
        ans.mat[i][i]=1;
    }
    while(power){
        if(power & 1){
            ans=ans*base;
        }
        base=base*base;
        power>>=1;
    }
    return ans;
}
