class SegmentTree 
{
private:
    vector<int> nums;
    vector<int> maxTree;
    vector<int> sumTree; 
    int n;
    
    int left(int p) 
    {
        return p << 1;
    }

    int right(int p) 
    {
        return (p << 1) + 1;
    }

    void buildMaxTree(int p, int L, int R) 
    {
        if (L == R) 
        {
            maxTree[p] = L;
        }
        else 
        {
            buildMaxTree(left(p), L, (L + R) / 2);
            buildMaxTree(right(p), (L + R) / 2 + 1, R);
            int c1 = maxTree[left(p)];
            int c2 = maxTree[right(p)];
            maxTree[p] = (nums[c1] <= nums[c2]) ? c1 : c2;
        }
    }

    void buildSumTree(int p, int L, int R) 
    {
        if (L == R) 
        {
            sumTree[p] = L;
        }
        else 
        {
            buildSumTree(left(p), L, (L + R) / 2);
            buildSumTree(right(p), (L + R) / 2 + 1, R);
            sumTree[p] = sumTree[left(p)] + sumTree[right(p)];
        }
    }
    
    int rmq(int p, int L, int R, int i, int j) 
    {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return maxTree[p];
        
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (nums[p1] <= nums[p2]) ? p1 : p2;
    }

    int rsq(int p, int L, int R, int i, int j) 
    {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return sumTree[p];

        return rsq(left(p), L, (L + R)/2, i, j) + rsq(right(p), (L + R)/2 + 1, R, i, j);
    }

    void update(int p, int l, int r, int idx, int dif) 
    {
        if (idx < l || idx > r) return;
        
        sumTree[p] += dif;
        if (nums[maxTree[p]] < nums[idx]) maxTree[p] = idx;
        if (l == r) return;
        update(left(p), l, (l + r)/2, idx, dif);
        update(right(p), (l + r)/2 + 1, r, idx, dif);
    }

public:
    SegmentTree(vector<int>& A) 
    {
        nums = A;
        n = (int)nums.size();
        maxTree.assign(4 * n, 0);
        buildMaxTree(1, 0, n - 1);
        sumTree.assign(4 * n, 0);
        buildSumTree(1, 0, n - 1);
    }
    
    int rangeMaxQuery(int i, int j) 
    {
        return rmq(1, 0, n - 1, i, j);
    }

    int rangeSumQuery(int i, int j) 
    {
        return rsq(1, 0, n - 1, i, j);
    }

    void update(int idx, int val) 
    {
        int dif = val - nums[idx];
        nums[idx] = val;
        update(1, 0, n - 1, idx, dif);
    }
};
