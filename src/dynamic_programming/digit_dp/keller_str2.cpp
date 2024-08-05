//
// Created by Jiang Yinzuo on 2020/12/16.
//
#include <cstdio>
#include <iostream>
#include <algorithm>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)

using namespace std;

typedef long long ll;
const int N=1e7+10,P=998244353;
int n,fac[N],ifac[N];ll ans,mul;

int ksm(int a,int b){
    int ans=1;
    for(; b; b >>= 1, a = 1ll*a*a%P)
        if(b&1) ans = 1ll*ans*a%P;
    return ans;
}

void pre(int n){
    fac[0] = 1; rep(i, 1, n) fac[i] = 1ll*fac[i-1]*i%P;
    ifac[n] = ksm(fac[n], P-2);
    per(i, n, 1) ifac[i-1] = 1ll*ifac[i]*i%P;
}

int C(int n, int k) {return 1ll*fac[n]*ifac[k]%P*ifac[n-k]%P;}

int main(){
    scanf("%d", &n); pre(n);
    ans = ksm(3, n); mul = 2;
    rep(i, 0, n/2-1) ans -= mul*C(n,i)%P;mul=mul*2%P;
    ans %= P; if(ans < 0) ans += P;
    printf("%lld\n", ans);
    return 0;
}
