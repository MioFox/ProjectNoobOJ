#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int presum = 0;
    int res = 0;
    unordered_map<int, int> hashmap;
    hashmap[0] = 1;
    for (int& i : nums)
    {
        presum += i;
        auto it = hashmap.find(presum - k);
        if (it != hashmap.end())
        {
            res += hashmap[presum - k];
        }
        hashmap[presum]++;
    }
    return res;
}


int main()
{
    int n, k, i;
    vector<int> nums;
    cout << "Enter the size of nums and k: ";
    cin >> n >> k;
    cout << "Enter nums: ";

    while (cin >> i)
    {
        nums.push_back(i);
        if (cin.get() == '\n') break;
    }

    cout << "和为k的子数组数量为：" << subarraySum(nums, k);
    return 0;

}

