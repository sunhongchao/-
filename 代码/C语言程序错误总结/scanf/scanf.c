/*ptcb->OSTCBY       = (INT8U)(prio >> 3u);			 //����λ������λ��
ptcb->OSTCBX       = (INT8U)(prio & 0x07u);
ptcb->OSTCBBitY    = (OS_PRIO)(1uL << ptcb->OSTCBY); //�趨��������Ӧλ��1
ptcb->OSTCBBitX    = (OS_PRIO)(1uL << ptcb->OSTCBX);
OSRdyGrp          |= ptcb->OSTCBBitY;                /*����������������*/
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
//�˴������ֵ����ô�ͻ�ʹprio ��OSRdyGrpռ�����ٵĿռ䡣��ʹ��scanf��%d,32λ����ʱ���ὫOSRdyGrp�ռ�����
//����취������һ����ʱ�Ŀռ�TEMPȡֵ��Ȼ�󸳸�prio
unsigned char prio=0;
unsigned char OSRdyGrp=0;
char OSRdyTbl[lowest_prio/8+1];
void Rdy()
{
	 
	char i; 
	int temp;//��ʱ�ռ乩SCANF����ʹ��
	printf("�������ȼ�:");
	scanf("%d",&temp);//�ô˺����������ֻ����32λ������Ϊchar����
	prio=(unsigned char)temp;
	OSRdyGrp|=(1<<(prio>>3));
    printf("���ȼ���:\n");
    printf("%d\n",OSRdyGrp);
	OSRdyTbl[prio>>3]|=(1<<(prio&0x07));
	printf("���ȼ���:\n");
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
//����ֵ10��20
//���н��
 /*OSRdyTbl[1]= 4=0000 0100;
 OSRdyTbl[2]=16=0001 0000

OSRdyTbl[prio>>3]|=1<<(prio&0x07);

//���Ͼ��ֽ�
ptcb->OSTCBX  = (INT8U)(prio & 0x07u);
ptcb->OSTCBBitX  = (OS_PRIO)(1uL << ptcb->OSTCBX);
ptcb->OSTCBY  = (INT8U)(prio >> 3u);	
OSRdyTbl[ptcb->OSTCBY]|= ptcb->OSTCBBitX;

OSRdyGrp|=1<<(prio>>3);

ptcb->OSTCBY  = (INT8U)(prio >> 3u);
ptcb->OSTCBBitY    = (OS_PRIO)(1uL << ptcb->OSTCBY);*/
//OSRdyGrp       |= ptcb->OSTCBBitY; 
