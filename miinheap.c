#include <stdio.h>
int b[100],countmin=0;
int insert(int n)
{
	countmin++;
	b[countmin]=n;
	int w=countmin;
	while(b[w]<b[w/2] && w>1)
	{
		int t=b[w];
		b[w]=b[w/2];
		b[w/2]=t;
		w=w/2;
	}
}

int min1(int re,int rt)
{
	if(re > rt)
		return rt;
	else
		return re;
}


void delete()
{
	b[1]=b[countmin];
	countmin--;
	int i=1,ind;
	while( min1(b[2*i],b[2*i+1]) < b[i])
	{
		if(b[2*i]< b[2*i+1])
		{
			ind=2*i;
		}
		else
			ind=2*i+1;
		if(ind>countmin)
			break;
		int t=b[ind];
		b[ind]=b[i];
		b[i]=t;
		i=ind;
	}
}

int main()
{
	while(1)
	{
		int i,r;
		char c1;
		scanf("%c",&c1);
		if(c1=='p')
		{
			scanf("%d",&r);
			insert(r);
			for(i=1;i<=countmin;i++)
			{
				printf("%d ",b[i]);
			}
			printf("\n");
		}
		else if (c1=='d')
		{
			delete();
			for(i=1;i<=countmin;i++)
			{
				printf("%d ",b[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
