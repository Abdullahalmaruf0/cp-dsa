#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'
#define PB push_back
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
const ll mx=2e5+123;
ll prop[mx*3];
bool vis[mx*3];
ll a[mx];
void shift(ll node){
    prop[node*2]+=prop[node];
     prop[node*2+1]+=prop[node];
     vis[node*2]=vis[node*2+1]=1;
     prop[node]=vis[node]=0;

}

void init(ll node,ll b,ll e){
    if(b==e){
        prop[node]=a[b];
        return;
    }
    ll mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
}

void update(ll node,ll b,ll e,ll i,ll j,ll val){
    if(i>e||j<b){
        return;
    }
    if(b>=i&&e<=j){
        prop[node]+=val;
        vis[node]=1;
        return;
    }
    ll mid=(b+e)/2;
    update(node*2,b,mid,i,j,val);
    update(node*2+1,mid+1,e,i,j,val);
}

    ll query(ll node,ll b,ll e,ll i){
        if(i>e||i<b)return 0;
        if(b==e&&i==b){
            return prop[node];
        }
        if(vis[node])shift(node);


        int mid=(b+e)/2;
       ll m= query(node*2,b,mid,i);
       ll ma= query(node*2+1,mid+1,e,i);
        return m+ma;
    }

int main(){
    optimize();
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init(1,1,n);
    while (q--)
    {
        ll x;
        cin>>x;
        if(x==2){
            ll y;
            cin>>y;
            cout<<query(1,1,n,y)<<endl;;
        }
        else{
            ll u,v,w;
            cin>>u>>v>>w;
            update(1,1,n,u,v,w);
        }
    }
    
}
  //bal er code