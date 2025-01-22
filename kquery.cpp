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
int val[mx];
vi st[4*mx];

void merge (vi &a,vi &b,vi &c){
    int i=0,j=0;
    while (i<a.size()&&j<b.size())
    {
        if(a[i]<b[j])c.push_back(a[i]),i++;
        else c.push_back(b[j]),j++;

    }
    
    while(i<a.size())c.push_back(a[i]),i++;
    while(j<b.size())c.push_back(b[j]),j++;
}

void init(ll node,ll b,ll e){
    if(b==e){
        st[node].push_back(val[b]);
        return;
    }
    ll mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    merge(st[2*node],st[node*2+1],st[node]);

}

ll query(ll node,ll b, ll e,ll i,ll j,ll newl){
    if(i>e||j<b)return 0;
    if(b>=i&&j>=e){
        return st[node].end()-upper_bound(st[node].begin(),st[node].end(),newl);
    }
    ll mid=(b+e)/2;
    return query(node*2,b,mid,i,j,newl)+query(node*2+1,mid+1,e,i,j,newl);
}


int main(){
    optimize();
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>val[i];
    init(1,1,n);
    ll q;
    cin>>q;
    while (q--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        cout<<query(1,1,n,x,y,z)<<endl;

    }
    
}