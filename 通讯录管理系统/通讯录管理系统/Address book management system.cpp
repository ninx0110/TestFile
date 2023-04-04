#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct person {

	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//���ͨѶ¼�ṹ��
struct addressbooks {

	//ͨѶ¼������ϵ�˵�����
	struct person presonarray[MAX];
	//ͨѶ¼��ǰ��ϵ�˵�����
	int m_Size;
};

//1.�����ϵ��
void addperson(addressbooks *abs){

	//�ж�ͨѶ¼�Ƿ��������������������
	if (abs->m_Size == MAX) {

		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {

		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->presonarray[abs->m_Size].m_Name = name;

		//�����Ա�1�����У�2����Ů
		int sex = 0;
		cout << "�������Ա�" << "\t";
		cout << "1---��" << "\t";
		cout << "2---Ů" << endl;

		while (true) {

			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->presonarray[abs->m_Size].m_Age = age;

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->presonarray[abs->m_Size].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->presonarray[abs->m_Size].m_Addr = addr;

		cout << "��ӳɹ�" << endl;
		abs->m_Size++;
	}
	system("pause");
	system("cls");
}

//2.��ʾ������ϵ��
void showperson(addressbooks* abs) {

	//�ж�ͨѶ¼��ϵ���Ƿ�Ϊ�㣬Ϊ���򷵻أ���Ϊ�����ʾ������ϵ��
	if (abs->m_Size == 0) {

		cout << "ͨѶ¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");

		return;
	}
	else {

		for (int i = 0; i < abs->m_Size; i++) {

			//��ӡ��������ϵ����Ϣ
			cout << "��ϵ��" << i + 1 << ":" << "\t";
			cout << "����:" << abs->presonarray[i].m_Name << "\t";
			cout << "�Ա�:" << (abs->presonarray[i].m_Sex == 1?"��" :"Ů") << "\t";
			cout << "����:" << abs->presonarray[i].m_Age << "\t";
			cout << "�绰:" << abs->presonarray[i].m_Phone << "\t";
			cout << "סַ:" << abs->presonarray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");
	}

}

//�����ϵ���Ƿ���ڣ����ڷ����������еľ���λ�ã��������򷵻�-1
//����һ��ͨѶ¼    ���������Ա�����
int isExist(addressbooks *abs, string name) {

	for (int j = 0; j < abs->m_Size; j++) {

		//�ҵ���ϵ�˵�λ����
		if (abs->presonarray[j].m_Name == name)
			return j;
	}
	//δ�ҵ���ϵ��
	return -1;
}

//3.ɾ����ϵ��
void deleteperson(addressbooks *abs) {

	string name;
	cout << "������ɾ����ϵ��������" << endl;
	cin >> name;
	//isExist(abs, name);
	int ret = isExist(abs, name);
	if (ret == -1){

		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
		
	else{

		//����һ��ȷ���Ƿ�ɾ���Ĺ��ܣ�����1ȷ��ɾ��������2ȡ��ɾ��
		cout << "�Ƿ�ɾ����" << endl;
		cout << "1---ȷ��" << "\t";
		cout << "2---ȡ��" << endl;
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
			cout << "ɾ���ɹ���" << endl;
		}
		system("pause");
		system("cls");
	}
}

//4��������ϵ��
void searchperson(addressbooks* abs) {

	//����Ҫ���ҵ���ϵ�������������ڲ��޴��ˣ���������ʾ����ϵ�˵���Ϣ
	cout << "���������������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);//���ü����ϵ���Ƿ���ڵĺ�������ret���շ���ֵ

	if (ret == -1) {

		cout << "���޴���" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {

		//��ӡ����ѯ����ϵ����Ϣ
		cout << "��ϵ��" << ret + 1 << ":" << "\t";
		cout << "����:" << abs->presonarray[ret].m_Name << "\t";
		cout << "�Ա�:" << (abs->presonarray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����:" << abs->presonarray[ret].m_Age << "\t";
		cout << "�绰:" << abs->presonarray[ret].m_Phone << "\t";
		cout << "סַ:" << abs->presonarray[ret].m_Addr << endl;

		system("pause");
		system("cls");
	}
}

//5���޸���ϵ����Ϣ
void changeperson(addressbooks* abs) {

	cout << "�������޸���ϵ������" << endl;
	string name, phone, addr;
	int sex, age;

	cin >> name;
	int ret = isExist(abs, name);

	if (ret == -1) {
		
		//���޸���ϵ�˲����ڣ��Ƿ��½���ϵ��
		cout << "��ϵ�˲����ڣ��Ƿ��½���ϵ�ˣ�" << endl;
		cout << "1---��" << "\t";
		cout << "2---��" << endl;
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

		//�ҵ����޸�����Ϣ������޸�
		cout << "��ϵ��" << ret + 1 << ":" << "\t";
		cout << "����:" << abs->presonarray[ret].m_Name << "\t";
		cout << "�Ա�:" << (abs->presonarray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����:" << abs->presonarray[ret].m_Age << "\t";
		cout << "�绰:" << abs->presonarray[ret].m_Phone << "\t";
		cout << "סַ:" << abs->presonarray[ret].m_Addr << endl;

		//addperson(abs);
		cout << "�޸�������" << endl;
		cin >> name;
		abs->presonarray[ret].m_Name = name;
		cout << "�޸��Ա�1---��    2---Ů" << endl;
		while (true) {

			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->presonarray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		abs->presonarray[ret].m_Sex = sex;
		cout << "�޸����䣺" << endl;
		cin >> age;
		abs->presonarray[ret].m_Age = age;
		cout << "�޸ĵ绰��" << endl;
		cin >> phone;
		abs->presonarray[ret].m_Phone = phone;
		cout << "�޸�סַ��" << endl;
		cin >> addr;
		abs->presonarray[ret].m_Addr = addr;

		//�޸���ɺ���ʾ�޸���ϵ��������Ϣ
		cout << "�޸����" << endl;
		showperson(abs);
	}
}

//6�������ϵ��
void clearperson(addressbooks* abs) {

	//ȷ���Ƿ����������ϵ��
	cout << "�Ƿ����������ϵ�ˣ�" << endl;
	cout << "1110---ȷ��" << "\t";
	cout << "1101---ȡ��" << endl;
	int clear;
	cin >> clear;
	if (clear == 1110) {

		//ȷ�����
		abs->m_Size = 0;
		cout << "��ճɹ���" << endl;
		system("pause");
		system("cls");
	}
	else if (clear == 1101) {

		//ȡ�����
		system("pause");
		system("cls");
		return;
	}
	else {

		cout << "�����������������" << endl;
		clearperson(abs);
	}
}

//�˵�����
void showmenu() {

	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

int main() 
{
	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼��ϵ������
	abs.m_Size = 0;

	int select = 0;

	while (true) {

		//�˵��ĵ���
		showmenu();

		cin >> select;

		switch (select) {
		case 1://�����ϵ��
			addperson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4://4��������ϵ��
			searchperson(&abs);
			break;
		case 5://5���޸���ϵ��
			changeperson(&abs);
			break;
		case 6://6�������ϵ��
			clearperson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��!" << endl;
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			break;
		}
	}

	system("pause");

	return 0;
}