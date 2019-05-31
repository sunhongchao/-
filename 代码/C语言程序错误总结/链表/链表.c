/*struct node{
	int value;
	struct node *next;
}
struct node *first=NULL;//跟踪链表位置,并不仅仅指向首个结构数据

struct node *new_node;//动态申请内存，返回的是指向空间的起始地址
new_node=malloc(sizeof(struct node));
(*new_node).value=10;
new_node->value=10;

next_node->next=first;//忽略
first=new_node;//first 指向new_node*/
typedef struct NODE{
	struct NODE *fwd;
	struct NODE *bwd;
	int         value;
}Node;
Node *rootp;//根指针
双向链表插入
int dll_insert(Node *rootp,int value)
{
	Node *this;
	Node *next;
	Node *newnode;
	for(this=rootp;(next=this->fwd)!=NULLL;this=next){
		if(next->value ==value)//已存在该项
			return 0;
		if(next->value >value)//找到插入位置
			break;
	}
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)//没有足够的空间
		return -1;
	newnode->value =value;
	if(next!=NULL){//并非位于链表的结尾
		if(this!=rootp){//并非位于链表的起始位置，即位于链表中间，情况1
			newnode->fwd =next;
			this->fwd=newnode;
			newnode->bwd =this;
			next->bwd=newnode;
		}
		else{//插入位置在于链表的起始位置
			newnode->fwd =next;
			rootp->fwd =newnode;
			newnode->bwd =NULL;
			next->bwd =newnode;
		}
	}
	else{//位于链表的结尾
		if(this!=roop){//不在链表的首部
			newnode->fwd =NULL;
			this->fwd=newnode;
			newnode->bwd =this;
			rootp->bwd =newnode;
		}
		else{//在链表首部，也在链表尾部，即源链表空
			newnode->fwd =NULL;
			rootp->fwd =newnode;
			newnode->bwd =NULL;
			rootp->bwd =newnode;
		}
	}
	return 1;//插入成功
}
简化插入技巧之后的函数，可以使程序精炼，但是不利于理解
简化启示函数：
if(x==3){
	i=1;
	something;
	j=2;
}
else{
	i=1;
	something different;
	j=2;
}
不管X==3的值是真还是假，语句i=1和j=2都执行，并且不会影响测试结果
可改为：
	i=1;
if(x==3){
	something;	
}
else{
	something different;	
}
j=2;
int dll_insert(Node *rootp,int value)
{
	Node *this;
	Node *next;
	Node *newnode;
	for(this=rootp;(next=this->fwd)!=NULLL;this=next){
		if(next->value ==value)//已存在该项
			return 0;
		if(next->value >value)//找到插入位置
			break;
	}
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)//没有足够的空间
		return -1;
	newnode->value =value;

	if(next!=NULL){//并非位于链表的结尾
		newnode->fwd =next;//此句不论哪种情况都会执行，而且不影响结果
		if(this!=rootp){//并非位于链表的起始位置，即位于链表中间，情况1
			this->fwd=newnode;
			newnode->bwd =this;
				}
		else{//插入位置在于链表的起始位置			
			rootp->fwd =newnode;
			newnode->bwd =NULL;
				}
			next->bwd =newnode;
	}
	else{
			newnode->fwd =NULL;
		if(this!=roop){
		
			this->fwd=newnode;
			newnode->bwd =this;
			
		}
		else{
		
			rootp->fwd =newnode;
			newnode->bwd =NULL;
			
		}
		rootp->bwd =newnode;
	}
	return 1;//插入成功
}
逻辑简化插入函数：
if(pointer !=NULL)
	field=pointer;
else
	fileld=NULL;
简化后：
field=pointer;
假如pointer!=NULL,
那么filed=pointer;filed 得到pointer的值
如果Pointer==NULL;
执行filed=pointer;之后filed=pointer=NULL
·····
精简后的最终版本：

int dll_insert(Node *rootp,int value)
{
	Node *this;
	Node *next;
	Node *newnode;
	for(this=rootp;(next=this->fwd)!=NULLL;this=next){
		if(next->value ==value)//已存在该项
			return 0;
		if(next->value >value)//找到插入位置
			break;
	}
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)//没有足够的空间
		return -1;
	newnode->value =value;
    newnode->fwd =next;
	this->fwd=newnode;
	if(next!=NULL){//并非位于链表的结尾
		//此句不论哪种情况都会执行，而且不影响结果
		
		if(this!=rootp){//并非位于链表的起始位置，即位于链表中间，情况1
			
			newnode->bwd =this;
				}
		else{//插入位置在于链表的起始位置			
			this->fwd =newnode;
			newnode->bwd =NULL;
			}
			next->bwd =newnode;
	}
	if(next!=NULL){
		
		if(this!=roop){
		
			this->fwd=newnode;
			newnode->bwd =this;	
		}
		else{
		
			rootp->fwd =newnode;
			newnode->bwd =NULL;
			
		}
		rootp->bwd =newnode;
	}
	return 1;//插入成功
}