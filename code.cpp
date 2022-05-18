//https://codeforces.com/contest/1117/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define rsrtl(v) sort(v.begin(), v.end(), greater<ll>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
#define srt(v) sort(v.begin(), v.end())
#define pb push_back
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(),(x).end()
#define ll long long
ll md = 1000000007;
#define theartofwar                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define F first
#define S second
#define sz(v) v.size()
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b){
    T c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m);
        m = (m * m), b /= 2;
    }
    return c;
}
template <typename T>
T ceel(T a, T b){
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
template <typename T>
T my_log(T n, T b){
    T i = 1, ans = 0;
    while (1){
        if (i > n){
            ans--;
            break;
        }
        if (i == n) break;
        i *= b, ans++;
    }
    return ans;
}
template <typename T>
T gcd(T a, T b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll pwmd(ll a, ll b){
    ll c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
ll modinv(ll n){
    return pwmd(n, md - 2);
}
ll inverse(ll i){
    if (i == 1)
        return 1;
    return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return (a.second < b.second);
}
vector<vll> mat_mul(vector<vll>& M1, vector<vll>& M2){
    ll n1 = M1.size(), m1 = M1[0].size(); 
    ll n2 = M2.size(), m2 = M2[0].size(); 
    vector<vll> ans(n1, vll(m2));
    fll(i, 0, n1){
        fll(j, 0, m2){
            fll(o, 0, n2){
                ans[i][j] = (ans[i][j] + (M1[i][o] * M2[o][j]) % md) % md;
                ans[i][j] = (ans[i][j] + md) % md;
            }
        }
    }
    return ans;
}
vector<vll> mat_pow(vector<vll>& M, ll n){
    ll sz = M.size();
    if (n == 0)
    {
        vector<vll> r(sz, vll(sz));
        for (int i = 0; i < sz; i++) r[i][i] = 1;
        return r;
    }
    vector<vll> u = mat_pow(M, n/2);
    u = mat_mul(u, u);
    if (n % 2 == 1) u = mat_mul(u, M);  
    return u;
}
int main()
{
    theartofwar;
    ll n, m;
    cin >> n >> m;
    if (n == 1){
        cout << "1";
        return 0;
    }
    vector<vector<ll>> M(m, vector<ll>(m));
    M[0][0] = M[0][m - 1] = 1;
    M[1][0] = 1;
    fll(i, 2, m) M[i][i - 1] = 1;
    vector<vll> T(m, vll(1));
    fll(i, 0, m) T[i][0] = 1;
    T[0][0] = 2;
    if (n <= m){
        cout << T[m - n][0];
        return 0;
    }
    vector<vll> fans = mat_pow(M, n - m);
    fans = mat_mul(fans, T);
    cout << fans[0][0];
}
