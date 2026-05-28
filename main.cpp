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
/*（1）问题描述
设计一个水电管理信息系统，能够对高校的水电费用进行管理,包括了登记费用，查询费用，以及
住户信息管理等。在设计时要考虑到学生和教工在用水电时的不同，学生可以免费使用一定额度的水
电，超过这个额度以后必须自费使用，且自费部分水电费的价格标准要高于教工的收费标准（主要是
节约资源）。
（2）基本要求
①实现对用户信息的录入；
②实现水电煤气数据的录入；
③计算并查询用户应缴费用；
④查询未缴纳费用名单。
（3）测试数据
可选用小区物业管理部门的数据，也可采用手工输入不少于 10 个用户信息的数据。
（4）实现提示
①用户基本信息类，教工用户信息类，学生用户信息类；
②收费标准类，该类存储水电煤气标准单位的收费标准，如：煤气，1.0 元/立方米；
③不同类型人员水、电、煤气信息类，这些类可以包括水表，电表，煤气表 ID,抄表时间，上次抄
表时间，本次抄表时间，上次抄表度数，本次抄表度数，本次使用度数，费用，是否缴费标记等信息。
在实现的时候考虑继承和多态技术的合理使用。
（5）选做内容
实现用户查询系统能够找出该用户半年之内的交费记录和本次应交费的数据。 */
using namespace std;

const int SIZE=999;

