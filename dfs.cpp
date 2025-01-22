#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
const ll N = 1'000'000'000'000L;
#define MOD 1000000007

#define mem(a, b) memset(a, b, sizeof(a))

#define optimize()              \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll power(ll a, ll b){
  ll result = 1;
  while (b) {
    if(b % 2) {
      result *= a;
      b--;
    } else {
      a *= a;
      b /= 2;
    }
  }
  return result;
}

int64_t ceil_div(int64_t a, int64_t b) {
  return (a + b - 1) / b;
}

bool is_prime(ll x){
  if (x < 2) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (ll i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
}

const int mx=2e5+123;
bool vis[mx];
vi adj[mx];

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}


int main(){
    optimize();
    int t;
    cin>>t;

    while (t--)
    {
       ll n;
       cin>>n;
       vl v(n);
       for(ll i=0;i<n;i++)cin>>v[i];
       ll m=*min_element(all(v));

       ll s=v[0];
       if(s==m)cout<<"Bob"<<endl;
       else cout<<"Alice"<<endl;
    }
    
    
}