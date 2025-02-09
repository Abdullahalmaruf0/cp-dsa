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
#define pb push_back
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

const int mx=500+123;
ll dist[mx][mx];

int main(){
    optimize();
    
    ll n,m,q;
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dist[i][j]=1e18;
        }
    }

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);;
    }


    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for(int i=1;i<=q;i++){
        ll x,y;
        cin>>x>>y;
        if(dist[x][y]>=1e18)cout<<-1<<endl;
        else
        cout<<dist[x][y]<<endl;
    }
    



}