int main() {
	int a, b, c, d, e, f, g;
	int numberteacher = 0, numberstudent = 0;
	int number;
	int genxing=1;
	studentinformation stu[SIZE];
	teacherinformation tea[SIZE];
	guidelineofstudent guidelinestudent;
	guidelineofteacher guidelineteacher;
	for(int i=0; i<SIZE; i++) {
		stu[i].usingguideline(guidelinestudent);
	}
	for(int i=0; i<SIZE; i++) {
		tea[i].usingguideline(guidelineteacher);
	}
	cout << "欢迎进入水电煤气管理系统\n" << endl;
	int tuichu1 = 0;
	while (tuichu1!=1) {
		cout << "请选择你的身份（1-管理人员、2-老师、3-学生）：";
		cin >> a;
		switch (a) {
				//管理人员【开始】
			case 1: {
				int tuichu2 = 0;
				while (tuichu2 != 1) {
					int success=1;
					cout << "请选择你的操作任务（1-添加成员、2-价格填写、3-信息查询、4-抄表信息录入）:";
					cin >> b;
					switch (b) {
							//添加成员
						case 1: {
							cout << "请输入添加成员个数（一行输入，先输入老师，再输入学生）：" ;
							int cinteacher, cinstudent;
							cin >> cinteacher >> cinstudent;
							cout << "请先输入"<<cinteacher<<"个老师的信息" << endl;
							cout << "请再输入"<<cinstudent<<"个学生的信息" << endl;
							cout<<"输入格式：依次输入姓名、水卡号、电卡号、煤气卡号【每个人两行输入，名字输完换行，三个水卡号之间空格】"<<endl;
							for (int i = 0; i < cinteacher; i++) {
								string cinname;
								int water_id;
								int electricity_id;
								int gas_id;
								cin.ignore();
								getline(cin, cinname);
								cin >> water_id >> electricity_id >> gas_id;
								tea[i + numberteacher].changeteacher(cinname, water_id, electricity_id, gas_id);
							}
							numberteacher += cinteacher;
							for (int i = 0; i < cinstudent; i++) {
								string cinname;
								int water_id;
								int electricity_id;
								int gas_id;
								cin.ignore();
								getline(cin, cinname);
								cin >> water_id >> electricity_id >> gas_id;
								stu[i + numberstudent].changestudent(cinname, water_id, electricity_id, gas_id);
							}
							numberstudent += cinstudent;
							break;
						}
						//价格填写
						case 2: {
							cout << "请输入教师的水、电、煤气的单价（一行输入，空格隔开）：";
							double water_price, electricity_price, gas_price;
							cin >> water_price >> electricity_price >> gas_price;
							guidelineteacher.changeguidelineofteacher(water_price, electricity_price, gas_price);
							for(int i=0; i<SIZE; i++) {
								tea[i].usingguideline(guidelineteacher);
								tea[i].usingnewguideline();
							}
							cout << "请输入学生的水、电、煤气的单价（一行输入，空格隔开）：";
							cin >> water_price >> electricity_price >> gas_price;
							guidelinestudent.changeprice(water_price, electricity_price, gas_price);
							cout << "请输入学生的水、电、煤气的免费额度（一行输入，空格隔开）：";
							cin >> water_price >> electricity_price >> gas_price;
							guidelinestudent.changefree(water_price, electricity_price, gas_price);
							for(int i=0; i<SIZE; i++) {
								stu[i].usingguideline(guidelinestudent);
								stu[i].usingnewguideline();
							}
							genxing=0;
							break;
						}
						//信息查询
						case 3: {
							cout << "请选择你需要查询的信息类型（1-当前价格、2-学生信息查询、3-教师信息查询）:";
							cin >> c;
							switch (c) {
									//信息查询-当前价格
								case 1: {
									guidelineteacher.print();
									guidelinestudent.print();
									break;
								}
								//信息查询-学生信息查询
								case 2: {
									cout << "请选择你需要查询的信息方式（1-输出全部、2-通过姓名查询、3-通过卡号查询）:";
									cin >> d;
									switch (d) {
											//信息查询-学生信息查询-输出全部
										case 1: {
											cout << "学生个人信息表" << endl;
											cout << left<<setw(20)<<"姓名"<<setw(20)<<"水卡号"<<setw(20)<<"电卡号"<<setw(20)<<"煤气卡号"<<setw(20)<<"当前用水量"<<setw(20)<<"当前用电量"<<setw(20)<<"当前用气量"<<setw(20)<<"当前应缴账单"<<setw(20)<<"当前已缴账单"<<setw(20)<<"余额（负代表欠费）" << endl;
											for (int i = 0; i < numberstudent; i++) {
												stu[i].tableprint();
											}
											if(genxing==1) {
												cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
												guidelinestudent.print();
											}
											break;
										}
										//信息查询-学生信息查询-通过姓名查询
										case 2: {
											cout << "请输入需要查询的姓名：" ;
											string cinname;
											cin.ignore();
											getline(cin, cinname);
											int found = 0;
											for (int i = 0; i < numberstudent; i++) {
												if (stu[i].getname() == cinname) {
													stu[i].print();
													if(genxing==1) {
														cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
														guidelinestudent.print();
													}
													found++;
													break;
												}
											}
											if (found == 0) {
												cout << "对不起，查询失败，请检查是否有误" << endl;
												success=0;
											}
											break;
										}
										//信息查询-学生信息查询-通过卡号查询
										case 3: {
											cout << "请选择你需要查询的卡号方式（1-水卡号、2-电卡号、3-煤气卡号）:";
											cin >> e;
											switch (e) {
												case 1: {
													cout << "请输入需要查询的水卡号：" ;
													cin >> number;
													int found = 0;
													for (int i = 0; i < numberstudent; i++) {
														if (stu[i].getwater_id() == number) {
															stu[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelinestudent.print();
															}
															found++;
															break;
														}
													}
													if (found == 0) {
														cout << "对不起，查询失败，请检查是否有误" << endl;
														success=0;
													}
													break;
												}
												case 2: {
													cout << "请输入需要查询的电卡号：";
													cin >> number;
													int found = 0;
													for (int i = 0; i < numberstudent; i++) {
														if (stu[i].getelectricity_id() == number) {
															stu[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelinestudent.print();
															}
															found++;
															break;
														}
													}
													if (found == 0) {
														cout << "对不起，查询失败，请检查是否有误" << endl;
														success=0;
													}
													break;
												}
												case 3: {
													cout << "请输入需要查询的煤气卡号：" ;
													cin >> number;
													int found = 0;
													for (int i = 0; i < numberstudent; i++) {
														if (stu[i].getgas_id() == number) {
															stu[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelinestudent.print();
															}
															found++;
															break;
														}
													}
													if (found == 0) {
														cout << "对不起，查询失败，请检查是否有误" << endl;
														success=0;
													}
													break;
												}
												//信息查询-学生信息查询-通过卡号查询的无效输入
												default: {
													cout << "无效的选择！请重新输入" << endl;
													success=0;
													break;
												}
											}
											break;
										}
										//信息查询-学生信息查询的无效输入
										default: {
											cout << "无效的选择！请重新输入" << endl;
											success=0;
											break;
										}
									}
									break;
								}
								//信息查询-教师信息查询
								case 3: {
									cout << "请选择你需要查询的信息方式（1-输出全部、2-通过姓名查询、3-通过卡号查询）:";
									cin >> d;
									switch (d) {
											//信息查询-教师信息查询-输出全部
										case 1: {
											cout << "教师个人信息表" << endl;
											cout << left<<setw(20)<<"姓名"<<setw(20)<<"水卡号"<<setw(20)<<"电卡号"<<setw(20)<<"煤气卡号"<<setw(20)<<"当前用水量"<<setw(20)<<"当前用电量"<<setw(20)<<"当前用气量"<<setw(20)<<"当前应缴账单"<<setw(20)<<"当前已缴账单"<<setw(20)<<"余额（负代表欠费）" << endl;
											for (int i = 0; i < numberteacher; i++) {
												tea[i].tableprint();
											}
											if(genxing==1) {
												cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
												guidelineteacher.print();
											}
											break;
										}
										//信息查询-教师信息查询-通过姓名查询
										case 2: {
											cout << "请输入需要查询的姓名：" ;
											string cinname;
											cin.ignore();
											getline(cin, cinname);
											int found = 0;
											for (int i = 0; i < numberteacher; i++) {
												if (tea[i].getname() == cinname) {
													tea[i].print();
													if(genxing==1) {
														cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
														guidelineteacher.print();
													}
													found++;
													break;
												}
											}
											if (found == 0) {
												cout << "对不起，查询失败，请检查是否有误" << endl;
												success=0;
											}
											break;
										}
										//信息查询-教师信息查询-通过卡号查询
										case 3: {
											cout << "请选择你需要查询的卡号方式（1-水卡号、2-电卡号、3-煤气卡号）:";
											cin >> e;
											switch (e) {
												case 1: {
													cout << "请输入需要查询的水卡号：" ;
													cin >> number;
													int found = 0;
													for (int i = 0; i < numberteacher; i++) {
														if (tea[i].getwater_id() == number) {
															tea[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelineteacher.print();
															}
															found++;
															break;
														}
													}
													if (found == 0) {
														cout << "对不起，查询失败，请检查是否有误" << endl;
														success=0;
													}
													break;
												}
												case 2: {
													cout << "请输入需要查询的电卡号：";
													cin >> number;
													int found = 0;
													for (int i = 0; i < numberteacher; i++) {
														if (tea[i].getelectricity_id() == number) {
															tea[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelineteacher.print();
															}
															found++;
															break;
														}
													}
													if (found == 0) {
														cout << "对不起，查询失败，请检查是否有误" << endl;
														success=0;
													}
													break;
												}
												case 3: {
													cout << "请输入需要查询的煤气卡号：" ;
													cin >> number;
													int found = 0;
													for (int i = 0; i < numberteacher; i++) {
														if (tea[i].getgas_id() == number) {
															tea[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelineteacher.print();
															}
															found++;
															break;
														}
													}
													if (found == 0) {
														cout << "对不起，查询失败，请检查是否有误" << endl;
														success=0;
													}
													break;
												}
												//信息查询-教师信息查询-通过卡号查询的无效输入
												default: {
													cout << "无效的选择！请重新输入" << endl;
													success=0;
													break;
												}
											}
											break;
										}
										//信息查询-教师信息查询的无效输入
										default: {
											cout << "无效的选择！请重新输入" << endl;
											success=0;
											break;
										}
									}
									break;
								}
								//信息查询的无效输入
								default: {
									cout <<"无效的选择！请重新输入" << endl;
									success=0;
									break;
								}
							}
							break;
						}
						//抄表信息录入
						case 4:  {
							cout << "请输入今天日期（格式：xxxx-xx-xx）:";
							string day;
							cin.ignore();
							getline(cin, day);
							cout << "请输入需要的成员个数（一行输入，先输入老师，再输入学生）：" ;
							int cinteacher, cinstudent;
							cin >> cinteacher >> cinstudent;
							cout << "请选择你需要输入方式（1-通过名字查询输入、2-通过卡号查询输入）:";
							cin>>c;
							switch(c) {
								case 1: {
									cout << "请先输入"<<cinteacher<<"个老师的信息" << endl;
									cout << "请再输入"<<cinstudent<<"个学生的信息" << endl;
									cout<<" 输入格式：依次输入姓名、水当前止度、电当前止度、煤气当前止度【每个人两行输入，名字输完换行，三个水卡号当止度前之间空格】"<<endl;
									for (int k = 0; k < cinteacher ; k++) {
										string cinname;
										double water_using,electricity_using,gas_using;
										cin.ignore();
										getline(cin, cinname);
										cin >> water_using >> electricity_using >> gas_using;
										int found=0;
										for (int i = 0; i < numberteacher; i++) {
											if (tea[i].getname() == cinname) {
												tea[i].cininformation(cinname, water_using, electricity_using , gas_using,day);
												found++;
												break;
											}
										}
										if (found == 0) {
											cout << "对不起，"<<cinname<<"查询失败，请检查是否有误" << endl;
											success=0;
										}
									}
									for (int k = 0; k < cinstudent ; k++) {
										string cinname;
										double water_using,electricity_using,gas_using;
										cin.ignore();
										getline(cin, cinname);
										cin >> water_using >> electricity_using >> gas_using;
										int found=0;
										for (int i = 0; i < numberstudent; i++) {
											if (stu[i].getname() == cinname) {
												stu[i].cininformation(cinname, water_using, electricity_using , gas_using,day);
												found++;
												break;
											}
										}
										if (found == 0) {
											cout << "对不起，"<<cinname<<"查询失败，请检查是否有误" << endl;
											success=0;
										}
									}
									break;
								}
								case 2 : {
									cout << "请选择你需要输入的卡号方式（1-水卡号、2-电卡号、3-气卡号）:";
									cin >> d;
									switch(d) {
										case 1: {
											cout << "请先输入"<<cinteacher<<"个老师的信息" << endl;
											cout << "请再输入"<<cinstudent<<"个学生的信息" << endl;
											cout<<" 输入格式：依次水卡号和当前用水止度【一行输入，空格隔开】"<<endl;
											for (int k = 0; k < cinteacher ; k++) {
												int number;
												double water_using;
												cin>>number>>water_using;
												int found=0;
												for (int i = 0; i < numberteacher; i++) {
													if (tea[i].getwater_id() == number) {
														tea[i].cinwater_idinformation(number, water_using,day);
														found++;
														break;
													}
												}
												if (found == 0) {
													cout << "对不起，"<<number<<"查询失败，请检查是否有误" << endl;
													success=0;
												}
											}
											for (int k = 0; k < cinstudent ; k++) {
												int number;
												double water_using;
												cin>>number>>water_using;
												int found=0;
												for (int i = 0; i < numberstudent; i++) {
													if (stu[i].getwater_id() == number) {
														stu[i].cinwater_idinformation(number, water_using,day);
														found++;
														break;
													}
												}
												if (found == 0) {
													cout << "对不起，"<<number<<"查询失败，请检查是否有误" << endl;
													success=0;
												}
											}
											break;
										}
										case 2: {
											cout << "请先输入"<<cinteacher<<"个老师的信息" << endl;
											cout << "请再输入"<<cinstudent<<"个学生的信息" << endl;
											cout<<" 输入格式：依次电卡号和当前用电止度【一行输入，空格隔开】"<<endl;
											for (int k = 0; k < cinteacher ; k++) {
												int number;
												double electricity_using;
												cin>>number>>electricity_using;
												int found=0;
												for (int i = 0; i < numberteacher; i++) {
													if (tea[i].getelectricity_id() == number) {
														tea[i].cinelectricity_idinformation(number, electricity_using,day);
														found++;
														break;
													}
												}
												if (found == 0) {
													cout << "对不起，"<<number<<"查询失败，请检查是否有误" << endl;
													success=0;
												}
											}
											for (int k = 0; k < cinstudent ; k++) {
												int number;
												double electricity_using;
												cin>>number>>electricity_using;
												int found=0;
												for (int i = 0; i < numberstudent; i++) {
													if (stu[i].getelectricity_id() == number) {
														stu[i].cinelectricity_idinformation(number, electricity_using,day);
														found++;
														break;
													}
												}
												if (found == 0) {
													cout << "对不起，"<<number<<"查询失败，请检查是否有误" << endl;
													success=0;
												}
											}
											break;
										}
										case 3: {
											cout << "请先输入"<<cinteacher<<"个老师的信息" << endl;
											cout << "请再输入"<<cinstudent<<"个学生的信息" << endl;
											cout<<" 输入格式：依次气卡号和当前用气止度【一行输入，空格隔开】"<<endl;
											for (int k = 0; k < cinteacher ; k++) {
												int number;
												double gas_using;
												cin>>number>>gas_using;
												int found=0;
												for (int i = 0; i < numberteacher; i++) {
													if (tea[i].getgas_id() == number) {
														tea[i].cingas_idinformation(number, gas_using,day);
														found++;
														break;
													}
												}
												if (found == 0) {
													cout << "对不起，查询失败，请检查是否有误" << endl;
													success=0;
												}
											}
											for (int k = 0; k < cinstudent ; k++) {
												int number;
												double gas_using;
												cin>>number>>gas_using;
												int found=0;
												for (int i = 0; i < numberstudent; i++) {
													if (stu[i].getgas_id() == number) {
														stu[i].cingas_idinformation(number, gas_using,day);
														found++;
														break;
													}
												}
												if (found == 0) {
													cout << "对不起，"<<number<<"查询失败，请检查是否有误" << endl;
													success=0;
												}
											}
											break;
										}
										//抄表信息录入-卡号选择的错误
										default: {
											cout << "无效的选择！请重新输入" << endl;
											success=0;
											break;
										}
									}
									break;
								}
								//抄表信息录入-卡号选择的错误
								default: {
									cout << "无效的选择！请重新输入" << endl;
									success=0;
									break;
								}
							}
							break;
						}
						//管理人员操作的无效输入
						default: {
							cout << "无效的选择！请重新输入" << endl;
							success=0;
							break;
						}
					}
					if(success==1) {
						cout << "当前任务已完成，请问你是否选择返回上一级[上一级是身份选择]（如果是输入1，反之输入0）：";
						cin >> tuichu2;
					}
				}
				break;
			}
			//管理人员【结束】
			//教师【开始】
			case 2: {
				// 老师功能的代码
				int tuichu2 = 0;
				while (tuichu2 != 1) {
					int success=1;
					cout << "请选择你的操作任务（1-注册、2-登录）:";
					cin>>b;
					switch(b) {
							//注册
						case 1: {
							cout << "请输入你的信息（依次输入姓名、水卡号、电卡号、煤气卡号【两行输入，名字输完换行，三个水卡号之间空格】）" << endl;
							string cinname;
							int water_id;
							int electricity_id;
							int gas_id;
							cin.ignore();
							getline(cin, cinname);
							cin >> water_id >> electricity_id >> gas_id;
							tea[numberteacher].changeteacher(cinname, water_id, electricity_id, gas_id);
							numberteacher++;
							break;
						}
						//登录
						case 2: {
							int panduan=0;
							cout <<"请输入你的姓名和卡号" << endl;
							cout<<"输入格式：依次输入姓名、水卡号、电卡号、煤气卡号【每个人两行输入，名字输完换行，三个水卡号之间空格】"<<endl;
							string cinname;
							int water_id;
							int electricity_id;
							int gas_id;
							cin.ignore();
							getline(cin, cinname);
							cin >> water_id >> electricity_id >> gas_id;
							for (int i = 0; i < numberteacher; i++) {
								if (tea[i].getname()==cinname&&tea[i].getwater_id()== water_id&&tea[i].getelectricity_id()==electricity_id&&tea[i].getgas_id()==gas_id) {
									panduan=1;
									break;
								}
							}
							if(panduan!=1) {
								cout<<"很遗憾登录失败，请重新检查后登录"<<endl;
								success=0;
							} else {
								cout<<"登录成功,"<<cinname<<"欢迎你"<<endl;
								int tuichu3 = 0;
								while (tuichu3 != 1) {
									cout<<"请选择你的操作任务(1-缴费、2-信息查询、3-自行录入抄表信息):";
									cin>>c;
									switch(c) {
											//缴费
										case 1: {
											cout <<"请输入你的缴费费用：";
											double money;
											cin >> money;
											int found=0;
											for (int i = 0; i < numberteacher; i++) {
												if (tea[i].getname() == cinname) {
													tea[i].paid(money);
													found++;
													tea[i].usingnewguideline();
													break;
												}
											}
											break;
										}
										//信息查询
										case 2: {
											cout<<"请选择你的操作任务(1-个人信息查询、2-当前价格)：";
											cin >> d;
											switch (d) {
													//信息查询-个人信息查询
												case 1: {
													for (int i = 0; i < numberteacher; i++) {
														if (tea[i].getname() == cinname) {
															tea[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelineteacher.print();
															}
															break;
														}
													}
													break;
												}
												//信息查询-教师收费标准
												case 2 : {
													guidelineteacher.print();
													break;
												}
												//信息查询-教师信息查询的无效输入
												default: {
													cout << "无效的选择！请重新输入" << endl;
													success=0;
													break;
												}
											}
											break;
										}
										case 3: {
											//抄表信息录入
											cout << "请输入今天日期（格式：xxxx-xx-xx）:";
											string day;
											cin.ignore();
											getline(cin, day);
											cout <<"请输入你当前水、电、煤气的读数（三个读数之间空格）:" ;
											double water_using,electricity_using,gas_using;
											cin >> water_using >> electricity_using >> gas_using;
											int found=0;
											for (int i = 0; i < numberteacher; i++) {
												if (tea[i].getname() == cinname) {
													tea[i].cininformation(cinname, water_using, electricity_using , gas_using,day);
													found++;
													break;
												}
											}
											break;
										}
										//教师操作任务的无效输入
										default: {
											cout << "无效的选择！请重新输入" << endl;
											success=0;
											break;
										}
									}
									if(success==1) {
										cout << "当前任务已完成，请问你是否选择返回上一级[上一级是注册和登录]（如果是输入1，反之输入0）：";
										cin >> tuichu3;
									}
								}
							}
							break;
						}
						//教师注册登录的无效输入
						default: {
							cout << "无效的选择！请重新输入" << endl;
							success=0;
							break;
						}
					}
					if(success==1) {
						cout << "当前任务已完成，请问你是否选择返回上一级[上一级是身份选择]（如果是输入1，反之输入0）：";
						cin >> tuichu2;
					}
				}
				break;
			}
			//教师【结束】
			//学生【开始】
			case 3: {
				// 学生功能的代码
				int tuichu2 = 0;
				while (tuichu2 != 1) {
					int success=1;
					cout << "请选择你的操作任务（1-注册、2-登录）:";
					cin>>b;
					switch(b) {
							//注册
						case 1: {
							cout << "请输入你的信息（依次输入姓名、水卡号、电卡号、煤气卡号【两行输入，名字输完换行，三个水卡号之间空格】）" << endl;
							string cinname;
							int water_id;
							int electricity_id;
							int gas_id;
							cin.ignore();
							getline(cin, cinname);
							cin >> water_id >> electricity_id >> gas_id;
							stu[numberstudent].changestudent(cinname, water_id, electricity_id, gas_id);
							numberstudent++;
							break;
						}
						//登录
						case 2: {
							int panduan=0;
							cout <<"请输入你的姓名和卡号" << endl;
							cout<<"输入格式：依次输入姓名、水卡号、电卡号、煤气卡号【每个人两行输入，名字输完换行，三个水卡号之间空格】"<<endl;
							string cinname;
							int water_id;
							int electricity_id;
							int gas_id;
							cin.ignore();
							getline(cin, cinname);
							cin >> water_id >> electricity_id >> gas_id;
							for (int i = 0; i < numberstudent; i++) {
								if (stu[i].getname()==cinname&&stu[i].getwater_id()== water_id&&stu[i].getelectricity_id()==electricity_id&&stu[i].getgas_id()==gas_id) {
									panduan=1;
									break;
								}
							}
							if(panduan!=1) {
								cout<<"很遗憾登录失败，请重新检查后登录"<<endl;
								success=0;
							} else {
								cout<<"登录成功,"<<cinname<<"欢迎你"<<endl;
								int tuichu3 = 0;
								while (tuichu3 != 1) {
									cout<<"请选择你的操作任务(1-缴费、2-信息查询、3-自行录入抄表信息):";
									cin>>c;
									switch(c) {
											//缴费
										case 1: {
											cout <<"请输入你的缴费费用：";
											double money;
											cin >> money;
											int found=0;
											for (int i = 0; i < numberstudent; i++) {
												if (stu[i].getname() == cinname) {
													stu[i].paid(money);
													stu[i].usingnewguideline() ;
													found++;
													break;
												}
											}
											break;
										}
										//信息查询
										case 2: {
											cout<<"请选择你的操作任务(1-个人信息查询、2-当前价格)：";
											cin >> d;
											switch (d) {
													//信息查询-个人信息查询
												case 1: {
													for (int i = 0; i < numberstudent; i++) {
														if (stu[i].getname() == cinname) {
															stu[i].print();
															if(genxing==1) {
																cout << "温馨提示，请注意当前的单价未重新更新！！！"<<endl;
																guidelinestudent.print();
															}
															break;
														}
													}
													break;
												}
												//信息查询-学生收费标准
												case 2 : {
													guidelinestudent.print();
													break;
												}
												//信息查询-学生信息查询的无效输入
												default: {
													cout << "无效的选择！请重新输入" << endl;
													success=0;
													break;
												}
											}
											break;
										}
										case 3: {
											//抄表信息录入
											cout << "请输入今天日期（格式：xxxx-xx-xx）:";
											string day;
											cin.ignore();
											getline(cin, day);
											cout <<"请输入你当前水、电、煤气的读数（三个读数之间空格）:" ;
											double water_using,electricity_using,gas_using;
											cin >> water_using >> electricity_using >> gas_using;
											int found=0;
											for (int i = 0; i < numberstudent; i++) {
												if (stu[i].getname() == cinname) {
													stu[i].cininformation(cinname, water_using, electricity_using , gas_using,day);
													found++;
													break;
												}
											}
											break;
										}
										//学生操作任务的无效输入
										default: {
											cout << "无效的选择！请重新输入" << endl;
											success=0;
											break;
										}
									}
									if(success==1) {
										cout << "当前任务已完成，请问你是否选择返回上一级[上一级是注册和登录]（如果是输入1，反之输入0）：";
										cin >> tuichu3;
									}
								}
							}
							break;
						}
						//学生注册登录的无效输入
						default: {
							cout << "无效的选择！请重新输入" << endl;
							success=0;
							break;
						}
					}
					if(success==1) {
						cout << "当前任务已完成，请问你是否选择返回上一级[上一级是身份选择]（如果是输入1，反之输入0）：";
						cin >> tuichu2;
					}
				}
				break;
			}
			//学生【结束】
			//身份选择的无效输入
			default: {
				cout << "无效的身份选择！" << endl;
				break;
			}
		}
		cout<<"目前你已经返回第一级，请问是否要退出程序（如果是输入1，反之输入0）:";
		cin>>tuichu1;
		if(tuichu1==1) {
			cout<<"请二次确认是否要退出程序（如果是输入1，反之输入0）：";
			cin>>tuichu1;
		}
	}
	return 0;
}


