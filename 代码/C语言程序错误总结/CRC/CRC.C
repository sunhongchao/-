#include <stdio.h>
unsigned short ccitt16=0x1021;//0x8005;

unsigned short crc16_ccitt(unsigned char data,unsigned short crc)
{
	
	char i;
	crc^=(data<<8);//新的数与原来的余数相加。相加就是异或。进位不管
	for(i=0;i<8;i++)
	{
		if(crc&0x8000)
		{
			crc<<=1;
			crc^=ccitt16;
		}
		else
			crc<<=1;

	}
	return crc;
}
void main() 
{ 
 char  i; 
 unsigned short crc;  
 unsigned char data[5] = { 0x71, 0x88, 0x93, 0xa5, 0x13 }; /* 计算这5个数据的CRC校验码 */ 
 crc = 0;  
 for (i=0; i<5; i++)  
 {  
	 crc = crc16_ccitt(data[i], crc);
 } 
 printf("crc is %x\n", crc);
 crc=0;
crc = crc16_ccitt(data[0], crc);
 printf("crc is %x", crc); 
}  