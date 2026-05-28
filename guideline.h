#ifndef GUIDELINE_H
#define GUIDELINE_H

using namespace std;

class guideline {
	protected:
		double water_free;
		double electricity_free;
		double gas_free;
		double water_price;
		double electricity_price;
		double gas_price;
	public:
		guideline();
		void changeguideline(double water_free,double electricity_free,double gas_free,double water_price,double electricity_price,double gas_price);
		void changefree(double water_free,double electricity_free,double gas_free);
		void changeprice(double water_price,double electricity_price,double gas_price);
		void print();
		void usingguideline(guideline gui) ;
		double getWaterFree();
		double getElectricityFree() ;
		double getGasFree() ;
		double getWaterPrice() ;
		double getElectricityPrice();
		double getGasPrice() ;
};

class guidelineofteacher:public guideline {
	public:
		guidelineofteacher();
		void changeguidelineofteacher(double water_price,double electricity_price,double gas_price);
		void print();
};

class guidelineofstudent:public guideline {
	public:
		guidelineofstudent();
		void changeguidelineofstudent(double water_free,double electricity_free,double gas_free,double water_price,double electricity_price,double gas_price);
		void print();
};

#endif
