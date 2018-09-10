/***************************************************
 * Data Structure & Algorithm
 * wzhe ahuwang@163.com
***************************************************/

#pragma once

#define ListNodePosi(T) ListNode<T>*		//�б�ڵ�λ��

//�б�ڵ�ģ����(��˫��������ʽʵ��)
template <typename T> struct ListNode {
	T data;									//����
	ListNodePosi(T) pred;					//ǰ��	
	ListNodePosi(T) succ;					//���

	//���캯��
	ListNode() {}							//���header��trailer�Ĺ���
	ListNode( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		: data(e), pred(p), succ(s) {}		//Ĭ�Ϲ���

	//�����ӿ�
	ListNodePosi(T) insertAsPred(T const& e);//������ǰ�ڵ�֮ǰ����
	ListNodePosi(T) insertAsSucc(T const& e);//������ǰ�ڵ�֮�����
};


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this);	//�����½ڵ�
	pred->succ = x;
	pred = x;
	return x;
}


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, this, succ);	//�����½ڵ�
	succ->pred = x;
	succ = x;
	return x;
}

