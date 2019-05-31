//定义一个函数指针类型。比如你有三个函数
#include<stdio.h>
void hello(void) { printf("你好!\n"); }
void bye(void) { printf("再见\n"); }
void ok(void) { printf("好的\n"); }
typedef void (*funcptr)(void);//这样就构造了一个通用的函数你用的时候可以这样：
void speak(int id)
{   
	funcptr words[3] = {&hello, &bye, &ok};  
      funcptr fun = words[id];  
	  (*fun)();
}
//这样的话，如果speak(0)就会显示“你好！”
//speak(1)就会显示“再见！”speak(2)就会显示“好的！
//”用于处理参数和返回值的形式都一样，但是功能不确定的一组函数，
//可以使用函数指针。比如算术运算符，加、减、乘、除，都可以用
//typedef int (*calc)(int,int)代表，等等

int  main(void)
{
	speak(0);
	speak(1);
	speak(2);
	printf("%d\n",sizeof(void*));
}
