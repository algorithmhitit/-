#include<stdio.h>

int N,x;//���� , ����    
int  L[101],C[101];//����,���� ª���� 
	
int add,count=0;
	

int c(int i,int j);
int main()
{
	//������ ����,���� �˰����� ��   
	//x��ŭ�� ���� ����� ��� ����?  ����� <2,147,483,647
	
	scanf("%d %d",&N,&x);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&L[i],&C[i]);
	}
	/*for(int i=0;i<=C[2];i++)
	{
		for(int j=0;j<=C[1];j++)
		{
			for(int k=0;k<=C[0];k++)
			{
				add = L[2]*k+L[1]*j+L[0]*i;
				if(add==x)
				{
					count++;
				}
			}
		}
	}*/
	
	c(0,0);
	printf("%d\n",add);
	//printf("%d",count);
	
}
int c(int i,int j) 
{
	i++;
	if(i<N)
	{
		for(int k=0;k<C[i];k++)
		{
			c(i,k);
		}
		
	}
	return L[i]*j;
}
