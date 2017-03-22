#include "stdafx.h"
#include "adts.h"
#include "claim.h"
Status delete_T(ptr_TNode *head, int index, int *data){				//ɾ��������
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if (head == NULL) return ERROR;									//�ж��Ƿ�������
	TNode* p,*p1;
		p = *head;
		
		
		if(0==index){
			p1=p;
			*head=p->next;
			p->next->pre=NULL;
			*data=p->data;
			free(p);
			return SUCCESS;
		}
		
		for(int i = 1; i < index ;i++){									//����ָ���ҵ��ڵ�
			p = p->next;	
			if ( p->next == NULL )
				{
					printf("the index is large,can't delete it");
					return ERROR;
				}
		}
		if(p->next->next==NULL){
		p1=p->next;
		p->next=NULL;
		
		free(p1);
		return SUCCESS;
	}
			
			p1 = p->next;										//ɾ���ڵ�����
			p->next = p->next->next;
			p1->next->pre = p;
			*data = p1->data;
			free(p1);
		return SUCCESS;
}
Status insert_T(ptr_TNode *head, ptr_TNode node, int index){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if ( *head == NULL ) return ERROR;				//�ж��Ƿ�������
	TNode* p;								
	p=*head;
	if( index == 1 ){							//�жϵ�index=1ʱ�����
		node->next = p->next;
		p->next->next->pre = node;
		p->next = node;
		node->pre = p;
		return SUCCESS;
	}
	if( 0==index){
		*head=node;
		node->pre=NULL;
		node->next=p;
		p->pre=node;
		return SUCCESS;
	}
	
	for (int i = 1 ; i < index; i++){					//����ָ���ҵ��ڵ�
		p = p->next;
			if(p==NULL&&i==(index-1))
			{		
					
					node->next = p->next;
					node->pre=p;
					p->next=node;
					return SUCCESS;
			}
			if(p == NULL)
			{
				printf("the index is large,can't insert it");
				return ERROR;
			}
		}
	if(p->next==NULL&&i==index)
			{		
					
					node->next = p->next;
					node->pre=p;
					p->next=node;
					return SUCCESS;
			}
	if(p->next->next==NULL){
		p->next->pre=node;
		node->next=p->next;
		node->pre=p;
		p->next=node;
		return SUCCESS;
	}
	node->next = p->next;							//����ڵ�
		p->next->next->pre = node;
		p->next = node;
		node->pre = p;
	return SUCCESS;
}
extern TNode* product(void){							//��������
	TNode *p1,*p2,*head;						//��������ָ��
	int i = 1;
	p1 = p2 = head = (TNode*)malloc(sizeof(TNode));	
	head->pre = NULL;
	printf("please enter number to create lian biao(-1 to quit):");
	scanf("%d",&p1->data);
	while(p1->data != -1){
		if( i >= 2 ){
			p2 = p1;
		}
		p1 = (TNode*)malloc(sizeof(TNode));
		scanf("%d",&p1->data);
		p2->next = p1;
		p1->pre = p2;
		i++;
	}
	p2->next = NULL;
	free(p1);	
	return head;								//����ͷ�ڵ�
}
void destroy(ptr_TNode head){						//��������ĺ���
	if (head != NULL){
		ptr_TNode p;
		while(head != NULL){
			p = head;
			head = head->next;
			free(p);
		}
	}
}