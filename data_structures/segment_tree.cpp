#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int N = 1005;
vector<int> a(N, -1), tree(N*4, -1);
int n;

void build(int id, int l, int r)
{
    if(l == r)
    {
        tree[id] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);

    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v, int val)
{
    if(u > r || v < l)
        return;
        
    if(l == r)
    {
        tree[id] += val;
        return;
    }
    
    int m = (l + r) / 2;
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    tree[id] = max(tree[id*2], tree[id*2+1]);
}

int query(int id, int l, int r, int u, int v)
{
    if(u > r || v < l)
        return INT_MIN;
        
    if(l == r)
        return tree[id];
    
    int m = (l + r) / 2;
    return max(query(id*2, l, m, u, v), query(id*2+1, m + 1, r, u, v));
}

int main()
{
    fio;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    for(int i = 1; i <= n * 4; i++)
        cout << tree[i] << " ";
    cout << endl;
    
    int T;
    cin >> T;
    while(T--)
    {
        char s;
        cin >> s;
        if(s == 'X')
        {
            int x, y, v;
            cin >> x >> y >> v;
            update(1, 1, n, x, y, v);
            
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << " ";
        }
    }

    return 0;
}
