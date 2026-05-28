#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "guideline.h"
using namespace std;

guideline::guideline() {
	water_free = 0;
	electricity_free = 0;
	gas_free = 0;
	water_price = 0;
	electricity_price = 0;
	gas_price = 0;
}

void guideline::usingguideline(guideline gui) {
	water_free = gui.water_free;
	electricity_free = gui.electricity_free;
	gas_free = gui.gas_free;
	water_price = gui.water_price;
	electricity_price = gui.electricity_price;
	gas_price = gui.gas_price;
}

double guideline::getWaterFree() {
	return water_free;
}

double guideline::getElectricityFree()  {
	return electricity_free;
}

double guideline::getGasFree()  {
	return gas_free;
}

double guideline::getWaterPrice()  {
	return water_price;
}

double guideline::getElectricityPrice() {
	return electricity_price;
}

double guideline::getGasPrice()  {
	return gas_price;
}

void guideline::changeguideline(double water_free,double electricity_free,double gas_free,double water_price,double electricity_price,double gas_price) {
	this->water_free = water_free;
	this->electricity_free = electricity_free;
	this->gas_free = gas_free;
	this->water_price = water_price;
	this->electricity_price = electricity_price;
	this->gas_price = gas_price;
}

void guideline::changefree(double water_free,double electricity_free,double gas_free) {
	this-> water_free=water_free;
	this-> electricity_free=electricity_free;
	this-> gas_free=gas_free;
}

void guideline::changeprice(double water_price,double electricity_price,double gas_price) {
	this-> water_price=water_price;
	this-> electricity_price=electricity_price;
	this-> gas_price=gas_price;
}

guidelineofteacher::guidelineofteacher() {
	water_free = 0;
	electricity_free = 0;
	gas_free = 0;
	water_price = 1;
	electricity_price = 1.5;
	gas_price = 2;
}

void guidelineofteacher::changeguidelineofteacher(double water_price,double electricity_price,double gas_price) {
	this->water_price = water_price;
	this->electricity_price = electricity_price;
	this->gas_price = gas_price;
}

void  guidelineofteacher::print() {
	cout<<"教师用水标准："<<endl;
	cout<<"水"<< water_price <<"元一吨，电"<< electricity_price <<"元一度，煤气"<<gas_price<<"元一立方米"<<endl;
}

guidelineofstudent::guidelineofstudent() {
	water_free = 10;
	electricity_free = 20;
	gas_free = 25;
	water_price = 1.5;
	electricity_price = 2;
	gas_price = 3;
}

void guidelineofstudent::changeguidelineofstudent(double water_free,double electricity_free,double gas_free,double water_price,double electricity_price,double gas_price) {
	this->water_free = water_free;
	this->electricity_free = electricity_free;
	this->gas_free = gas_free;
	this->water_price = water_price;
	this->electricity_price = electricity_price;
	this->gas_price = gas_price;
}

void guidelineofstudent::print() {
	cout<<"学生用水标准："<<endl;
	cout<<"水"<< water_price <<"元一吨，电"<< electricity_price <<"元一度，煤气"<<gas_price<<"元一立方米"<<endl;
	cout<<"其中免费的额度有：水"<< water_free <<"吨，电"<< electricity_free <<"度，煤气"<<gas_free<<"立方米"<<endl;
}
