#include<iostream>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashtable;

    for (int i = 0; i < nums.size(); ++i) {

        auto it = hashtable.find(target - nums[i]); //����ҵ��򷵻�ָ���Ԫ�صĵ�����,δ�ҵ��򷵻�ָ��unordered_map::end�ĵ�����

        if (it != hashtable.end())     //�������δ�ҵ�==����ҵ�
        {
            return { it->second, i };    //���ع�ϣ���ж�Ӧ�����±������x���±�
        }
        //�Ȳ�ѯ�ٽ�x���뵽��ϣ���У���֤x�����Լ�ƥ��
        hashtable[nums[i]] = i;    //��ϣ���ж�Ӧ��ϵΪnums[i]-i
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
