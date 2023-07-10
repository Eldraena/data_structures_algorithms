int main()
{
    vector<int> set = {1,2,3,4};
    for (int m = 1; m < (1 << set.size()); ++m) 
    {
        for (int i = 0; i < m; ++i) 
        {
            if (m & (1 << i)) 
                cout << set[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
