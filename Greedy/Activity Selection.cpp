/// SPOJ -> BUSYMAN - I AM VERY BUSY
/// http://www.spoj.com/problems/BUSYMAN/

#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

class task
{
public:
    int s,f;
    task(int a, int b)
    {
        s = a;
        f = b;
    }
    bool operator < (const task &p) const{
        if(f!=p.f)  return f < p.f;
        else return s<p.s;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,s,f;
    vector<task>solution;
    scanf("%d",&t);

    while(t--)
    {
        solution.clear();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&s,&f);
            solution.push_back(task(s,f));
        }
        sort(all(solution));
        int ans = 1, ft = solution[0].f;
        for(int i=1;i<solution.size();i++)
            if(solution[i].s>=ft)
            {
                ans++;
                ft = solution[i].f;
            }
        pif(ans);
    }

    return 0;
}
