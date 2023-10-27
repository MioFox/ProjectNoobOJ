#include<iostream>
#include<vector>
using namespace std;

vector<int> nums;   //元素数组
vector<int> dir;    //方向数组（0表示左移，1表示右移）
int n;  //元素数组大小
int ans = 0;    //组合数量

void Print()
{
	for (int i = 0; i < n; i++)  cout << nums[i] << " ";
	cout << endl;
	ans++;
}

void changeDir(int num)      //调转比当前移动元素更大的所有元素的方向
{
	for (int i = 0; i < n; i++)
	{
		if (num < nums[i])
		{
			if (dir[i] == 0)  dir[i] = 1;
			else dir[i] = 0;
		}
	}
}

void SWAP(int a, int b)
{
	swap(nums[a], nums[b]);
	swap(dir[a], dir[b]);
}

int canMove()         //找到可移动的最大元素
{
	int maxIndex = -1;
	int maxNum = -1;
	for (int i = 0; i < n; i++)
	{
		if (dir[i] == 0 && i > 0 && nums[i] > nums[i - 1])
		{
			if (maxNum < nums[i])
			{
				maxIndex = i;
				maxNum = nums[i];
			}
		}
		else if (dir[i] == 1 && i<n - 1 && nums[i]>nums[i + 1])
		{
			if (maxNum < nums[i])
			{
				maxIndex = i;
				maxNum = nums[i];
			}
		}
	}
	Print();       //每一次交换调用一次canMove函数
	return maxIndex;
}

void move(int index)
{
	//左移
	if (dir[index] == 0 && index > 0 && nums[index] > nums[index - 1])
	{
		SWAP(index, index - 1);
	}
	//右移
	else if (dir[index] == 1 && index<n - 1 && nums[index]>nums[index + 1])
	{
		SWAP(index, index + 1);
	}
}


int main()
{
	cout << "Enter the size of the number seq: ";
	cin >> n;

	//初始化
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
		dir.push_back(0);           //初始化元素方向向左
	}

	while (true)
	{
		int moveIndex = canMove();
		if (moveIndex != -1)
		{
			int moveNumber = nums[moveIndex];
			move(moveIndex);
			changeDir(moveNumber);
		}
		else break;
	}
	cout <<"组合数量为"<< ans << endl;
	return 0;
}