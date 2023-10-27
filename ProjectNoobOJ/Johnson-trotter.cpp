#include<iostream>
#include<vector>
using namespace std;

vector<int> nums;   //Ԫ������
vector<int> dir;    //�������飨0��ʾ���ƣ�1��ʾ���ƣ�
int n;  //Ԫ�������С
int ans = 0;    //�������

void Print()
{
	for (int i = 0; i < n; i++)  cout << nums[i] << " ";
	cout << endl;
	ans++;
}

void changeDir(int num)      //��ת�ȵ�ǰ�ƶ�Ԫ�ظ��������Ԫ�صķ���
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

int canMove()         //�ҵ����ƶ������Ԫ��
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
	Print();       //ÿһ�ν�������һ��canMove����
	return maxIndex;
}

void move(int index)
{
	//����
	if (dir[index] == 0 && index > 0 && nums[index] > nums[index - 1])
	{
		SWAP(index, index - 1);
	}
	//����
	else if (dir[index] == 1 && index<n - 1 && nums[index]>nums[index + 1])
	{
		SWAP(index, index + 1);
	}
}


int main()
{
	cout << "Enter the size of the number seq: ";
	cin >> n;

	//��ʼ��
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
		dir.push_back(0);           //��ʼ��Ԫ�ط�������
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
	cout <<"�������Ϊ"<< ans << endl;
	return 0;
}