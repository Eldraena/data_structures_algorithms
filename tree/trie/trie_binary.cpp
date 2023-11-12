class Solution 
{
public:
    struct Node
    {
        Node* nextBit[2];
    };

    struct Trie
    {
        Node* root;

        Trie(){ root = new Node(); }

        void insert(int num)
        {
            Node* tmp = root;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1;
                if(tmp->nextBit[bit] == nullptr)
                    tmp->nextBit[bit] = new Node();
                tmp = tmp->nextBit[bit];
            }
        }

        int find_max_xor(int val)
        {
            Node* tmp = root;
            int res = 0;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (val >> i) & 1;
                if(tmp->nextBit[1 - bit] != nullptr)
                {
                    res |= (1 << i);
                    tmp = tmp->nextBit[1 - bit];
                }
                else
                    tmp = tmp->nextBit[bit];
            }
            return res;
        }
    };

    int findMaximumXOR(vector<int>& nums) 
    {
        int res = 0;
        Trie t;

        t.insert(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            res = max(res, t.find_max_xor(nums[i]));
            t.insert(nums[i]);
        }
        
        return res;
    }
};
