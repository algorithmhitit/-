#include<stdio.h>
 
int main()
{
	int N,S,t=0;  //����,����,�� 
	//int c=0;//���ڱ���
	scanf("%d %d",&N,&S);
	int a[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	//a[0]����a[N]���� ���ؼ� �ƴϸ�,0
	for(int i=0;i<N;i++)
	{
		t=t+a[i];
	}
	if(t<S)
	{
		printf("0");
		return 0;
	}
	t=0;
	int c=0;
	//1��° ���� 1,2,3,4,5,6...N,�ƴϸ� ī��� +1
	for(;c<N-1;c++)
	{
		for(int i=0;i<N-c;i++)
		{
			for(int j=i;j<=i+c;j++)
			{
				
			t=t+a[j];
			}
			printf("%d\n",t);
			if(t>=S)
			{
				break;
			}
			t=0;
		}
		if(t>=S)
		{
			break;
		}
	}	
	printf("%d",c+1);
}
 
