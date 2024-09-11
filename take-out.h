//take_out.h
#ifndef TAKE_OUT_H
#define TAKE_OUT_H
#include "LinkList.h"
#include <iomanip>
#include<string>

class User;	// 提前声明

class order	// 外卖订单
{
public:
	order(int Year=2024, int Month=9, int Day=18, double Money=0,string name="无",string food="无",string address="无");
	void Set(int Year, int Month, int Day, double Money,string name,string food,string address);
	operator double() const; 
	friend ostream & operator<<(ostream &out, const order &b);
	friend class User;

private:
	int year, month, day;	// 订单日期
	string name,food,address;   //订单的外卖商户,食物和收货地址
	double money;		// 本次订单的金额
};

class User
{
public:
	User(const char *TEL="19979704156", const char *Name="LIQIANYUE");
	void Set(const char *TEL, const char *Name);
	operator string() const;
	void Appendorder(const order &b); //添加新订单
	void Show(ostream &out) const;  //用户信息
	friend ostream & operator<<(ostream &out, const User &u); //显示订单信息

private:
	string  TEL,name;		// 账号、户名
	LinkList<order> link;		// 链表(该用户的订单记录)
};

#endif