//����һ������ָ�����͡�����������������
#include<stdio.h>
void hello(void) { printf("���!\n"); }
void bye(void) { printf("�ټ�\n"); }
void ok(void) { printf("�õ�\n"); }
typedef void (*funcptr)(void);//�����͹�����һ��ͨ�õĺ������õ�ʱ�����������
void speak(int id)
{   
	funcptr words[3] = {&hello, &bye, &ok};  
      funcptr fun = words[id];  
	  (*fun)();
}
//�����Ļ������speak(0)�ͻ���ʾ����ã���
//speak(1)�ͻ���ʾ���ټ�����speak(2)�ͻ���ʾ���õģ�
//�����ڴ�������ͷ���ֵ����ʽ��һ�������ǹ��ܲ�ȷ����һ�麯����
//����ʹ�ú���ָ�롣����������������ӡ������ˡ�������������
//typedef int (*calc)(int,int)�����ȵ�

int  main(void)
{
	speak(0);
	speak(1);
	speak(2);
	printf("%d\n",sizeof(void*));
}
