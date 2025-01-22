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

string preprocess(const string& s) {
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    return t;
}

// Manacher's Algorithm
string longestPalindrome(const string& s) {
    if (s.empty()) return "";

    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0); 
    int center = 0, right = 0;
    int maxLength = 0, centerIndex = 0;

    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
            ++p[i];
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        if (p[i] > maxLength) {
            maxLength = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLength) / 2;
    return s.substr(start, maxLength);
}

int main(){
    optimize();

    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
}
