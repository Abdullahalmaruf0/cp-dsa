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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i]<n&& s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    optimize();
    string s;
    cin>>s;
    vi tm=z_function(s);    
   for(int i=0;i<tm.size()-1;i++){
    if(i+1+tm[i+1]==tm.size()){
      cout<<i+1<<" ";
    }
   }
   cout<<tm.size()<<" ";
}