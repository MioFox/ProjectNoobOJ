#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
{
	int mod = 1e9 + 7;

	sort(horizontalCuts.begin(), horizontalCuts.end());
	sort(verticalCuts.begin(), verticalCuts.end());

	auto calMax = [] (vector<int>& arr, int border) -> int {         //Lambda���ʽ    [capture list] (parameters) murtable throw() ->return type{statement};
		int res = 0, pre = 0;
		for (int i : arr)                     //̰��          
		{
			res = max(i - pre, res);          //ÿ��ѭ���������ĵ�����
			pre = i;
		}
		return max(res, border - pre);        //������N������N+1�鵰�⣬���һ�鵰��Ϊ�߽����ǰ��λ��
	};

	return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % mod;

}

int main()
{
	int h, w;
	vector<int> horizontalCuts,verticalCuts;
	cout << "Enter the h and w:";
	cin >> h >> w;
	cout << "Enter the horizontalCuts:";
	int i;
	while (cin >> i)        //vector��������������
	{
		horizontalCuts.push_back(i);
		if (cin.get() == '\n') break;
	}
	cout << "Enter the verticalCuts:";
	int j;
	while (cin >> j)
	{
		verticalCuts.push_back(j);
		if (cin.get() == '\n') break;
	}

	cout << "The max cake is:" << maxArea(h, w, horizontalCuts, verticalCuts);

	return 0;

}