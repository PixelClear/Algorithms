#include <stdio.h>
#include<limits.h>
/*Needed for float ranges*/
#include<float.h>
#include<string.h>

/*i starts from gap and goes in -> direction one by one till n;
j starts from gap - i and goes in direction <- moving by gap till j>=0
After one complete traversal we reduce gap/interval by gap/2*/

void shell_sort(int v[], int n)
{
	int gap = 0;
	int i = 0;
	int j = 0;

	for(gap = n/2; gap > 0; gap/=2)
	{
		for(i = gap ; i < n; i++)
		{
			for(j = i-gap; j>=0 && v[j] > v[j+gap] ; j-=gap)
			{
				int temp;
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}

}

int binary_search(int v[],int n, int key)
{
	int low = 0;
	int high = n-1;

	while(low <= high)
	{
		int mid = (high + low)/2;

		if(v[mid] < key)
			low = mid + 1;
		else if(v[mid] > key)
			high = mid - 1;
		else 
			return mid;
	}

	return -1;
}

int main()
{
	int n = 8;
	int a[]={35,33,42,10,14,19,27,44};
	
	shell_sort(a,8);

	for(int i = 0; i<8;i++)
	{
		printf("%d\n",a[i]);
	}

	printf("Found at index:%d\n",binary_search(a,8,35));
	return 0;
}
