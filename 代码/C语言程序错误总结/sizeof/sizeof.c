#include <stdio.h>
 //�趨һ���ֽڶ��룬���û�д˾������Ĭ�����ֽڶ���,int �����ݵ�ַ�����λΪ0��һ�α�ɶ���ȫ�����ݣ��ٶȿ졣
// �ڽṹ���в���4�ֽ�Ҳ��ռ�����ֽ�
#pragma pack (4)
typedef struct student{
	char num;//�趨һ�ֽڶ���ʱռ��1�ֽڣ�Ĭ��ռ�����ֽ�
	int  score;//4�ֽ�	
}stu1;

stu1 a[10];
char b[10];
stu1 *p=&a[0];


void main()
{
	char i;
	int c=0,d=0;
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(b[0]));
	printf("%d\n",sizeof(b));
	printf("%d\n",sizeof(int));
	//Ϊʲô��20��������Ĭ�����ֽڶ���
	printf("%d\n",sizeof(a[0]));
	printf("%d\n",sizeof(p));//4,ָ�������ֽڴ洢2^32=4G
	printf("%d\n",sizeof(a));
	for(i=0;i<5;i++);
	printf("%d\n",i); 
	printf("%d\n",&p->score);//427E64
	printf("%d\n%d\n",&c,&d);//12FF40,12FF3C

}
			   //���浱ǰ������ƿ�ָ��