#include<stdio.h> 
#include<stdlib.h>
#include <conio.h>



void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

int main() 
{ 
	int lx,rx;
	int n,i,j;
	int val,run =0;
	char str[12];
	char tim[10];
	
	printf("Enter number of Process: "); 
	scanf("%d",&n); 
	int at[n],bt[n],ct[n+1],wt[n],tat[n],p[n],st[n+1],gc[n];
	
	for(i=0;i<n;i++)
    {
        printf("Enter the process number   : ");
        scanf("%d",&p[i]);
        printf("Enter the arival time of the above process  : ");
        scanf("%d",&at[i]);
        printf("Enter the burst time of the above process  : ");
        scanf("%d",&bt[i]);
        gc[i] = bt[i];
        run+=bt[i];
    }
	printf("Given Data\n");
    for(i=0;i<n;i++)
    {
        printf(" %d   %d   %d  \n",p[i],at[i],bt[i]);
    }
        
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (p[j] >p[j+1])
            {
                swap(&p[j], &p[j+1]);
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
            }
        }  
    }
    
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (bt[j] >bt[j+1])
            {
                swap(&p[j], &p[j+1]);
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
            }
        }  
    }
    
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (at[j] >at[j+1])
            {
                swap(&p[j], &p[j+1]);
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
            }
        }  
	}

	int temp = 1;
	int time =0;
	float aw = 0.0;
    while(run > 0)
    {
    	int ind = 0;
	
    	val = 100;
        ind = n;
        for (j = 0 ; j < n; j++)
        {
        	if (bt[j] < val && bt[j]>0 && at[j] <= time)
        	{
				ind = j;
                val = bt[j];  
            }
    	}
    	
        time = time+1;
    	bt[ind] = bt[ind] - 1;	
		if(ind!=n)
		{
			run-=1;	
		}
		if(bt[ind]==0)
    	{
    		ct[ind] = time;
            tat[ind] = ct[ind] - at[ind];
            wt[ind] = tat[ind] - gc[ind];
        }
	}
	
	printf("processed data \n");
    for(i=0;i<n;i++)
    {
        printf(" %2d   %2d   %2d   %2d   %2d   %2d  \n",p[i],at[i],gc[i],ct[i],tat[i],wt[i]);
		aw = aw + wt[i];   
    }
    aw = (aw/n);
    printf("Awerage Waiting Time is =  %f",aw);
}
