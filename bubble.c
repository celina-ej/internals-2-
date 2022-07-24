#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
float timedif(struct timeval t0,struct timeval t1)
{
	return	(t1.tv_sec - t0.tv_sec) +1000.0f + (t1.tv_usec - t0.tv_usec)/1000.0f;
}
void printarray(int *array,int n)
{
	printf("\nThe given array is \n\n");
	for(int i=0;i<n;i++)
	{
		printf("|%d|",*(array +i));
	}
}

int bubble(int *array,int n)
{
	int temp;
	for( int m=0;m<n;m++)
	{
		for(int p=0;p<n-m-1;p++ )
		{
			if(array[p]>array[p+1])
			{
				temp=array[p];
				array[p]=array[p+1];
				array[p+1]=temp;		
			}
	
		}
	}
}

int insertion(int *array,int n)
{
	int t=0,flag=0,d;
	for(int m=1;m<n;m++)
	{
		t=array[m];
		for(d=m-1;d>=0;d--)
		{
			if(array[d]>t)
			{
				array[d+1]=array[d];
				flag =1;
			}
			else
				break;
		}
		
		if(flag)
		{
			array[d+1]=t;
		}
	}
	
}
int selection(int *array,int n)
{
	int pos,temp;
	for(int m=0;m<n-1;m++)
	{
		pos=m;
		for(int p=m+1;p<n;p++)
		{
			if(array[pos]>array[p])
			{
				pos=p;
			}
	
		}
		if(pos!=m)
		{
			temp=array[m];
			array[m]=array[pos];
			array[pos]=temp;
		}
	}	
}	
int main()
{	
	struct timeval t0,t1;
	float elapsed;
	while (1)
	{	
		printf("MENU\n1.Bubble Sort\n2.Insertion sort\n3.Selection sort\n4.Quit\nEnter your choice");
		int choice,*arr,size;
		scanf("%d",&choice);
		if (choice!=4)
		{	
			printf("Enter the number of elements");
			scanf("%d",&size);
			arr=(int*)malloc(sizeof(int)*size);
			srand((unsigned) time(NULL)*getpid());
			if (arr!=NULL)
			{
				for (int j=0;j<size;j++)
				{
					arr[j]=rand()%100;
				}
			}
			printarray(arr,size);
		}
		switch(choice)
		{
			case 1:
				{
					gettimeofday(&t0,NULL);
					bubble(arr,size);
					gettimeofday(&t1,NULL);
					printarray(arr,size);
					elapsed=timedif(t0,t1);
					printf("\n\nThe time taken to sort %f milliseconds\n\n",elapsed);
					free(arr);
					break;
				}
			
			case 2:
				{
					gettimeofday(&t0,NULL);
					insertion(arr,size);
					gettimeofday(&t1,NULL);
					printarray(arr,size);
					elapsed=timedif(t0,t1);
					printf("\n\nThe time taken to sort %f milliseconds\n\n",elapsed);
					free(arr);
					break;
				}
			
			case 3:
				{
					gettimeofday(&t0,NULL);
					selection(arr,size);
					gettimeofday(&t1,NULL);
					printarray(arr,size);
					elapsed=timedif(t0,t1);
					printf("\n\nThe time taken to sort %f milliseconds\n\n",elapsed);
					free(arr);
					break;
				}
			case 4:
				printf("\nGood Bye\n");
				exit(0);
			default:
				printf("Invalid option");
				break;
		}
	}
}
