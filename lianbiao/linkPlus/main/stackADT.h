#include<stdio.h> 
#include <stdlib.h>
#include "stdafx.h"
//�����ṹ��
typedef struct Node {    
	int data;   
	struct Node *next; 
}Node, *ptr_Node; 
 
typedef enum Status {  
	SUCCESS, ERROR 
}Status; 

//�������ֺ���
 /**********************************************************************************
 Name............: ptr_Node create(int *arr, int n)
 Description.....: ��������
 Parameters......: arr������ָ�룬n���������С
 Return values...: �ɹ� returnͷ�ڵ� ʧ��-return NULL
**********************************************************************************/
ptr_Node create(int *arr, int n);				//�����鴴������
 /**********************************************************************************
 Name............: void destroy(ptr_Node head)
 Description.....: �������� 
 Parameters......: head-ָ���нڵ㣬�ڵ� index λ������� node ��� 
 Return values...: ����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
**********************************************************************************/
void destroy(ptr_Node head);					//�ݻ�����
/**********************************************************************************
 Name............: Status insert(ptr_Node *head, ptr_Node node, int index)
 Description.....: �������� 
 Parameters......: head-ָ��ͷ�ڵ�  �ڵ� index λ������� node ��� 
 Return values...: �ɹ�-return TRUE ʧ��-return FALSE
**********************************************************************************/

 Status insert(ptr_Node *head, ptr_Node node, int index);		//�ڵ� index λ������� node ��� 
																//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
 /**********************************************************************************
 Name............: Status delete_(ptr_Node *head, int index, int *data);	
 Description.....: ɾ������
 Parameters......: head-ָ��ͷ�ڵ�  ɾ���� index λ����Ľ�� �����Ұ�ɾ���Ľ���ֵ���浽��*data���� 
 Return values...: �ɹ�-return TRUE ʧ��-return FALSE
**********************************************************************************/
 Status delete_(ptr_Node *head, int index, int *data);			//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
																//ɾ���ɹ����� SUCCESS������������� ERROR Status 
 /**********************************************************************************
 Name............: int search(ptr_Node head, int data);	
 Description.....: �������� 
 Parameters......: head-ָ��ͷ�ڵ� �����в��ҽڵ�ֵ�� data ��ȵĽڵ�
 Return values...: �ɹ�-return λ�� ʧ��-return -1
**********************************************************************************/
 int search(ptr_Node head, int data);							//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ�� 
																//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1
 /**********************************************************************************
 Name............: Status edit(ptr_Node head, int index, int *data);	
 Description.....: �޸����� 
 Parameters......: head-ָ��ͷ�ڵ� index-λ�� data����ԭֵ
 Return values...: �ɹ�-return TRUE ʧ��-return FALSE
**********************************************************************************/
 Status edit(ptr_Node head, int index, int *data);				//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data) 
																//�޸ĳɹ����� SUCCESS������������� ERROR 
 /**********************************************************************************
 Name............: void print(ptr_Node head);
 Description.....: ������� 
 Parameters......: head-ָ��ͷ�ڵ�
 Return values...: ��
**********************************************************************************/
 void print(ptr_Node head);										//��������ֵ����һ���ĸ�ʽ���
 /**********************************************************************************
 Name............: Status sort(ptr_Node *head)
 Description.....: ��������
 Parameters......: head-ָ��ͷ�ڵ�
 Return values...: �ɹ�-return TRUE ʧ��-return FALSE
**********************************************************************************/
 Status sort(ptr_Node *head);									//ʵ�ֵ������սڵ�ֵ��С����