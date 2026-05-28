#ifndef PERSON_H
#define PERSON_H

using namespace std;

class person {
	protected:
		string name;
		int water_id;
		int electricity_id;
		int gas_id;
		double paid_price;
	public:
		person();
		void changeperson(string cinname,int water_id,int electricity_id,int gas_id,double paid_price);
		string getname();
		int getwater_id();
		int getelectricity_id();
		int getgas_id();
		void pay(string cinname,double cinpaid_price); 
		double getPaidPrice() ;
		void setPaidPrice(double price) ;
};

class teacher:public person {
	public:
		teacher();
		void changeteacher(string cinname,int water_id,int electricity_id,int gas_id);
		void paid(double cinpaid_price);
		void print();
};

class student:public person {
	public:
		student();
		void changestudent(string cinname,int water_id,int electricity_id,int gas_id);
		void print();
		void paid(double cinpaid_price);
};

#endif
