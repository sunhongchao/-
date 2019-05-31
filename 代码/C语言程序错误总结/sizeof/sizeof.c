#include <stdio.h>
 //设定一个字节对齐，如果没有此句编译器默认四字节对齐,int 型数据地址最低两位为0，一次便可读出全部数据，速度快。
// 在结构体中不足4字节也会占用四字节
#pragma pack (4)
typedef struct student{
	char num;//设定一字节对齐时占用1字节，默认占用四字节
	int  score;//4字节	
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
	//为什么是20？编译器默认四字节对齐
	printf("%d\n",sizeof(a[0]));
	printf("%d\n",sizeof(p));//4,指针是四字节存储2^32=4G
	printf("%d\n",sizeof(a));
	for(i=0;i<5;i++);
	printf("%d\n",i); 
	printf("%d\n",&p->score);//427E64
	printf("%d\n%d\n",&c,&d);//12FF40,12FF3C

}
			   //保存当前任务控制块指针