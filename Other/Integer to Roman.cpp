#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

string add_digit(string r,int q,char c)
{
    for(int i=0;i<q;i++)
        r+=c;
    return r;
}

void int_to_roman(int n)
{
    int q;
    int temp=n;
    string roman;

    while(n)
    {
        if(n>=1000)
        {
            q = n/1000;
            roman = add_digit(roman,q,'M');
            n%=1000;
        }
        else if(n>=500)
        {
            if(n<900)
            {
                q = n/500;
                roman = add_digit(roman,q,'D');
                n%=500;
            }
            else
            {
                roman+='C';
                roman+='M';
                n%=100;
            }
        }

        else if(n>=100)
        {
            if(n<400)
            {
                q = n/100;
                roman = add_digit(roman,q,'C');
                n%=100;
            }
            else
            {
                roman+='C';
                roman+='D';
                n%=100;
            }
        }
        else if(n>=50)
        {
            if(n<90)
            {
                q = n/50;
                roman = add_digit(roman,q,'L');
                n%=50;
            }
            else
            {
                roman+='X';
                roman+='C';
                n%=10;
            }
        }
        else if(n>=10)
        {
            if(n<40)
            {
                q = n/10;
                roman = add_digit(roman,q,'X');
                n%=10;
            }
            else
            {
                roman+='X';
                roman+='L';
                n%=10;
            }
        }
        else if(n>=5)
        {
            if(n<9)
            {
                q = n/5;
                roman = add_digit(roman,q,'V');
                n%=5;
            }
            else
            {
                roman+='I';
                roman+='X';
                n=0;
            }
        }
        else if(n>=1)
        {
            if(n<4)
            {
                q = n;
                roman = add_digit(roman,q,'I');
                n=0;
            }
            else
            {
                roman+='I';
                roman+='V';
                n=0;
            }
        }
    }
    cout<<roman<<endl;
}

int main()
{

    int n;

    cin>>n;

    int_to_roman(n);

    return 0;
}
