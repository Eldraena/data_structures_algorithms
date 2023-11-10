#include<bits/stdc++.h>
using namespace std;

struct segtree 
{
	int n;
	vector<int> st;

	void init(int _n) 
	{
    		this->n = _n;
    		st.resize(4 * n, 0);
	}

    	void build(int start, int ending, int node, vector<int> &v) 
    	{
        	// leaf node base case
		if (start == ending) 
        	{
	    	st[node] = v[start];
	    	return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);
		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v);

		//build sum segment tree
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
		//build min segment tree
		//st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
		//build max segment tree
		//st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
    	}

    	int query(int start, int ending, int l, int r, int node) 
    	{
        	// non overlapping case
		if (start > r || ending < l)
        	{
			//query sum segment tree
			return 0;
			//query min segment tree
			//return INT_MAX;
			//query max segment tree
			//return INT_MIN;
		}

		// complete overlap
		if (start >= l && ending <= r) 
        	{
	    		return st[node];
		}

		// partial case
		int mid = (start + ending) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);


		//query sum segment tree
		return q1 + q2;
		//query min segment tree
		//return min(q1, q2);
		//query max segment tree
		//return max(q1, q2);
    	}

    	void update(int start, int ending, int node, int index, int value) 
    	{
        	// base case
		if (start == ending) 
        	{
	    		st[node] = value;
	    		return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) 
        	{
	    		// left subtree
	    		update(start, mid, 2 * node + 1, index, value);
		}
		else 
		{
	    		// right
	    		update(mid + 1, ending, 2 * node + 2, index, value);
		}

		//update sum segment tree
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
		//update min segment tree
		//st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
		//update max segment tree
		//st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
		return;
    	}

    	void build(vector<int> &v) 
    	{
		build(0, n - 1, 0, v);
    	}

    	int query(int l, int r) 
    	{
		return query(0, n - 1, l, r, 0);
    	}

    	void update(int x, int y) 
    	{
		update(0, n - 1, 0, x, y);
    	}
};
