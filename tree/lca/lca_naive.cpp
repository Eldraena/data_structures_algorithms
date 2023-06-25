#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define _MAX 10005

typedef vector<int> vi;

struct vertice
{
    vector<int> children;
    int parent;
    int depth;
    
    vertice(vector<int> _children, int _parent, int _depth)
    {
        children = _children;
        parent = _parent;
        depth = _depth;
    }
};

vector<vertice> dt(_MAX, {{}, 0, 0});

void dfs(int u, int p, int d)
{
    dt[u].parent = p;
    dt[u].depth = d;
    
    for(auto i: dt[u].children)
    {
        dfs(i, u, d + 1);
    }
}

int lca_naive(int u, int v)
{
    if(u == v)
    {
        return u;
    }
    
    if(dt[u].depth > dt[v].depth)
    {
        swap(u, v);
    }
    
    while(dt[u].depth != dt[v].depth)
    {
        v = dt[v].parent;
    }

    while(dt[u].parent != dt[v].parent)
    {
        u = dt[u].parent;
        v = dt[v].parent;
    }
    
    return dt[u].parent;
}

int main()
{
    fio;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        dt[u].children.push_back(v);
    }
    
    dfs(1, 0, 1);
   
    cout << "*******" << "\n";
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca_naive(u, v) << "\n";
    }
  
    return 0;
}
