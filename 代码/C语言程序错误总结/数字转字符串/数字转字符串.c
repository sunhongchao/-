//该文档用于十六进制数字转字符串

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define uint8 unsigned char
#define u8 uint8
#define u32 unsigned int 
#define HI_UINT8(a)   ((a>> 4) & 0x0F)
#define LO_UINT8(a)   (a & 0x0F)
/*u32 hex_2_ascii(u8 *data, char *buffer, u32 len)
{
    char  ascTable[17] = {"0123456789ABCDEF"};
    char *tmp_p = buffer;

    u32 i, pos=0;
    if(len == 0)
       return 0;

    for(i = 0; i < len; i++)
    {
         tmp_p[pos++] = ascTable[data[i] >> 4];
         tmp_p[pos++] = ascTable[data[i] & 0x0f];
    }

    tmp_p[pos] = '\0';

    return pos;
}*/



//单个数字转字符
uint8 aHexToAsc(uint8 aHex)
{    
     
 if((aHex>=0)&&(aHex<=9))       
    aHex += 0x30;    
  else if((aHex>=10)&&(aHex<=15))//A-F       
    aHex += 0x37;    
   else aHex = 0xff;    
  return aHex;
}
//数字转字符串
/*uint8* ToString(uint8 *pstring,uint8 *phex,uint8 len)
{
	 
	while(len--)
	{
      	*pstring--=aHexToAsc(LO_UINT8(*phex));
		*pstring--=aHexToAsc(HI_UINT8(*phex++));
     }
	
	 return (pstring+1);//返回首地址
}*/

uint8* ToString(uint8 *pstring,uint8 *phex,uint8 len)
{
	 uint8 tmp;
	 uint8 *pbuf,*buf;
	 
	 pbuf=pstring;
	 tmp=len*2;
	 
    // buf=(uint8*)malloc(len*sizeof(uint8));
	 buf=(uint8*)malloc(len*2*sizeof(uint8));//申请len*2字节空间
	 memset(buf,0,len*2);
    if(NULL!=buf)//防止申请失败
    
	{
	  
	  while(len--)
	   {
      	*buf++=aHexToAsc((uint8)LO_UINT8(*phex));

		*buf++=aHexToAsc((uint8)HI_UINT8(*phex++));
	   }
        
	  while(tmp--)
	  {
		  *pbuf++=*(--buf);
	  }
	
	}
	 free(buf);
	 buf=NULL;//防止野指针
	 return (pstring);//返回首地址
}


/*int main(void)
{
  
    uint8 hexstr[4];
    uint8 *P;
	unsigned int temp=0x1B;//CD;
	
	P=ToString(&hexstr[0],(uint8*)&temp,2);
	
	//printf("%d",sizeof(unsigned int));
	printf("%c%c%c%c\n",hexstr[0],hexstr[1],hexstr[2],hexstr[3]);
	printf("%c%c%c%c\n",*(P),*(P+1),*(P+2),*(P+3));

	return 0;
}*/
/*****************************************************************/
u32 hex_2_ascii(u8 *data, u8 *buffer, u32 len)//字节数
{
   u8  ascTable[17] = {"0123456789ABCDEF"};
    u8 *tmp_p = buffer;

    u32 i, pos=0;
    if(len == 0)
       return 0;

    for(i = 0; i < len; i++)
    {
         tmp_p[pos++] = ascTable[data[i] >> 4];
         tmp_p[pos++] = ascTable[data[i] & 0x0f];
    }

    tmp_p[pos] = '\0';

    return pos;
}
int main(void)
{
	u8 tdata=0xA5;
	u8 tbuf[2];
	hex_2_ascii(&tdata, tbuf, 1);//字节数
	printf("%c%c",tbuf[0],tbuf[1]);
	return 0;
}