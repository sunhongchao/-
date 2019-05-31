#include<stdio.h>
#include<string.h>
int main()
{
	void sort(char *name[],int n);
	void print(char *name[],int n);
	char *name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer designer"};
	int n=5;
	sort(name,n);
	print(name,n);
	return 0;
}
/*选择法排序的思想，是冒泡法的改进，冒泡法没比较一次交换一次位置，而选择法标记，每次比较只交换一次位置
第1趟，在待排序记录r[1]~r[n]中标记出最小的记录，将它与r[1]交换；
用一个标号K标记最小数所在位置，用标记的数与之后的数比较，如果之后的数小，就更新标记
比较完毕，就将标记的数与第一个数交换。
第2趟，在待排序记录r[2]~r[n]中选出最小的记录，将它与r[2]交换；
以此类推，第i趟在待排序记录r[i]~r[n]中选出最小的记录，将它与r[i]交换，
使有序序列不断增长直到全部排序完毕。*/
void sort(char *name[],int n)
{
	char *temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{k=i;
	for(j=i+1;j<n;j++)
		if(strcmp(name[k],name[j])>0)
			k=j;//k始终标记最小的数，将其移到最前位置
		if(k!=i)
		{temp=name[i],name[i]=name[k],name[k]=temp;}
	}

}
void print(char *name[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",name[i]);
}

