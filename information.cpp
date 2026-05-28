#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "guideline.h"
#include "person.h"
#include "information.h"
using namespace std;

information::information() {
	lasttime_waterusing = 0;
	nowtime_waterusing = 0;
	lasttime_electricityusing = 0;
	nowtime_electricityusing = 0;
	lasttime_gasusing = 0;
	nowtime_gasusing = 0;
	usingwater = 0;
	usingelectricity = 0;
	usinggas = 0;
	lasttime = "";
	nowtime = "";
}

void information::changeinformation(double lasttime_waterusing,double nowtime_waterusing,double lasttime_electricityusing,double nowtime_electricityusing,double lasttime_gasusing,double nowtime_gasusing,string cinlasttime,string cinnowtime) {
	this->lasttime_waterusing = lasttime_waterusing;
	this->nowtime_waterusing = nowtime_waterusing;
	this->lasttime_electricityusing = lasttime_electricityusing;
	this->nowtime_electricityusing = nowtime_electricityusing;
	this->lasttime_gasusing = lasttime_gasusing;
	this->nowtime_gasusing = nowtime_gasusing;
	lasttime = cinlasttime;
	nowtime = cinnowtime;
	usingwater = nowtime_waterusing - lasttime_waterusing;
	usingelectricity = nowtime_electricityusing - lasttime_electricityusing;
	usinggas = nowtime_gasusing - lasttime_gasusing;
}

void information::gettime() {
	cout<<"上一次抄表时间是："<< lasttime<<endl;
	cout<<"本次抄表时间是："<<nowtime<<endl;
}

void information::getusing() {
	cout<<"上一次抄表到本次抄表情况："<<endl;
	cout<<"使用水"<< usingwater <<"吨，电"<<usingelectricity<<"度，煤气"<<usinggas<<"立方米"<<endl;
}

studentinformation::studentinformation() {
	lastwater_price = 0;
	lastelectricity_price = 0;
	lastgas_price = 0;
	sumlast_price = 0;
	sumwater_price = 0;
	sumelectricity_price = 0;
	sumgas_price = 0;
	sum_price = 0;
	qianfei = false;
	surpuls = 0;
}

void studentinformation::changestudentinformation(student stu,guidelineofstudent guidelinestudent,double lasttime_waterusing,double nowtime_waterusing,double lasttime_electricityusing,double nowtime_electricityusing,double lasttime_gasusing,double nowtime_gasusing,string cinlasttime,string cinnowtime) {
	student::changeperson(stu.getname(), stu.getwater_id(), stu.getelectricity_id(), stu.getgas_id(), stu.getPaidPrice());

	this->water_free = guidelinestudent.getWaterFree();
	this->electricity_free = guidelinestudent.getElectricityFree();
	this->gas_free = guidelinestudent.getGasFree();
	this->water_price = guidelinestudent.getWaterPrice();
	this->electricity_price = guidelinestudent.getElectricityPrice();
	this->gas_price = guidelinestudent.getGasPrice();

	information::changeinformation(lasttime_waterusing, nowtime_waterusing, lasttime_electricityusing, nowtime_electricityusing, lasttime_gasusing, nowtime_gasusing, cinlasttime, cinnowtime);

	double water_usage = nowtime_waterusing - lasttime_waterusing;
	double electricity_usage = nowtime_electricityusing - lasttime_electricityusing;
	double gas_usage = nowtime_gasusing - lasttime_gasusing;

	double water_chargeable = max(0.0, nowtime_waterusing - water_free) - max(0.0, lasttime_waterusing - water_free);
	double electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free) - max(0.0, lasttime_electricityusing - electricity_free);
	double gas_chargeable = max(0.0, nowtime_gasusing - gas_free) - max(0.0, lasttime_gasusing - gas_free);

	lastwater_price = water_chargeable * water_price;
	lastelectricity_price = electricity_chargeable * electricity_price;
	lastgas_price = gas_chargeable * gas_price;
	sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

	double current_water_chargeable = max(0.0, nowtime_waterusing - water_free);
	double current_electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free);
	double current_gas_chargeable = max(0.0, nowtime_gasusing - gas_free);

	sumwater_price = current_water_chargeable * water_price;
	sumelectricity_price = current_electricity_chargeable * electricity_price;
	sumgas_price = current_gas_chargeable * gas_price;
	sum_price = sumwater_price + sumelectricity_price + sumgas_price;
	qianfei = (sum_price > paid_price);
	surpuls = paid_price - sum_price;
}

