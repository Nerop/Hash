#include "stdafx.h"
#include "iostream"
#include <fstream>
#include <string>
#include <cstdlib> 
#include <algorithm>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

string associativeArray[100] = {"0","0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0","0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

void saveToFile() {
	int size = ARRAY_SIZE(associativeArray);
	ofstream fout("F:/Studying/3_1/�++/2/Hash/output.txt");

	for (int i = 0; i < size; i++) {
		fout << associativeArray[i] << endl;
	}
	
	fout.close(); 
	system("pause");
}

void readFromFile() {
	string line;
	ifstream myfile("F:/Studying/3_1/�++/2/Hash/output.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i < ARRAY_SIZE(associativeArray); i++)
		{
			myfile >> associativeArray[i];
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	system("pause");
}

void addValue() {
	string key;
	string value;

	string key_string;
	string value_string;

	cout << "������� ����:\n";
	cin >> key;
	cout << "������� ��������:\n";
	cin >> value;

	key_string = string(key);
	value_string = string(value);

	for (int i = 0; i < ARRAY_SIZE(associativeArray); i += 2) {
		if (key_string == associativeArray[i]) {
			cout << "����� ���� ��� ����\n";
			system("pause");
			break;
		}
		else {
			if (associativeArray[i] == "0") {
				associativeArray[i] = key_string;
				associativeArray[i + 1] = value_string;
				cout << "���������!\n";
				system("pause");
				break;
			}
		}
	}
}

void deleteValue() {
	string key;
	string key_string;

	cout << "������� ����:\n";
	cin >> key;

	key_string = string(key);

	for (int i = 0; i < ARRAY_SIZE(associativeArray); i += 2) {
		if (key_string == associativeArray[i]) {
			associativeArray[i] = "0";
			associativeArray[i + 1] = "0";
			cout << "�������!\n";
			system("pause");
			break;
		}
		else {
			cout << "������ ����� ���!\n";
			system("pause");
			break;
		}
	}
}

void showHash() {
	int counter = 1;
	for (int i = 0; i <= ARRAY_SIZE(associativeArray) - 3; i += 2) {
		cout << counter << ". " << "����: " << associativeArray[i] << " " << "��������: " << associativeArray[i + 1] << " " << endl;
		counter++;
	}
	//cout << "counter = " << counter << endl;
	system("pause");
}

void getValueByIndex() {
	string indexValue;
	int intIndexValue;

	cout << "������� �������� �������:\n";
	cin >> indexValue;

	intIndexValue = stoi(indexValue);

	cout <<"�������� �� ������� " << indexValue << " = " << associativeArray[intIndexValue*2 + 1] << endl;
	system("pause");
}

void getValueByKeyName() {
	string keyValue;

	cout << "������� �������� �������:\n";
	cin >> keyValue;

	for (int i = 0; i <= ARRAY_SIZE(associativeArray) - 3; i += 2) {
		if (keyValue == associativeArray[i]) {
			cout << "�������� �� ������� " << keyValue << " = " << associativeArray[i + 1] << endl;
			system("pause");
		}
	}
}

void clearHash() {
	for (int i = 0; i <= ARRAY_SIZE(associativeArray) - 3; i++) {
		associativeArray[i] = "0";
	}
}

void sortHash() {
	int size = ARRAY_SIZE(associativeArray);
	string copyOfArray[50];
	string arrayOfSortedKeys[50];
	string key;
	string value;
	std::string::size_type pos;

	for (int i = 0, j = 0; i < size; i += 2, j++) {
		copyOfArray[j] = associativeArray[i] + "|" + associativeArray[i+1]; // ��������� ����� � �������� � ���� ������
		arrayOfSortedKeys[j] = associativeArray[i];
	}
	clearHash();
	
	sort(std::begin(arrayOfSortedKeys), std::end(arrayOfSortedKeys));

	for (int i = 0; i < ARRAY_SIZE(copyOfArray); i++) {
		pos = copyOfArray[i].find('|');

		if (pos != std::string::npos) {
			key = copyOfArray[i].substr(0, pos);
			value = copyOfArray[i].substr(pos + 1);
			//cout << key << " " << value << endl;
			for (int i = 0, j = 1; i <= ARRAY_SIZE(associativeArray); i++, j++) {
				if (arrayOfSortedKeys[j] == key) {
					associativeArray[i] = arrayOfSortedKeys[i];
					associativeArray[i + 1] = value;
				}
			}
		}
	}

	/*for (int i = 0; i < 50; i++) {
		cout << arrayOfSortedKeys[i] << endl;
	}*/

	system("pause");
}

int prompt_menu_item() {
	int variant;
	cout << "�������� �������\n" << endl;
	cout << "1. �������� ������\n"
		<< "2. �������� ��������\n"
		<< "3. ������� ��������\n"
		<< "4. ���������� �������� �� �������\n"
		<< "5. ���������� �������� �� �����\n"
		<< "6. �������������\n"
		<< "7. ��������� � ����\n"
		<< "8. ��������� �� �����\n"
		<< "9.����� �� ���������..." << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}

void menu() {
	system("cls");
	int variant = prompt_menu_item();

	do {
		switch (variant) {
		case 1:
			cout << "�������� ������" << endl;
			showHash();
			menu();
			break;
		case 2:
			cout << "�������� ��������" << endl;
			addValue();
			menu();
			break;
		case 3:
			cout << "������� ��������" << endl;
			deleteValue();
			menu();
			break;
		case 4:
			cout << "���������� �������� �� �������" << endl;
			getValueByIndex();
			menu();
			break;
		case 5:
			cout << "���������� �������� �� �����" << endl;
			getValueByKeyName();
			menu();
			break;
		case 6:
			cout << "�������������" << endl;
			sortHash();
			menu();
			break;
		case 7:
			cout << "��������� � ����" << endl;
			saveToFile();
			menu();
			break;
		case 8:
			cout << "��������� �� �����" << endl;
			readFromFile();
			menu();
			break;
		case 9:
			cout << "����� �� ���������..." << endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			cerr << "�� ������� �������� �������" << endl;
			menu();
		}
	} while (variant != 9);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}
