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
		unordered_map<char, int> to2 = { {'R',1},{'G',2},{'B',4} };   //�ù�ϣ����ӳ����ɫ�Ͷ�����λ��ϵ
		for (int i = 0; i < n; i += 2)
		{
			cnt[rings[i + 1] - '0'] |= to2[rings[i]];    //������ɫ�ĸ˵���ɫλ��������
		}
		return count(cnt, cnt + 10, 7);      //���������е���7��111���ĸ�����
	}
};


int main()
{
	Solution solution;
	string rings = "B0B6G0R6R0R6G9";
	cout << rings << ":" << solution.countPoints(rings);
	return 0;
}