void studentinformation::usingnewguideline(){
	double water_usage = nowtime_waterusing - lasttime_waterusing;
	double electricity_usage = nowtime_electricityusing - lasttime_electricityusing;
	double gas_usage = nowtime_gasusing - lasttime_gasusing;

	double water_chargeable = max(0.0, nowtime_waterusing - water_free) - max(0.0, lasttime_waterusing - water_free);
	double electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free) - max(0.0, lasttime_electricityusing - electricity_free);
	double gas_chargeable = max(0.0, nowtime_gasusing - gas_free) - max(0.0, lasttime_gasusing - gas_free);

	lastwater_price = water_chargeable * water_price;
	lastelectricity_price = electricity_chargeable * electricity_price;
	lastgas_price = gas_chargeable * gas_price;
	sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

	double current_water_chargeable = max(0.0, nowtime_waterusing - water_free);
	double current_electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free);
	double current_gas_chargeable = max(0.0, nowtime_gasusing - gas_free);

	sumwater_price = current_water_chargeable * water_price;
	sumelectricity_price = current_electricity_chargeable * electricity_price;
	sumgas_price = current_gas_chargeable * gas_price;
	sum_price = sumwater_price + sumelectricity_price + sumgas_price;
	qianfei = (sum_price > paid_price);
	surpuls = paid_price - sum_price;
}

void studentinformation::getlastusingprice() {
	cout<<"水费"<<lastwater_price <<"元，电费"<<lastelectricity_price<<"元，煤气费"<<lastgas_price<<"元；合计："<<sumlast_price<<"元。"<<endl;
}

void studentinformation::getusingprice() {
	cout<<"截止到目前("<<nowtime<<")为止情况："<<endl;
	cout<<"水费"<<sumwater_price <<"元，电费"<<sumelectricity_price<<"元，煤气费"<<sumgas_price<<"元；合计："<<sum_price<<"元。"<<endl;
}

void studentinformation::getsurpuls() {
	cout<<"当前总共充值："<<paid_price<<"元，"<<"已使用" <<sum_price<<"元。"<<endl;
	if(qianfei) {
		cout<<"目前已经欠费，需要缴纳"<<-surpuls<<"元" <<endl;
	} else {
		cout<<"目前没有欠费，账户还剩余"<<surpuls<<"元" <<endl;
	}
}

void studentinformation::print() {
	student::print();
	information::gettime();
	information::getusing();
	getlastusingprice();
	getusingprice();
	getsurpuls();
}

void studentinformation::tableprint() {
	cout<<left<<setw(20)<<name<<setw(20)<<water_id<<setw(20)<<electricity_id<<setw(20)<<gas_id<<setw(20)<<nowtime_waterusing<<setw(20)<<nowtime_electricityusing<<setw(20)<<nowtime_gasusing<<setw(20)<<sum_price<<setw(20)<<paid_price<<setw(20)<<surpuls<<endl;
}

void studentinformation::cininformation(string cinname,double cinnowtime_waterusing,double cinnowtime_electricityusing,double cinnowtime_gasusing,string cinnowtime) {
	if(name==cinname) {
		double old_water = nowtime_waterusing;
		double old_electricity = nowtime_electricityusing;
		double old_gas = nowtime_gasusing;

		lasttime_waterusing = nowtime_waterusing;
		nowtime_waterusing = cinnowtime_waterusing;
		lasttime_electricityusing = nowtime_electricityusing;
		nowtime_electricityusing = cinnowtime_electricityusing;
		lasttime_gasusing = nowtime_gasusing;
		nowtime_gasusing = cinnowtime_gasusing;
		usingwater = nowtime_waterusing - lasttime_waterusing;
		usingelectricity = nowtime_electricityusing - lasttime_electricityusing;
		usinggas = nowtime_gasusing - lasttime_gasusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double water_chargeable = max(0.0, nowtime_waterusing - water_free) - max(0.0, old_water - water_free);
		double electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free) - max(0.0, old_electricity - electricity_free);
		double gas_chargeable = max(0.0, nowtime_gasusing - gas_free) - max(0.0, old_gas - gas_free);

		lastwater_price = water_chargeable * water_price;
		lastelectricity_price = electricity_chargeable * electricity_price;
		lastgas_price = gas_chargeable * gas_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		double current_water_chargeable = max(0.0, nowtime_waterusing - water_free);
		double current_electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free);
		double current_gas_chargeable = max(0.0, nowtime_gasusing - gas_free);

		sumwater_price = current_water_chargeable * water_price;
		sumelectricity_price = current_electricity_chargeable * electricity_price;
		sumgas_price = current_gas_chargeable * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

