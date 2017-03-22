#include "stdafx.h"
#include "stackADT.h"
ptr_Node create(int *arr, int n){					//��������
	Node *p1 , *p2, *head;
	if( (head=(Node*)malloc(sizeof(Node))) && head == NULL) return NULL;			//�ж��Ƿ��ܷ���ռ�
	p1 = p2 = head;
	for(int i = 0;i < n;i++){
		if(i >= 1)									
			p2 = p1;
		p1->data=arr[i];
		if(( p1 = (Node*)malloc(sizeof(Node))) && p1==NULL ) {				//��һ���ж��Ƿ��пռ����
			destroy(head);	
			return NULL;
		}
		p2->next = p1;

	}
	p2->next = NULL;
	free(p1);	
	return head;	
}
Status delete_(ptr_Node *head, int index, int *data){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if (*head != NULL){								//�ж��Ƿ���head				
		Node* p,*p1;
		p =* head;
		if(0==index){
			p1=p;
			*head=p->next;
			
			*data=p->data;
			free(p);
			return SUCCESS;
		}
		if(1==index){
			p1=p->next;
			p->next=p1->next;
			*data=p1->data;
			free(p1);
		
		
		return SUCCESS;
		}
		if(index<0){
			printf("the index is small,can't delete it");
			return ERROR;
		}
		
		for(int i = 1;i < index;i++){				//��������ָ��λ��
			p = p->next;	
			if(p->next == NULL)
				{
					printf("the index is large,can't delete it");
					return ERROR;
				
				}
		}
		
			
			p1 = p->next;
			p->next = p->next->next;				//ɾ�������еĽڵ�
			*data = p1->data;
			free(p1);
			return SUCCESS;
		
	}
	else {	
		printf("the head is none");
		return ERROR;
	}
	
} 
void destroy(ptr_Node head){						//��������ĺ���
	if (head != NULL){
		ptr_Node p;
		while(head != NULL){
			p = head;
			head = head->next;
			free(p);
		}
	}
}
Status edit(ptr_Node head, int index, int *data){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if (head!=NULL){										//�ж��Ƿ���head	
		Node *p;
	p = head;
	int t;
	if(head->next == NULL && index == 1) return ERROR;			//�ж��Ƿ�ֻ��һ���ڵ�
	if(index==0)
	{
		t = p->data;
		p->data = *data;
		*data = t;
		return SUCCESS;
	}
	for(int i = 1;i < index;i++){
			p = p->next;										//��������Ѱ�ҽڵ�
			if(p->next == NULL)
				{
					printf("the index is large,can't delete it");
					return ERROR;
				
				}
		}
	
	t = p->next->data;						//�޸Ľڵ��ֵ
	p->next->data = *data;
	*data = t;
	return SUCCESS;
	}
	else {	
		printf("the head is none");
		return ERROR;
	}
}
Status insert(ptr_Node *head, ptr_Node node, int index){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if ( *head == NULL ) return ERROR;				//�ж��Ƿ�������
	Node* p;								
	p=*head;
	if( index == 1 ){							//�жϵ�index=1ʱ�����
		node->next = p->next;
		
		p->next = node;
		
		return SUCCESS;
	}
	if( 0==index){
		*head=node;
		
		node->next=p;
		
		return SUCCESS;
	}
	for (int i = 1 ; i < index ; i++){					//����ָ���ҵ��ڵ�
		p = p->next;
			if(p == NULL)
			{
				printf("the index is large,can't insert it");
				return ERROR;
			}
		}

	node->next = p->next;							//����ڵ�
		
		p->next = node;
		
	return SUCCESS;
	
}
void print(ptr_Node head){		//�������
	ptr_Node p;
	p = head;
	int i = 0;
	while(p != NULL){
	printf("%10d",p->data);
	p = p->next;
	i++;
	if(i == 5){
		printf("\n");
		i = 0;
	}
	}
	printf("\n");
}
int search(ptr_Node head, int data){		
	if (head == NULL) return -1;				//�ж��Ƿ�������
	Node *p;
	p =  head;
	int i = 1;
	if(head->data == data)				//�ж�ͷ�ڵ��ֵ�Ƿ�Ϊdata
		return 0;
	while(p->next != NULL){					//���������ҵ�data��ֵ
		if(data == p->next->data)
			return i;
		p=p->next;
		i++;
	}
	return -1;
}
Status sort(ptr_Node *head){			//��������
	ptr_Node p,t;
	int min,j;
	t = p = *head;
	min = p->data;
	if(*head == NULL || p->next == NULL)
		return ERROR;
	
	while(t->next != NULL){
		while(p != NULL){
			if(min>p->data){
				j = min;
				min = p->data;
				p->data = j;
			}
			p = p->next;
		}
		t->data = min;
		t = p = t->next;
		min = t->data;
	}
	return SUCCESS;
}