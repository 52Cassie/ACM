#include<stdio.h>
#include<math.h>

void choseNum(int *s,int *x,int m,int n);
bool prime(int n);
void sum(int *s,int *x,int n);
int check(int *s,int m,int n);

int add,mean;
int main()
{
	int n,k;
	int x[21],s[21] = {0};
	int i;

	FILE *fin  = fopen ("test.in", "r");
    FILE *fout = fopen ("test.out", "w");

	while(fscanf(fin,"%d%d",&n,&k))
	{
		for(i = 0;i < n;i ++)
		{
			fscanf(fin,"%d",&x[i]);
			if(i < k)
				s[i] = 1;
		}
		choseNum(s,x,n,k);
		fprintf (fout, "%d\n", mean);
	}
	return 0;
}

bool prime(int n)
{
	int i;
	for(i = 2;i <= sqrt(n);i ++)
	{
		if(n%i)
			return 0;//不是素数
	}
	return 1;//是素数
}

void sum(int *s,int *x,int n)
{
	int i;
	for(i = 0;i < n;i ++)
		if(s[i] == 1)
			add += x[i];
	if(prime(add))
		mean ++;
	add = 0;
}

void choseNum(int *s,int *x,int m,int n)
{
	 int i,j;
	 sum(s,x,m);  
	 while(1)
	 {
		  int count=0;   
		  for(i=0;i<m-1;i++)
		  {
  			 if(*(s+i)==1&&*(s+i+1)==0)
			 {
				*(s+i)=0;
				*(s+i+1)=1;
				break;
			 }
			 if(*(s+i))   
				 count++; 
		  }
		  for(j=0;j<i;j++)
		  {
			 if(j<count)   
			 {
				*(s+j)=1;
			 }
			 else        
			 {
				*(s+j)=0;
			 }
		  }
		  sum(s,x,m);
		  if(check(s,m,n)!=1)
				break;
	 }
}

int check(int *s,int m,int n)
{
	int flag=1,i; 
    for(i=0;i<m-n;i++)
	{
		if(*(s+i))
		 {
			 return  1;
		 }
	}
	return 0;
}