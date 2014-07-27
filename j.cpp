#include <iostream>
#include <cmath>
using namespace std;
//��һ������ģ�Ԫ�ظ���Ϊ2n�����������飬��ν����ָ��Ԫ�ظ���Ϊn���������飬��ʹ����������ĺ���ӽ�

int arr[] = {1,5,7,8,9,6,3,11,20,17};

//����1:�����ⷨ---ʱ�临�Ӷ���O(n),���ǵõ����������鲢�������ŵ�
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
//�Ƚ����������������뵽�����������֤�ϴ������뵽�ܺͽ�С�������У���С�����뵽�ܺͽϴ��������
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
	k = abs(sum1 - sum2)/2;     //���ݷֺõ������ܺ�֮����ҳ�һ�������н�����ʹ��������͵Ĳ�ֵ������С
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
	cout << "��һ����������:"<<" ";
	for (i = 0; i < 5; i ++)
		cout << p[i] <<" ";
	cout << endl;
	cout <<"�ڶ�����������:"<<" ";
	for (i = 0; i <5; i ++)
		cout << q[i] <<" ";
	cout << endl;
	return 0;
}