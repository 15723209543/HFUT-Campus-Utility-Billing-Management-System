#ifndef INFORMATION_H
#define INFORMATION_H

#include "guideline.h"
#include "person.h"

using namespace std;

class information {
	protected:
		double lasttime_waterusing;
		double nowtime_waterusing;
		double lasttime_electricityusing;
		double nowtime_electricityusing;
		double lasttime_gasusing;
		double nowtime_gasusing;
		double usingwater;
		double usingelectricity;
		double usinggas;
		string lasttime;
		string nowtime;
	public:
		information();
		void changeinformation(double lasttime_waterusing,double nowtime_waterusing,double lasttime_electricityusing,double nowtime_electricityusing,double lasttime_gasusing,double nowtime_gasusing,string cinlasttime,string cinnowtime);
		void gettime();
		void getusing();
};

class studentinformation:public information , public guidelineofstudent , public student {
	private:
		double lastwater_price;
		double lastelectricity_price;
		double lastgas_price;
		double sumlast_price;
		double sumwater_price;
		double sumelectricity_price;
		double sumgas_price;
		double sum_price;
		bool qianfei;
		double surpuls;
	public:
		studentinformation();
		void changestudentinformation(student stu,guidelineofstudent guidelinestudent,double lasttime_waterusing,double nowtime_waterusing,double lasttime_electricityusing,double nowtime_electricityusing,double lasttime_gasusing,double nowtime_gasusing,string cinlasttime,string cinnowtime);
		void getlastusingprice();
		void getusingprice();
		void getsurpuls();
		void cininformation(string cinname,double nowtime_waterusing,double nowtime_electricityusing,double nowtime_gasusing,string cinnowtime);
		void cinwater_idinformation(int number,double nowtime_waterusing,string cinnowtime);
		void cinelectricity_idinformation(int number,double nowtime_electricityusing,string cinnowtime);
		void cingas_idinformation(int number,double nowtime_gasusing,string cinnowtime);
		void print();
		void tableprint();
		void usingnewguideline(); 
};

class teacherinformation:public information , public guidelineofteacher , public teacher {
	private:
		double lastwater_price;
		double lastelectricity_price;
		double lastgas_price;
		double sumlast_price;
		double sumwater_price;
		double sumelectricity_price;
		double sumgas_price;
		double sum_price;
		bool qianfei;
		double surpuls;
	public:
		teacherinformation();
		void changeteacherinformation(teacher tea,guidelineofteacher guidelineteacher,double lasttime_waterusing,double nowtime_waterusing,double lasttime_electricityusing,double nowtime_electricityusing,double lasttime_gasusing,double nowtime_gasusing,string cinlasttime,string cinnowtime);
		void getlastusingprice();
		void getusingprice();
		void getsurpuls();
		void cininformation(string cinname,double nowtime_waterusing,double nowtime_electricityusing,double nowtime_gasusing,string cinnowtime);
		void cinwater_idinformation(int number,double nowtime_waterusing,string cinnowtime);
		void cinelectricity_idinformation(int number,double nowtime_electricityusing,string cinnowtime);
		void cingas_idinformation(int number,double nowtime_gasusing,string cinnowtime);
		void print();
		void tableprint();
		void usingnewguideline(); 
};

#endif
