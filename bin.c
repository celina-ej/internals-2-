#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct timeval t0;
struct timeval t1;
float elapsed;

float timedifference_msec(struct timeval t0,struct timeval t1)
{
	return(t1.tv_sec - t0.tv_sec) *1000.0f + (t1.tv_usec - t0.tv_usec)/1000.f;
}

int binsearch(long arr[],int l,int r,int key)
{
	gettimeofday(&t0,NULL);
	while(l<=r)
	{
		int m = (l+r)/2;
		if (arr[m]==key)
		{
			return m;
		}
		if (arr[m]<key)
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	gettimeofday(&t1,NULL);
	elapsed = timedifference_msec(t0,t1);
	printf("Code executed in %f milliseconds.\n", elapsed);
	return -1;
}
void main()
{
	long *arr;
	int key,num,i,x,pos,y,temp,result;
	printf("Enter number of elements in array :");
	scanf("%d",&num);
	arr =(long *)malloc(sizeof(long)*num);
	srand( (unsigned) time(NULL) * getpid());
	if(arr !=NULL)
	{
		for (i =0;i< num;i++)
		{
			arr[i] = rand()%100;
		}
	}
	for(x=0;x<num -1;x++)
	{
		pos = x;
		for(y=x+1;y<num;y++)
		{
			if(arr[pos]>arr[y])
			{
				pos=y;
			}
		}
		if (pos!=x)
		{
			temp=arr[x];
			arr[x]=arr[pos];
			arr[pos]=temp;
		}
	}
	printf("Enter element to be found :");
	scanf("%d",&key);
	result = binsearch(arr,0,num-1,key);
	if (result==-1)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element found\n");
	}	
}
