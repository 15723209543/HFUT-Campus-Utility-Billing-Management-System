#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "person.h"
using namespace std;

person::person() {
	name = "";
	water_id = 0;
	electricity_id = 0;
	gas_id = 0;
	paid_price = 0;
}

void person::changeperson(string cinname,int water_id,int electricity_id,int gas_id,double paid_price) {
	name = cinname;
	this->water_id = water_id;
	this->electricity_id = electricity_id;
	this->gas_id = gas_id;
	this->paid_price = paid_price;
}

void person::pay(string cinname,double cinpaid_price) {
	if(name==cinname) {
		paid_price=paid_price+cinpaid_price;
	}
}

string person::getname() {
	return name;
}

int person::getwater_id() {
	return water_id;
}

int person::getelectricity_id() {
	return electricity_id;
}

int person::getgas_id() {
	return gas_id;
}

double person::getPaidPrice() {
	return paid_price;
}

void person::setPaidPrice(double price) {
	paid_price = price;
}

teacher::teacher() {
	name = "";
	water_id = 0;
	electricity_id = 0;
	gas_id = 0;
	paid_price = 0;
}

void teacher::changeteacher(string cinname,int water_id,int electricity_id,int gas_id) {
	name = cinname;
	this->water_id = water_id;
	this->electricity_id = electricity_id;
	this->gas_id = gas_id;
}

void teacher::print() {
	cout<<"教师名字："<< name<<endl;
	cout<<"水卡号："<< water_id<<endl;
	cout<<"电卡号："<< electricity_id<<endl;
	cout<<"煤气卡号："<< gas_id<<endl;
	cout<<"当前账户总充值："<< paid_price<<endl;
}

void teacher::paid(double cinpaid_price) {
	paid_price = paid_price + cinpaid_price;
}

student::student() {
	name = "";
	water_id = 0;
	electricity_id = 0;
	gas_id = 0;
	paid_price = 0;
}

void student::changestudent(string cinname,int water_id,int electricity_id,int gas_id) {
	name = cinname;
	this->water_id = water_id;
	this->electricity_id = electricity_id;
	this->gas_id = gas_id;
}

void student::print() {
	cout<<"学生名字："<< name<<endl;
	cout<<"水卡号："<< water_id<<endl;
	cout<<"电卡号："<< electricity_id<<endl;
	cout<<"煤气卡号："<< gas_id<<endl;
	cout<<"当前账户总充值："<< paid_price<<endl;
}

void student::paid(double cinpaid_price) {
	paid_price = paid_price + cinpaid_price;
}