void studentinformation::cinwater_idinformation(int number,double cinnowtime_waterusing,string cinnowtime) {
	if(water_id==number) {
		double old_water = nowtime_waterusing;

		lasttime_waterusing = nowtime_waterusing;
		nowtime_waterusing = cinnowtime_waterusing;
		usingwater = nowtime_waterusing - lasttime_waterusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double water_chargeable = max(0.0, nowtime_waterusing - water_free) - max(0.0, old_water - water_free);
		lastwater_price = water_chargeable * water_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		double current_water_chargeable = max(0.0, nowtime_waterusing - water_free);
		sumwater_price = current_water_chargeable * water_price;
		sumelectricity_price = max(0.0, nowtime_electricityusing - electricity_free) * electricity_price;
		sumgas_price = max(0.0, nowtime_gasusing - gas_free) * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

void studentinformation::cinelectricity_idinformation(int number,double cinnowtime_electricityusing,string cinnowtime) {
	if(electricity_id==number) {
		double old_electricity = nowtime_electricityusing;

		lasttime_electricityusing = nowtime_electricityusing;
		nowtime_electricityusing = cinnowtime_electricityusing;
		usingelectricity = nowtime_electricityusing - lasttime_electricityusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free) - max(0.0, old_electricity - electricity_free);
		lastelectricity_price = electricity_chargeable * electricity_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		sumwater_price = max(0.0, nowtime_waterusing - water_free) * water_price;
		double current_electricity_chargeable = max(0.0, nowtime_electricityusing - electricity_free);
		sumelectricity_price = current_electricity_chargeable * electricity_price;
		sumgas_price = max(0.0, nowtime_gasusing - gas_free) * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

void studentinformation::cingas_idinformation(int number,double cinnowtime_gasusing,string cinnowtime) {
	if(gas_id==number) {
		double old_gas = nowtime_gasusing;

		lasttime_gasusing = nowtime_gasusing;
		nowtime_gasusing = cinnowtime_gasusing;
		usinggas = nowtime_gasusing - lasttime_gasusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double gas_chargeable = max(0.0, nowtime_gasusing - gas_free) - max(0.0, old_gas - gas_free);
		lastgas_price = gas_chargeable * gas_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		sumwater_price = max(0.0, nowtime_waterusing - water_free) * water_price;
		sumelectricity_price = max(0.0, nowtime_electricityusing - electricity_free) * electricity_price;
		double current_gas_chargeable = max(0.0, nowtime_gasusing - gas_free);
		sumgas_price = current_gas_chargeable * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

teacherinformation::teacherinformation() {
	lastwater_price = 0;
	lastelectricity_price = 0;
	lastgas_price = 0;
	sumlast_price = 0;
	sumwater_price = 0;
	sumelectricity_price = 0;
	sumgas_price = 0;
	sum_price = 0;
	qianfei = false;
	surpuls = 0;
}

void teacherinformation::changeteacherinformation(teacher tea,guidelineofteacher guidelineteacher,double lasttime_waterusing,double nowtime_waterusing,double lasttime_electricityusing,double nowtime_electricityusing,double lasttime_gasusing,double nowtime_gasusing,string cinlasttime,string cinnowtime) {
	teacher::changeperson(tea.getname(), tea.getwater_id(), tea.getelectricity_id(), tea.getgas_id(), tea.getPaidPrice());
	this->water_price = guidelineteacher.getWaterPrice();
	this->electricity_price = guidelineteacher.getElectricityPrice();
	this->gas_price = guidelineteacher.getGasPrice();

	information::changeinformation(lasttime_waterusing, nowtime_waterusing, lasttime_electricityusing, nowtime_electricityusing, lasttime_gasusing, nowtime_gasusing, cinlasttime, cinnowtime);

	lastwater_price = usingwater * water_price;
	lastelectricity_price = usingelectricity * electricity_price;
	lastgas_price = usinggas * gas_price;
	sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;
	sumwater_price = nowtime_waterusing * water_price;
	sumelectricity_price = nowtime_electricityusing * electricity_price;
	sumgas_price = nowtime_gasusing * gas_price;
	sum_price = sumwater_price + sumelectricity_price + sumgas_price;
	qianfei = (sum_price > paid_price);
	surpuls = paid_price - sum_price;
}

void teacherinformation::usingnewguideline(){
	lastwater_price = usingwater * water_price;
	lastelectricity_price = usingelectricity * electricity_price;
	lastgas_price = usinggas * gas_price;
	sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;
	sumwater_price = nowtime_waterusing * water_price;
	sumelectricity_price = nowtime_electricityusing * electricity_price;
	sumgas_price = nowtime_gasusing * gas_price;
	sum_price = sumwater_price + sumelectricity_price + sumgas_price;
	qianfei = (sum_price > paid_price);
	surpuls = paid_price - sum_price;
}

void teacherinformation::getlastusingprice() {
	cout<<"水费"<<lastwater_price <<"元，电费"<<lastelectricity_price<<"元，煤气费"<<lastgas_price<<"元；合计："<<sumlast_price<<"元。"<<endl;
}

void teacherinformation::getusingprice() {
	cout<<"截止到目前("<<nowtime<<")为止情况："<<endl;
	cout<<"水费"<<sumwater_price <<"元，电费"<<sumelectricity_price<<"元，煤气费"<<sumgas_price<<"元；合计："<<sum_price<<"元。"<<endl;
}

void teacherinformation::getsurpuls() {
	cout<<"当前总共充值："<<paid_price<<"元，"<<"已使用" <<sum_price<<"元。"<<endl;
	if(qianfei) {
		cout<<"目前已经欠费，需要缴纳"<<-surpuls<<"元" <<endl;
	} else {
		cout<<"目前没有欠费，账户还剩余"<<surpuls<<"元" <<endl;
	}
}

void teacherinformation::print() {
	teacher::print();
	information::gettime();
	information::getusing();
	getlastusingprice();
	getusingprice();
	getsurpuls();
}

void teacherinformation::tableprint() {
	cout<<left<<setw(20)<<name<<setw(20)<<water_id<<setw(20)<<electricity_id<<setw(20)<<gas_id<<setw(20)<<nowtime_waterusing<<setw(20)<<nowtime_electricityusing<<setw(20)<<nowtime_gasusing<<setw(20)<<sum_price<<setw(20)<<paid_price<<setw(20)<<surpuls<<endl;
}

void teacherinformation::cininformation(string cinname,double cinnowtime_waterusing,double cinnowtime_electricityusing,double cinnowtime_gasusing,string cinnowtime) {
	if(name==cinname) {
		double old_water = nowtime_waterusing;
		double old_electricity = nowtime_electricityusing;
		double old_gas = nowtime_gasusing;

		lasttime_waterusing = nowtime_waterusing;
		nowtime_waterusing = cinnowtime_waterusing;
		lasttime_electricityusing = nowtime_electricityusing;
		nowtime_electricityusing = cinnowtime_electricityusing;
		lasttime_gasusing = nowtime_gasusing;
		nowtime_gasusing = cinnowtime_gasusing;
		usingwater = nowtime_waterusing - lasttime_waterusing;
		usingelectricity = nowtime_electricityusing - lasttime_electricityusing;
		usinggas = nowtime_gasusing - lasttime_gasusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double water_used = nowtime_waterusing - old_water;
		double electricity_used = nowtime_electricityusing - old_electricity;
		double gas_used = nowtime_gasusing - old_gas;

		lastwater_price = water_used * water_price;
		lastelectricity_price = electricity_used * electricity_price;
		lastgas_price = gas_used * gas_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		sumwater_price = nowtime_waterusing * water_price;
		sumelectricity_price = nowtime_electricityusing * electricity_price;
		sumgas_price = nowtime_gasusing * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

void teacherinformation::cinwater_idinformation(int number,double cinnowtime_waterusing,string cinnowtime) {
	if(water_id== number) {
		double old_water = nowtime_waterusing;

		lasttime_waterusing = nowtime_waterusing;
		nowtime_waterusing = cinnowtime_waterusing;
		usingwater = nowtime_waterusing - lasttime_waterusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double water_used = nowtime_waterusing - old_water;
		lastwater_price = water_used * water_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		sumwater_price = nowtime_waterusing * water_price;
		sumelectricity_price = nowtime_electricityusing * electricity_price;
		sumgas_price = nowtime_gasusing * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

void teacherinformation::cinelectricity_idinformation(int number,double cinnowtime_electricityusing,string cinnowtime) {
	if(electricity_id== number) {
		double old_electricity = nowtime_electricityusing;

		lasttime_electricityusing = nowtime_electricityusing;
		nowtime_electricityusing = cinnowtime_electricityusing;
		usingelectricity = nowtime_electricityusing - lasttime_electricityusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double electricity_used = nowtime_electricityusing - old_electricity;
		lastelectricity_price = electricity_used * electricity_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		sumwater_price = nowtime_waterusing * water_price;
		sumelectricity_price = nowtime_electricityusing * electricity_price;
		sumgas_price = nowtime_gasusing * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}

void teacherinformation::cingas_idinformation(int number,double cinnowtime_gasusing,string cinnowtime) {
	if(gas_id== number) {
		double old_gas = nowtime_gasusing;

		lasttime_gasusing = nowtime_gasusing;
		nowtime_gasusing = cinnowtime_gasusing;
		usinggas = nowtime_gasusing - lasttime_gasusing;
		lasttime = nowtime;
		nowtime = cinnowtime;

		double gas_used = nowtime_gasusing - old_gas;
		lastgas_price = gas_used * gas_price;
		sumlast_price = lastwater_price + lastelectricity_price + lastgas_price;

		sumwater_price = nowtime_waterusing * water_price;
		sumelectricity_price = nowtime_electricityusing * electricity_price;
		sumgas_price = nowtime_gasusing * gas_price;
		sum_price = sumwater_price + sumelectricity_price + sumgas_price;
		qianfei = (sum_price > paid_price);
		surpuls = paid_price - sum_price;
	}
}
