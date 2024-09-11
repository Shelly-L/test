//take_out.h
#ifndef TAKE_OUT_H
#define TAKE_OUT_H
#include "LinkList.h"
#include <iomanip>
#include<string>

class User;	// ��ǰ����

class order	// ��������
{
public:
	order(int Year=2024, int Month=9, int Day=18, double Money=0,string name="��",string food="��",string address="��");
	void Set(int Year, int Month, int Day, double Money,string name,string food,string address);
	operator double() const; 
	friend ostream & operator<<(ostream &out, const order &b);
	friend class User;

private:
	int year, month, day;	// ��������
	string name,food,address;   //�����������̻�,ʳ����ջ���ַ
	double money;		// ���ζ����Ľ��
};

class User
{
public:
	User(const char *TEL="19979704156", const char *Name="LIQIANYUE");
	void Set(const char *TEL, const char *Name);
	operator string() const;
	void Appendorder(const order &b); //����¶���
	void Show(ostream &out) const;  //�û���Ϣ
	friend ostream & operator<<(ostream &out, const User &u); //��ʾ������Ϣ

private:
	string  TEL,name;		// �˺š�����
	LinkList<order> link;		// ����(���û��Ķ�����¼)
};

#endif