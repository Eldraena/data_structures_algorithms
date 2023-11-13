//https://leetcode.com/problems/maximum-strong-pair-xor-ii/

class Solution {
public:
    struct Node
    {
        Node* nextBit[2];
        int cnt;

        Node()
        {
            this->nextBit[0] = nullptr;
            this->nextBit[1] = nullptr;
            this->cnt = 0;
        }
    };

    struct Trie
    {
        Node* root;

        Trie()
        { 
            root = new Node();
        }

        void insert(int num)
        {
            Node* tmp = root;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1;
                if(tmp->nextBit[bit] == nullptr)
                    tmp->nextBit[bit] = new Node();
                tmp->nextBit[bit]->cnt++;

                tmp = tmp->nextBit[bit];
            }
        }

        void remove(int num)
        {
            Node* tmp = root;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1;
                if(tmp->nextBit[bit] == nullptr) return;

                tmp->nextBit[bit]->cnt--;
                if(tmp->nextBit[bit]->cnt == 0)
                {
                    delete tmp->nextBit[bit];
                    tmp->nextBit[bit] = nullptr;
                    return;
                }
                    
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
    
    int maximumStrongPairXor(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int res = 0, k = 0;
        Trie t;
        t.insert(nums[0]);
        
        for(int i = 1; i < nums.size(); i++)
        {
            t.insert(nums[i]);
            while(nums[k] * 2 < nums[i])
            {
                t.remove(nums[k]);
                k++;
            }
            res = max(res, t.find_max_xor(nums[i]));
        }

        return res;
    }
};
