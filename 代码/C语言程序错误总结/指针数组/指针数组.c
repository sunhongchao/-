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
/*ѡ�������˼�룬��ð�ݷ��ĸĽ���ð�ݷ�û�Ƚ�һ�ν���һ��λ�ã���ѡ�񷨱�ǣ�ÿ�αȽ�ֻ����һ��λ��
��1�ˣ��ڴ������¼r[1]~r[n]�б�ǳ���С�ļ�¼��������r[1]������
��һ�����K�����С������λ�ã��ñ�ǵ�����֮������Ƚϣ����֮�����С���͸��±��
�Ƚ���ϣ��ͽ���ǵ������һ����������
��2�ˣ��ڴ������¼r[2]~r[n]��ѡ����С�ļ�¼��������r[2]������
�Դ����ƣ���i���ڴ������¼r[i]~r[n]��ѡ����С�ļ�¼��������r[i]������
ʹ�������в�������ֱ��ȫ��������ϡ�*/
void sort(char *name[],int n)
{
	char *temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{k=i;
	for(j=i+1;j<n;j++)
		if(strcmp(name[k],name[j])>0)
			k=j;//kʼ�ձ����С�����������Ƶ���ǰλ��
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

