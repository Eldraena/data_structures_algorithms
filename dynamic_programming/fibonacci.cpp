#include <iostream>
#include <vector>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

vector<ll> fib(1000, -1);

ll fibonacci(int n)
{
    if(n < 0)
    {
        cout << "Wrong request!";
        return -1;
    }
    
    if(fib.at(n) != -1)
       return fib.at(n);
       
    ll res = -1;
    
    if(n == 0 || n == 1)
        res = n;
    else
        res = fibonacci(n - 1) + fibonacci(n - 2);
    
    fib.at(n) = res;
    return res;
}

int main()
{
    fio;
    cout << fibonacci(52) << endl;
    return 0;
}
