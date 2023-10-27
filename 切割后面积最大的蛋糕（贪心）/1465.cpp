#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
{
	int mod = 1e9 + 7;

	sort(horizontalCuts.begin(), horizontalCuts.end());
	sort(verticalCuts.begin(), verticalCuts.end());

	auto calMax = [] (vector<int>& arr, int border) -> int {         //Lambda表达式    [capture list] (parameters) murtable throw() ->return type{statement};
		int res = 0, pre = 0;
		for (int i : arr)                     //贪心          
		{
			res = max(i - pre, res);          //每次循环保留最大的蛋糕间隔
			pre = i;
		}
		return max(res, border - pre);        //蛋糕切N刀后有N+1块蛋糕，最后一块蛋糕为边界减当前刀位置
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
	while (cin >> i)        //vector不定长数组输入
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