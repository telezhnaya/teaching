

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
	// сценарий 1. Толком ничего не знаем о данных.
	while (getline(for_read, data)) {
		// прочитаем весь файл
		// на каждой итерации мы будем получать строчку в переменной data
		// переноса строки в этой строчке нет!
		string piece = data.substr(2, 5); // в этих 5 символах цифры, мы уверены в этом
		int a = stoi(piece); // получили число из строки
		cout << a << endl;
	}

	for_read.close();


	//сценарий 2. Точно знаем: каждая строка - это Имя, Возраст, Пол
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
		// запишем всех людей
		cnt++;
	}

	for_read.close();
	// на выходе - массив, в нем cnt записей о людях.


	// сценарий 3. Записать в файл
	ofstream for_write;
	for_write.open("result.txt");
	for (int i = 0; i < cnt; i++) {
		string line = "Name: " + people[i].name + ", Age: " + to_string(people[i].age);
		for_write << line << endl;
	}

	for_write.close();


    return 0;
}

