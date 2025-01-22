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





const int mx=2e5+123;
ll a[mx];
ll t[mx*3];


void init(ll node,ll b,ll e){
    if(b==e){
        t[node]=a[b];
        return;
    }
    ll mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    t[node]=t[node*2]+t[node*2+1];
}

ll query(ll node,ll b,ll e,ll i,ll j){
    if(i>e||j<b){
        return 0;
    }
    if(i<=b&&j>=e){
       return t[node];
    }
    ll mid=(b+e)/2;
    ll leftSum=query(node*2,b,mid,i,j);
    ll rightSum=query(node*2+1,mid+1,e,i,j);
    return leftSum+rightSum;
}

void update(ll node,ll b,ll e,ll i,ll newvalue){
    if(i>e||i<b){
        return;
    }
    if(i==b&&i==e){
    t[node]=newvalue;
    return;
    }
    ll mid=(b+e)/2;
    update(node*2,b,mid,i,newvalue);
    update(node*2+1,mid+1,e,i,newvalue);
    t[node]=t[node*2]+t[node*2+1];
}




int main(){
    optimize();
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
     init(1,1,n);
    while (m--)
    {
       ll x,y,z;
       cin>>x>>y>>z;
       if(x==1){
        update(1,1,n,y+1,z);
       }
       else{
        cout<<query(1,1,n,y,z)<<endl;
       }
    }
    
    

   
    }
  //bal er codey