#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007


#define mem(a,b) memset(a, b, sizeof(a) )


#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
        {
            result *= a;
            b--;
        }
        else
        {
            a *= a;
            b /= 2;
        }
    }
    return result;
}

int64_t ceil_div(int64_t a, int64_t b)
{
    return (a + b - 1) / b;
}

bool is_prime(ll x)
{
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (ll i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

const int mx = 1e5+123;
ll dist[mx];
vii adj[mx];
int par[mx];


void dijkstra ( int s, int n )
{
    for ( int i = 1; i <= n; i++ ) dist[i] = infLL;
    priority_queue< pll, vll, greater<pll>> pq;

    dist[s] = 0;
    pq.push ( { 0, s } );

    while ( !pq.empty() ) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();

        if ( dist[u] < curD ) continue;

        for ( auto v : adj[u] ) {
            if ( curD + v.S < dist[v.F] ) {
                dist[v.F] = curD + v.S;
                par[v.F] = u;
                pq.push( { dist[v.F], v.F } );
            }
        }
    }
}

int main(){
    optimize();

     int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB ( {v, w} );
        adj[v].PB ( { u, w } );
    }

    dijkstra(1, n);

    if ( dist[n] == infLL ) return cout << "-1\n", 0;

    int u = n;
    vi ans = {n};
    while ( par[u] != 0 ) {
        ans.PB ( par[u] );
        u = par[u];
    }

    reverse ( all ( ans ) );

    for ( auto u : ans ) cout << u << " ";
    cout << endl;



}