#include <stdio.h>
#define u32 unsigned int
unsigned char TEXT_Buffer[3]={0XFA,0X1E,0X00};
unsigned int  a;
unsigned short b;
void main()
{
	a=((u32)TEXT_Buffer[0]&0x00FF)|(( (u32)TEXT_Buffer[1]&0x00FF)<<8)|(( (u32)         TEXT_Buffer[2]&0x00FF)<<16 );
	b=a/506;
	printf("%d",b);
}
