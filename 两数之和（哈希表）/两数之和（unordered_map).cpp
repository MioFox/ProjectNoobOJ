#include<iostream>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashtable;

    for (int i = 0; i < nums.size(); ++i) {

        auto it = hashtable.find(target - nums[i]); //如果找到则返回指向该元素的迭代器,未找到则返回指向unordered_map::end的迭代器

        if (it != hashtable.end())     //如果不是未找到==如果找到
        {
            return { it->second, i };    //返回哈希表中对应数的下标和现在x的下标
        }
        //先查询再将x插入到哈希表中，保证x不与自己匹配
        hashtable[nums[i]] = i;    //哈希表中对应关系为nums[i]-i
    }
    return {};
}



int main()
{
    cout << "Enter the nums:";
    vector<int> nums;
    int i;
    while (cin >> i)
    {
        nums.push_back(i);
        if (cin.get()=='\n') break;
    }
    cout << "Enter the Target:";
    int target;
    cin >> target;
    cout << "The index of two nums:";
    vector<int> tindex = twoSum(nums, target);
    cout << tindex[0] << "," << tindex[1];

}
