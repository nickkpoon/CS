#include <cstdio> 
#include <cstdlib>
#include <cstring>
#include <iostream>

int findMax(int ar[], int size)
{
	if(size == 0)
		return ar[0];
	int max = findMax(ar, size-1);
	if(ar[size]>max)
		return ar[size];
	else
		return max;
		
	
}

int findMin(int ar[], int size)
{
	if(size == 0)
		return ar[0];
	int min = findMin(ar, size-1);
	if(ar[size]<min)
		return ar[size];
	else
		return min;
		
	
}

int findTotal(int ar[], int size)
{
	int sum = ar[size];
	if(size == 0)
		return sum;
	else
	{
		return sum+findTotal(ar, size-1);
	}
		
	
}

int findLessThan(int ar[], int size, int n)
{
	if(size < 0)
		return 0;
	if(ar[size] < n) 
	{
		return findLessThan(ar, size-1, n) + 1;
	}
	else
		return findLessThan(ar, size-1, n);
		
	
}

int findEqual(int ar[], int size, int n)
{
	if(size < 0)
		return 0;
	if(ar[size] == n) 
	{
		return findEqual(ar, size-1, n) + 1;
	}
	else
		return findEqual(ar, size-1, n);
		
	
}

int findIndex(int ar[], int size, int n)
{
	if(size < 0)
		return 0;
	if(ar[size] == n) 
	{
		return size;
	}
	else
		return findIndex(ar, size-1, n);
		
	
}

int recursiveFun(int n,int i,int o)
{
	static int count = 0;
	if (n<=0)
		//printf("fuck \n");
		return count + 1;
		
	else
	{
		count++;
		recursiveFun(n-1,i,o);
		recursiveFun(n-1,i,o);
	}
}

static int lel = 0;
int recursive(int n)
{
	//static int count = 0;
	for(int i = 0; i<n;i+=2)
		lel++;
	if (n<=0)
		return 1;
	else
		return 1+recursive(n-1);
}

int main()
{
	int i[] = {10,100,1000,10,10,10000,10,10,10,1000000,100000};
	//printf("%i\n", sizeof(i)/sizeof(int)-1);
	printf("the max is %i \n", findMax(i, sizeof(i)/sizeof(int)-1));
	printf("the min is %i \n", findMin(i, sizeof(i)/sizeof(int)-1));
	printf("the total is %i \n", findTotal(i, sizeof(i)/sizeof(int)-1));
	printf("there are %i elements less than 10000 \n", findLessThan(i, sizeof(i)/sizeof(int)-1, 1000000));
	printf("there are %i elements equal to 10 \n", findEqual(i, sizeof(i)/sizeof(int)-1, 10));
	printf("10000 is in index %i \n", findIndex(i, sizeof(i)/sizeof(int)-1, 10000));
	int count;
	/*for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<i; j++)
		{
			count++;
			printf("%i\n", count);
		}
	}*/
	count = 4;
	printf("%i\n", recursiveFun(count,1,1));
	recursive(count);
	printf("the shit is %i\n", lel);
	/*int count1=0;
	for(int i = 0; i<count; i++)
		for(int j = 0; j < i; j++)
			count1++;
	printf("FUCKIN FOR LOOP IS %i", count1);*/

	
	
	return 0;
}

