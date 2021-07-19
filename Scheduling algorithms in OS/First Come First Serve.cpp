#include<stdio.h>
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
main()
{
	int i,j,n;
	printf("enter no of process");
	scanf("%d",&n);
	int pno[n],at[n],bt[n],ct[n],tat[n],wt[n];
	for(i=0;i<n;i++)
	{
		printf("enter process no for pno[%d]\n",i);
		scanf("%d",&pno[i]);
		printf("enter arrival time for at[%d]\n",i);
		scanf("%d",&at[i]);
		printf("enter burst time for bt[%d]\n",i);
		scanf("%d",&bt[i]);
	}
	printf("given inputs are\n");
	printf("pno\tat\tbt\t");
	for(i=0;i<n;i++)
	{
		printf("\n%d\%d\t%d\t ",pno[i],at[i],bt[i]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
				swap(at[i],at[j]);
				swap(pno[i],pno[j]);
				swap(bt[i],bt[j]);
			}
			else
			{
			if(at[i]==at[j])
			{
				if(pno[i]>pno[j])
				{
				swap(at[i],at[j]);
				swap(pno[i],pno[j]);
				swap(bt[i],bt[j]);
			    }
			}
		   }
		}
	}
	printf("\pno\tat\tbt\tct\ttat\twt\t");
	ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		ct[i]=bt[i]+ct[i-1];
	}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t",pno[i],at[i],bt[i],ct[i],tat[i],wt[i]);
		printf("\n");
	}
}
