#include<stdio.h>
#define a
#define b
unsigned char reg=0xff,clear_mask=0x01,set_mask=0;

int main(void)
{
   #ifdef a
	printf("a");
	#else 
	#ifdef b
	printf("b");
	#endif
  #endif
	printf("\n%x",((reg&~clear_mask)|set_mask));
	return 0;
}
