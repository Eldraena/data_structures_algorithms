#include <iostream>
using namespace std;

#define INF     -99999

int N;                  //Number of sponsored goods
int D[100000 + 10];     //Preference

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> D[i];
}

//Kadane's Algorithm, Greedy + Dynamic Programming, O(n)
int Solve_dp()
{ 
    int max_ending_here = D[0];
    int max_so_far = D[0];

    for (int i = 1; i < N; i++)
    {
        if (D[i] < max_ending_here + D[i])
            max_ending_here += D[i];
        else
            max_ending_here = D[i];

        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }

    return max_so_far;
}

//Devide and Conquer, O(nlogn)
int _max(int a, int b, int c)
{
    int res = a;
    if (res < b) res = b;
    if (res < c) res = c;
    return res;
}

int find_max(int idxLeft, int idxRight)
{
    if (idxLeft >= idxRight -1) return _max(D[idxLeft], D[idxRight], INF);
    int mid = (idxLeft + idxRight) / 2;

    int max_left_sum, max_right_sum, sum, max_mid;
    max_left_sum = INF; sum = 0;
    for (int i = mid; i >= idxLeft; i--)
    {
        sum += D[i];
        if (max_left_sum < sum)
            max_left_sum = sum;
    }

    max_right_sum = INF, sum = 0;
    for (int i = mid; i <= idxRight; i++)
    {
        sum += D[i];
        if (max_right_sum < sum)
            max_right_sum = sum;
    }

    max_mid = _max(max_left_sum, max_right_sum, max_left_sum + max_right_sum - D[mid]);

    return _max(find_max(idxLeft, mid), find_max(mid, idxRight), max_mid);
}

int Solve_devide_conquer()
{
    return find_max(0, N - 1);
}

int main()
{
    InputData(); //Input function
    //cout << Solve_dp() << endl; //Output
    cout << Solve_devide_conquer() << endl; //Output
    return 0;
}