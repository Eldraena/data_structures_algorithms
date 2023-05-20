//Caculate (a^b)%p

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const ll MOD = 1e9 + 7;

ll powmod_non_recursive(ll a, ll b, ll p)
{
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b >>= 1;
    }
    return product;
}

ll powmod_recursive(ll a, ll b, ll p)
{
    if(a == 0) return 0;
    if(b == 0) return 1;
    
    a %= p;
    ll tmp = powmod_recursive(a, b/2, p);
    tmp = (tmp * tmp) % p;
    if (b % 2 == 0)
        return tmp;
    return (a * tmp) % p;
}


int main()
{
    int a;
    cin >> a;
    cout << powmod_non_recursive(a, MOD - 2, MOD) << endl;
    cout << powmod_recursive(a, MOD - 2, MOD) << endl;
    return 0;
}

