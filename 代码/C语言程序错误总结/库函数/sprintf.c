#include<stdio.h>
#include<string.h>
char BufNetFrameData[256];
char data[20]={0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,0x34};
char hex_2_ascii(char *data, char *buffer, char len) 
{ 
    char  ascTable[17] = {"0123456789ABCDEF"}; //双引号里面实际上是0——F的ASCii码
    char *tmp_p = buffer; 
     
    char i, pos=0; 
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
void Upload_NetData(char *data_buf,char datalen)
{
	char temp_len=0;
	char *buf_write_ptr;
	
	
	
	buf_write_ptr=BufNetFrameData;
	memset(BufNetFrameData,0,256);
    temp_len=sprintf((char*)BufNetFrameData,"AT+ZIPSEND=1,%d",datalen*2);
	buf_write_ptr+=temp_len;
	//printf(BufNetFrameData);
	temp_len=hex_2_ascii(data_buf, (char *)buf_write_ptr, datalen);
	buf_write_ptr+=temp_len;
	printf(BufNetFrameData);

}
int main(void)
{
	unsigned char len;
	char buf[20];
    //sprintf((char*)buf,"AT+ZIPSEND=1,%d",10);
	//printf(buf);
	/*len=sprintf(buf,"ILOVEYOU%d",111);
	printf("%d\n",len);
	printf(buf);
	printf("\n");*/
	Upload_NetData(data,7);
	return 0;
}