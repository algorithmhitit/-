#include<stdio.h>
int list[100000];
int sorted[100000];

void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* ���� ���ĵ� list�� �պ� */
  while(i<=mid && j<=right){
    if(list[i]<=list[j]){	
      sorted[k++] = list[i++];
      
    }else{
      sorted[k++] = list[j++];
     
  	}
  }

  // ���� �ִ� ������ �ϰ� ����
  if(i>mid){
    for(l=j; l<=right; l++){
      sorted[k++] = list[l];
   	}
  }
  // ���� �ִ� ������ �ϰ� ����
  else{
    for(l=i; l<=mid; l++){
      sorted[k++] = list[l];
    }
  }

  // �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// �պ� ����
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
    merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
    merge_sort(list, mid+1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
    merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
  }
}

int main()
{
	int N,S,total=0,c=0;
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&list[i]);
	}
	merge_sort(list,0,N-1);//����
	//���ϱ�,�� 
	for(int i=0;i<N;i++)
	{
		printf("%d ",list[i]);
	}
	printf("\n");
	for(int i=N-1;i>=0;i--)
	{
		if(S>total){
			total=total+list[i];
			c++;
			printf("%d %d %d\n",total,list[i],c);
		}else if(S<=total)
		{
			printf("%d",c);
			break;
		}
	}
	if(S>total)
	{
		printf("0");
	}
}
