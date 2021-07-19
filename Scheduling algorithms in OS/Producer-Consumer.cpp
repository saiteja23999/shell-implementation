#include<stdio.h>
#include<stdlib.h>
int full=0,empty,mutex=1,x=0;
void producer();
void consumer();
int wait(int s)
{
	return --s;
}
int signal(int s)
{
	return ++s;
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("Produced item: %d",x);
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	x--;
	printf("Consumed item: %d",x);
	mutex=signal(mutex);
}
main()
{
	int ch,n;
	printf("Enter the storage capacity");
	scanf("%d",&n);
	empty=n;
	while(1)
	{
		printf("\nMenu:");
		printf("\n1.Produce");
		printf("\n2.Consume");
		printf("\n3.Storage status");
		printf("\n4.Exit");
		printf("\nChoose the option");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(full!=n && mutex!=0)
					{
						producer();	
					}
					else
					{
						printf("Unable to proceed");
					}
					break;
			case 2: if(full!=0 && mutex!=0)
					{
						consumer();	
					}
					else
					{
						printf("unable to process");
					}
					break;
			case 3: printf("%d",full);
					break;
			case 4: exit(1);
		}
	}
}
