#include <bits/stdc++.h>
#define ll long long
ll md = 1000000007;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pb push_back
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
using namespace std;
//using namespace std::chrono;
template <typename T>
T pw(T a, T b)
{
    T c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m);
        m = (m * m), b /= 2;
    }
    return c;
}
template <typename T>
T ceel(T a, T b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
template <typename T>
T my_log(T n, T b)
{
    T i = 1, ans = 0;
    while (1)
    {
        if (i > n)
        {
            ans--;
            break;
        }
        if (i == n)
            break;
        i *= b, ans++;
    }
    return ans;
}
template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <typename T>
T mysqt(T a)
{
    T ans = 1;
    while (ans * ans <= a)
        ans++;
    ans--;
    return ans;
}
ll pwmd(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
ll modinv(ll n)
{
    return pwmd(n, md - 2);
}
ll inverse(ll i)
{
    if (i == 1)
        return 1;
    return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    return (a.second < b.second);
}
/* auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: "
         << duration.count()<< "ms" <<"\n";*/
vector<char> capl = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> sml = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
template <typename T>
string conv(T a)
{
    string b;
    T e = 2;
    T c = my_log(a, e);
    c++, b = '1';
    for (T i = 0; i < c - 1; i++)
    {
        T k = a >> (c - 2 - i);
        if (k & 1)
            b += '1';
        else
            b += '0';
    }
    if (a == 0)
        return "0";
    return b;
}
vector<vll> mat_mul(vector<vll> M1, vector<vll> M2, ll n1, ll m1, ll n2, ll m2){
    vector<vll> ans(n1, vll(m2));
    fll(i, 0, n1){
        fll(j, 0, m2){
            fll(o, 0, n2){
                ans[i][j] = (ans[i][j] + (M1[i][o] * M2[o][j]) % md) % md;
            }
        }
    }
    return ans;
}
vector<vll> mat_pow(vector<vll> M, ll n, ll sz){
    if (n == 0)
    {
        vector<vll> r(sz, vll(sz));
        for (int i = 0; i < sz; i++) r[i][i] = 1;
        return r;
    }
    vector<vll> u = mat_pow(M, n/2, sz);
    u = mat_mul(u, u, sz, sz, sz, sz);
    if (n % 2 == 1) u = mat_mul(u, M, sz, sz, sz, sz);  
    return u;
}
int main()
{
    fast;
    vector<vll> v;
    fll(i, 0, 6){
        vll p;
        v.pb(p);
        fll(j, 0, 6){
            if (i == 0) v[i].pb(1);
            else{
                if (j == i - 1) v[i].pb(1);
                else v[i].pb(0);
            }
        }
    }
    ll n;
    cin >> n;
    vector<vll> T(6, vll(1));
    T[0][0] = 32, T[1][0] = 16, T[2][0] = 8;
    T[3][0] = 4, T[4][0] = 2, T[5][0] = 1;
    if (n <= 6){
        cout << T[6 - n][0];
        return 0;
    }
    vector<vll> fans = mat_pow(v, n - 6, 6);
    fans = mat_mul(fans, T, 6, 6, 6, 1);
    cout << fans[0][0];
}
/*

[n    ]       [n - 1]
[n - 1]       [n - 2]
[n - 2]       [n - 3]
[n - 3] = M * [n - 4]
[n - 4]       [n - 5]
[n - 5]       [n - 6]


find M;











/*
