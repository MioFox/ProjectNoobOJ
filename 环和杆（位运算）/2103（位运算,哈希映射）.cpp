#include<iostream>
#include<string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int countPoints(string rings)
	{
		int cnt[10]{};
		int n = rings.size();
		unordered_map<char, int> to2 = { {'R',1},{'G',2},{'B',4} };   //用哈希表来映射颜色和二进制位关系
		for (int i = 0; i < n; i += 2)
		{
			cnt[rings[i + 1] - '0'] |= to2[rings[i]];    //对有颜色的杆的颜色位做或运算
		}
		return count(cnt, cnt + 10, 7);      //计算数组中等于7（111）的杆数量
	}
};


int main()
{
	Solution solution;
	string rings = "B0B6G0R6R0R6G9";
	cout << rings << ":" << solution.countPoints(rings);
	return 0;
}