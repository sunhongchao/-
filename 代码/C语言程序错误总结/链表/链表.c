/*struct node{
	int value;
	struct node *next;
}
struct node *first=NULL;//��������λ��,��������ָ���׸��ṹ����

struct node *new_node;//��̬�����ڴ棬���ص���ָ��ռ����ʼ��ַ
new_node=malloc(sizeof(struct node));
(*new_node).value=10;
new_node->value=10;

next_node->next=first;//����
first=new_node;//first ָ��new_node*/
typedef struct NODE{
	struct NODE *fwd;
	struct NODE *bwd;
	int         value;
}Node;
Node *rootp;//��ָ��
˫���������
int dll_insert(Node *rootp,int value)
{
	Node *this;
	Node *next;
	Node *newnode;
	for(this=rootp;(next=this->fwd)!=NULLL;this=next){
		if(next->value ==value)//�Ѵ��ڸ���
			return 0;
		if(next->value >value)//�ҵ�����λ��
			break;
	}
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)//û���㹻�Ŀռ�
		return -1;
	newnode->value =value;
	if(next!=NULL){//����λ������Ľ�β
		if(this!=rootp){//����λ���������ʼλ�ã���λ�������м䣬���1
			newnode->fwd =next;
			this->fwd=newnode;
			newnode->bwd =this;
			next->bwd=newnode;
		}
		else{//����λ�������������ʼλ��
			newnode->fwd =next;
			rootp->fwd =newnode;
			newnode->bwd =NULL;
			next->bwd =newnode;
		}
	}
	else{//λ������Ľ�β
		if(this!=roop){//����������ײ�
			newnode->fwd =NULL;
			this->fwd=newnode;
			newnode->bwd =this;
			rootp->bwd =newnode;
		}
		else{//�������ײ���Ҳ������β������Դ�����
			newnode->fwd =NULL;
			rootp->fwd =newnode;
			newnode->bwd =NULL;
			rootp->bwd =newnode;
		}
	}
	return 1;//����ɹ�
}
�򻯲��뼼��֮��ĺ���������ʹ�����������ǲ��������
����ʾ������
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
����X==3��ֵ���滹�Ǽ٣����i=1��j=2��ִ�У����Ҳ���Ӱ����Խ��
�ɸ�Ϊ��
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
		if(next->value ==value)//�Ѵ��ڸ���
			return 0;
		if(next->value >value)//�ҵ�����λ��
			break;
	}
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)//û���㹻�Ŀռ�
		return -1;
	newnode->value =value;

	if(next!=NULL){//����λ������Ľ�β
		newnode->fwd =next;//�˾䲻�������������ִ�У����Ҳ�Ӱ����
		if(this!=rootp){//����λ���������ʼλ�ã���λ�������м䣬���1
			this->fwd=newnode;
			newnode->bwd =this;
				}
		else{//����λ�������������ʼλ��			
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
	return 1;//����ɹ�
}
�߼��򻯲��뺯����
if(pointer !=NULL)
	field=pointer;
else
	fileld=NULL;
�򻯺�
field=pointer;
����pointer!=NULL,
��ôfiled=pointer;filed �õ�pointer��ֵ
���Pointer==NULL;
ִ��filed=pointer;֮��filed=pointer=NULL
����������
���������հ汾��

int dll_insert(Node *rootp,int value)
{
	Node *this;
	Node *next;
	Node *newnode;
	for(this=rootp;(next=this->fwd)!=NULLL;this=next){
		if(next->value ==value)//�Ѵ��ڸ���
			return 0;
		if(next->value >value)//�ҵ�����λ��
			break;
	}
	newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL)//û���㹻�Ŀռ�
		return -1;
	newnode->value =value;
    newnode->fwd =next;
	this->fwd=newnode;
	if(next!=NULL){//����λ������Ľ�β
		//�˾䲻�������������ִ�У����Ҳ�Ӱ����
		
		if(this!=rootp){//����λ���������ʼλ�ã���λ�������м䣬���1
			
			newnode->bwd =this;
				}
		else{//����λ�������������ʼλ��			
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
	return 1;//����ɹ�
}