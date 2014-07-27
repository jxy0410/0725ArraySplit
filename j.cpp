#include <iostream>
#include <cmath>
using namespace std;
//有一个无序的，元素个数为2n的正整数数组，如何将它分割成元素个数为n的两个数组，并使两个子数组的和最接近

int arr[] = {1,5,7,8,9,6,3,11,20,17};

//方法1:基础解法---时间复杂度是O(n),但是得到的两个数组并不是最优的
int p[5];
int q[5];
bool flag = true;
#define max(x,y)  x > y ? x : y
#define min(x,y)  x < y ? x : y

void Breakup(int a[], int n)
{
	int i;
	int j;
	int k = 1;
	p[0] = a[0];
	q[0] = a[1];
	int sum1 = p[0];
	int sum2 = q[0];
//先将整个数组两两插入到两个数组里，保证较大数插入到总和较小的数组中，较小数插入到总和较大的数组中
	for (i = 2; i < n; i += 2)     
	{
		if (sum1 <= sum2)
		{
			p[k] = max(a[i], a[i + 1]);
			q[k] = min(a[i], a[i + 1]);
		}
		else 
		{
			p[k] = min(a[i], a[i + 1]);
			q[k] = max(a[i], a[i + 1]);
		}
		sum1 += p[k];
		sum2 += q[k];
		k ++;
	}
	k = abs(sum1 - sum2)/2;     //依据分好的两组总和之差，来找出一对数进行交换，使得两数组和的差值尽可能小
	for (i = 0; i < 5; i ++)
		if (flag)
		{
			for (j = 0; j < 5; j ++)
				if (sum1 > sum2)
				{
					if (p[i] > q[j])
						if ((p[i]-q[j]) == k)
						{
							sum2 = p[i];
							p[i] = q[j];
							q[j] = sum2;
							flag = false;
							break;
						}
				}
				else
				{
					if (q[j] > p[i])
						if ((q[j] - p[i]) == k)
						{
							sum2 = p[i];
							p[i] = q[j];
							q[j] = sum2;
							flag = false;
							break;
						}
				}
		}
}


int main()
{
	int i;
	Breakup(arr,10);
	cout << "第一个子数组是:"<<" ";
	for (i = 0; i < 5; i ++)
		cout << p[i] <<" ";
	cout << endl;
	cout <<"第二个子数组是:"<<" ";
	for (i = 0; i <5; i ++)
		cout << q[i] <<" ";
	cout << endl;
	return 0;
}