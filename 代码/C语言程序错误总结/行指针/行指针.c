#include <stdio.h>
/*void main()
{
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int (*p)[4]=a;
	p++;
	printf("%d",*p[0]);
}*/

void main()
{
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int (*p)[4]=a;
	//int *q=a[0];//
	int *q=&a[0][0];//二维数组当一维数组访问
	p++;
	q=q+4;
	printf("%d\n%d\n",*p[0],*q);

}