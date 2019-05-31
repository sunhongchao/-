/*ptcb->OSTCBY       = (INT8U)(prio >> 3u);			 //高三位决定列位置
ptcb->OSTCBX       = (INT8U)(prio & 0x07u);
ptcb->OSTCBBitY    = (OS_PRIO)(1uL << ptcb->OSTCBY); //设定就绪表相应位置1
ptcb->OSTCBBitX    = (OS_PRIO)(1uL << ptcb->OSTCBX);
OSRdyGrp          |= ptcb->OSTCBBitY;                /*将任务放入就绪表中*/
/*OSRdyTbl[ptcb->OSTCBY]|= ptcb->OSTCBBitX;
prio=10 =0000 1010
ptcb->OSTCBY=prio>>3=0000 0001=1
ptcb->OSTCBX =prio & 0x07u=0000 0010=2;
ptcb->OSTCBBitY=1<<1=0000 0001=1;
ptcb->OSTCBBitX=1<<2=0000 0100=3;
OSRdyGrp        |= 0000 0001
OSRdyTbl[1]|= 0000 0100;*/
#include <stdio.h>
#define lowest_prio 63
//此处如果赋值，那么就会使prio 和OSRdyGrp占用相临的空间。当使用scanf按%d,32位输入时，会将OSRdyGrp空间清零
//解决办法，分配一个临时的空间TEMP取值，然后赋给prio
unsigned char prio=0;
unsigned char OSRdyGrp=0;
char OSRdyTbl[lowest_prio/8+1];
void Rdy()
{
	 
	char i; 
	int temp;//临时空间供SCANF函数使用
	printf("输入优先级:");
	scanf("%d",&temp);//用此函数输入的数只能是32位，定义为char出错
	prio=(unsigned char)temp;
	OSRdyGrp|=(1<<(prio>>3));
    printf("优先级组:\n");
    printf("%d\n",OSRdyGrp);
	OSRdyTbl[prio>>3]|=(1<<(prio&0x07));
	printf("优先级表:\n");
	for(i=0;i<lowest_prio/8+1;i++)
	printf("%d\n",OSRdyTbl[i]);	
}
void main(void)
{
	unsigned char a=0,i=0;
	printf("%d\n",lowest_prio/8+1 );
	for(i=0;i<8;i++)
	OSRdyTbl[i]=0;
	Rdy();
	Rdy();
	Rdy();
	printf("%d\n",Rdy);
}
//输入值10；20
//运行结果
 /*OSRdyTbl[1]= 4=0000 0100;
 OSRdyTbl[2]=16=0001 0000

OSRdyTbl[prio>>3]|=1<<(prio&0x07);

//将上句句分解
ptcb->OSTCBX  = (INT8U)(prio & 0x07u);
ptcb->OSTCBBitX  = (OS_PRIO)(1uL << ptcb->OSTCBX);
ptcb->OSTCBY  = (INT8U)(prio >> 3u);	
OSRdyTbl[ptcb->OSTCBY]|= ptcb->OSTCBBitX;

OSRdyGrp|=1<<(prio>>3);

ptcb->OSTCBY  = (INT8U)(prio >> 3u);
ptcb->OSTCBBitY    = (OS_PRIO)(1uL << ptcb->OSTCBY);*/
//OSRdyGrp       |= ptcb->OSTCBBitY; 
