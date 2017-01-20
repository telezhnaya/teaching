

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

	ifstream for_read;
	for_read.open("source1.txt");
	

	if (!for_read.is_open()) {
		return 1;
	}

	string data;
	// �������� 1. ������ ������ �� ����� � ������.
	while (getline(for_read, data)) {
		// ��������� ���� ����
		// �� ������ �������� �� ����� �������� ������� � ���������� data
		// �������� ������ � ���� ������� ���!
		string piece = data.substr(2, 5); // � ���� 5 �������� �����, �� ������� � ����
		int a = stoi(piece); // �������� ����� �� ������
		cout << a << endl;
	}

	for_read.close();


	//�������� 2. ����� �����: ������ ������ - ��� ���, �������, ���
	struct Person {
		string name;
		int age;
		bool sex;
	};

	for_read.open("source2.txt");
	if (!for_read.is_open()) {
		return 1;
	}

	vector<Person> people(1000);
	int cnt = 0;
	while (for_read >> people[cnt].name >> people[cnt].age >> people[cnt].sex) {
		// ������� ���� �����
		cnt++;
	}

	for_read.close();
	// �� ������ - ������, � ��� cnt ������� � �����.


	// �������� 3. �������� � ����
	ofstream for_write;
	for_write.open("result.txt");
	for (int i = 0; i < cnt; i++) {
		string line = "Name: " + people[i].name + ", Age: " + to_string(people[i].age);
		for_write << line << endl;
	}

	for_write.close();


    return 0;
}

