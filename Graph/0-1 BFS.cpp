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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

vector<string>grid;
int level[1005][1005];
int r,c;

void reset()
{
    grid.clear();
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            level[i][j] = INF;
}

int BFS(int sx,int sy)
{
    deque<pii>q;
    q.push_front(pii(sx,sy));
    level[sx][sy] = 0;
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;

        if(ux == r-1 && uy == c-1)
            break;

        q.pop_front();

        for(int i=0; i<4; i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx>=0&&vx<r && vy>=0&&vy<c)
            {
                if(grid[vx][vy]==grid[ux][uy] && level[vx][vy] > level[ux][uy])
                {
                    level[vx][vy] = level[ux][uy];
                    q.push_front(pii(vx,vy));
                }
                else if(level[vx][vy] > level[ux][uy] + 1)
                {
                    level[vx][vy] = level[ux][uy] + 1;
                    q.push_back(pii(vx,vy));
                }
            }
        }
    }
    return level[r-1][c-1];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    char s[150];
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        scanf("%d%d",&r,&c);
        reset();
        for(int i=0; i<r; i++)
        {
            scanf("%s",s);
            grid.push_back(s);
        }
        int ans = INF;
        ans = BFS(0,0);
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
