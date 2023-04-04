#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人结构体
struct person {

	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct addressbooks {

	//通讯录保存联系人的数组
	struct person presonarray[MAX];
	//通讯录当前联系人的数量
	int m_Size;
};

//1.添加联系人
void addperson(addressbooks *abs){

	//判断通讯录是否已满，满了则不能再添加
	if (abs->m_Size == MAX) {

		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {

		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->presonarray[abs->m_Size].m_Name = name;

		//输入性别，1代表男，2代表女
		int sex = 0;
		cout << "请输入性别：" << "\t";
		cout << "1---男" << "\t";
		cout << "2---女" << endl;

		while (true) {

			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->presonarray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->presonarray[abs->m_Size].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->presonarray[abs->m_Size].m_Addr = addr;

		cout << "添加成功" << endl;
		abs->m_Size++;
	}
	system("pause");
	system("cls");
}

//2.显示所有联系人
void showperson(addressbooks* abs) {

	//判断通讯录联系人是否为零，为零则返回，不为零可显示所有联系人
	if (abs->m_Size == 0) {

		cout << "通讯录为空！" << endl;
		system("pause");
		system("cls");

		return;
	}
	else {

		for (int i = 0; i < abs->m_Size; i++) {

			//打印出所有联系人信息
			cout << "联系人" << i + 1 << ":" << "\t";
			cout << "姓名:" << abs->presonarray[i].m_Name << "\t";
			cout << "性别:" << (abs->presonarray[i].m_Sex == 1?"男" :"女") << "\t";
			cout << "年龄:" << abs->presonarray[i].m_Age << "\t";
			cout << "电话:" << abs->presonarray[i].m_Phone << "\t";
			cout << "住址:" << abs->presonarray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");
	}

}

//检测联系人是否存在，存在返回在数字中的具体位置，不存在则返回-1
//参数一：通讯录    参数二：对比姓名
int isExist(addressbooks *abs, string name) {

	for (int j = 0; j < abs->m_Size; j++) {

		//找到联系人的位置了
		if (abs->presonarray[j].m_Name == name)
			return j;
	}
	//未找到联系人
	return -1;
}

//3.删除联系人
void deleteperson(addressbooks *abs) {

	string name;
	cout << "请输入删除联系人姓名：" << endl;
	cin >> name;
	//isExist(abs, name);
	int ret = isExist(abs, name);
	if (ret == -1){

		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
		
	else{

		//增加一个确认是否删除的功能，输入1确认删除，输入2取消删除
		cout << "是否删除？" << endl;
		cout << "1---确认" << "\t";
		cout << "2---取消" << endl;
		int del;
		cin >> del;

		if (del == 2) {

			system("pause");
			system("cls");
			return;
		}
		else if(ret != -1) {

			for (int i = ret; i < abs->m_Size; i++) {

				abs->presonarray[i] = abs->presonarray[i + 1];
			}
			abs->m_Size--;
			cout << "删除成功！" << endl;
		}
		system("pause");
		system("cls");
	}
}

//4、查找联系人
void searchperson(addressbooks* abs) {

	//输入要查找的联系人姓名，不存在查无此人，存在则显示出联系人的信息
	cout << "请输入查找人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//调用检测联系人是否存在的函数并用ret接收返回值

	if (ret == -1) {

		cout << "查无此人" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {

		//打印出查询的联系人信息
		cout << "联系人" << ret + 1 << ":" << "\t";
		cout << "姓名:" << abs->presonarray[ret].m_Name << "\t";
		cout << "性别:" << (abs->presonarray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs->presonarray[ret].m_Age << "\t";
		cout << "电话:" << abs->presonarray[ret].m_Phone << "\t";
		cout << "住址:" << abs->presonarray[ret].m_Addr << endl;

		system("pause");
		system("cls");
	}
}

//5、修改联系人信息
void changeperson(addressbooks* abs) {

	cout << "请输入修改联系人姓名" << endl;
	string name, phone, addr;
	int sex, age;

	cin >> name;
	int ret = isExist(abs, name);

	if (ret == -1) {
		
		//被修改联系人不存在，是否新建联系人
		cout << "联系人不存在，是否新建联系人？" << endl;
		cout << "1---是" << "\t";
		cout << "2---否" << endl;
		int newper;
		cin >> newper;

		if (newper == 1)
			addperson(abs);
		else if(newper == 2) {

			system("cls");
			return;
		}
	}
	else {

		//找到被修改人信息后进行修改
		cout << "联系人" << ret + 1 << ":" << "\t";
		cout << "姓名:" << abs->presonarray[ret].m_Name << "\t";
		cout << "性别:" << (abs->presonarray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs->presonarray[ret].m_Age << "\t";
		cout << "电话:" << abs->presonarray[ret].m_Phone << "\t";
		cout << "住址:" << abs->presonarray[ret].m_Addr << endl;

		//addperson(abs);
		cout << "修改姓名：" << endl;
		cin >> name;
		abs->presonarray[ret].m_Name = name;
		cout << "修改性别：1---男    2---女" << endl;
		while (true) {

			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		abs->presonarray[ret].m_Sex = sex;
		cout << "修改年龄：" << endl;
		cin >> age;
		abs->presonarray[ret].m_Age = age;
		cout << "修改电话：" << endl;
		cin >> phone;
		abs->presonarray[ret].m_Phone = phone;
		cout << "修改住址：" << endl;
		cin >> addr;
		abs->presonarray[ret].m_Addr = addr;

		//修改完成后显示修改联系人完整信息
		cout << "修改完成" << endl;
		showperson(abs);
	}
}

//6、清空联系人
void clearperson(addressbooks* abs) {

	//确认是否清空所有联系人
	cout << "是否清空所有联系人？" << endl;
	cout << "1110---确认" << "\t";
	cout << "1101---取消" << endl;
	int clear;
	cin >> clear;
	if (clear == 1110) {

		//确认清空
		abs->m_Size = 0;
		cout << "清空成功！" << endl;
		system("pause");
		system("cls");
	}
	else if (clear == 1101) {

		//取消清空
		system("pause");
		system("cls");
		return;
	}
	else {

		cout << "输入错误，请重新输入" << endl;
		clearperson(abs);
	}
}

//菜单界面
void showmenu() {

	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main() 
{
	//创建通讯录结构体变量
	addressbooks abs;
	//初始化通讯录联系人数量
	abs.m_Size = 0;

	int select = 0;

	while (true) {

		//菜单的调用
		showmenu();

		cin >> select;

		switch (select) {
		case 1://添加联系人
			addperson(&abs);//利用地址传递可以修饰实参
			break;
		case 2://2、显示联系人
			showperson(&abs);
			break;
		case 3://3、删除联系人
			deleteperson(&abs);
			break;
		case 4://4、查找联系人
			searchperson(&abs);
			break;
		case 5://5、修改联系人
			changeperson(&abs);
			break;
		case 6://6、清空联系人
			clearperson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用!" << endl;
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	}

	system("pause");

	return 0;
}