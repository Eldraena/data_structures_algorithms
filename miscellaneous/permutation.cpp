
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int n, k, cnt;

vector<int> vt;

void permutation(vector<int> vt, vector<bool>& mark, vector<int>& per, int c)
{
    if(c == k)
    {
        cnt++;
        for(auto i: per)
            cout << i << " ";
        cout << endl;
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(mark[i] == false)
        {
            mark[i] = true;
            per.at(c) = vt[i];
            permutation(vt, mark, per, c + 1);
            mark[i] = false;
        }
    }
}

int main()
{
    fio;
    cin >> n >> k;
    cnt = 0;

    vector<bool> mark(n, false);
    vector<int> vt, per(k, -1);
    
    for(int i = 0; i < n; i++)
    {
        vt.push_back(i);
        cout << vt.at(i) << " ";
    }
    cout << endl;
    
    permutation(vt, mark, per, 0);
    cout << cnt << endl;
    
    return 0;
}
