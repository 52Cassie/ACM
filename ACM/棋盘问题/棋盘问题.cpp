#include<stdio.h>

 int chess[5][5];

int nextxy(int *x,int *y,int count)
{
	switch(count)
	{
	case 0://shang
		if(*x-1>=0 && !chess[*x-1][*y])
		{
			*x -= 1;
			return 1;
		}
		break;
	case 1://xia
		if(*x+1<=4 && !chess[*x+1][*y])
		{
			*x += 1;
			return 1;
		}
		break;
	case 2://zuo
		if( *y-1>=0 && !chess[*x][*y-1])
		{
			*y -= 1;
			return 1;
		}
		break;
	case 3://you
		if(*y+1<=4 && !chess[*x][*y+1])
		{
			*y += 1;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}



int travelchess(int x,int y,int tag)
{
	int x1=x,y1=y,count=0;
	chess[x][y]=tag;

	if(x==4 && y==4)
		return 1;

	int flag=0;
	flag=nextxy(&x1,&y1,count);

	while(!flag && count < 4)
	{
		count ++;
		flag=nextxy(&x1,&y1,count);	
	}

	while(flag)
	{
		if(travelchess(x1,y1,tag+1))
		{
			return 1;
		}
		x1=x;
		y1=y;
		count++;

		flag=nextxy(&x1,&y1,count);

		while(!flag && count < 4)
		{
			count ++;
			flag=nextxy(&x1,&y1,count);	
		}
	}

	if(0==flag)
		chess[x][y]=0;

	return 0;

}

void print()
{
	int i, j,tag=2;
	while(i!=4||j!=4)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(chess[i][j]==tag)
				{
					printf("(%d,%d)\n",i,j);
					tag++;
				}
			}
		}
	}
	printf("\n");
}

int main()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&chess[i][j]);
		}
	}
	travelchess(0,0,2);
	print();

	return 0;
}