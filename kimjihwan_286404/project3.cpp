#include <string>
#include <iostream>
using namespace std;

class People
{
	string name;
	string addr;
	int age;

public:
	People(string n, string add, int a) : name(n), addr(add), age(a) {}

	// 복사생성자
	People(const People &p) : name(p.name), addr(p.addr), age(p.age)
	{
		cout << "copy constructor" << endl;

		// cout << "name: " << name << endl;
		// cout << "addr: " << addr << endl;
		// cout << "age: " << age << endl;
	}

	// 대입연산자
	People &operator=(const People &p)
	{
		cout << "= operator" << endl;

		name = p.name;
		addr = p.addr;
		age = p.age;

		// cout << "name: " << name << endl;
		// cout << "addr: " << addr << endl;
		// cout << "age: " << age << endl;

		return *this;
	}

	// Move 생성자
	People(People &&p) : name(move(p.name)), addr(move(p.addr)), age(move(p.age))
	{
		cout << "move constructor" << endl;

		// cout << "name: " << name << endl;
		// cout << "addr: " << addr << endl;
		// cout << "age: " << age << endl;
	}

	// Move 대입연산자
	People &operator=(People &&p)
	{
		cout << "move = operator" << endl;

		name = move(p.name);
		addr = move(p.addr);
		age = move(p.age);

		// cout << "name: " << name << endl;
		// cout << "addr: " << addr << endl;
		// cout << "age: " << age << endl;

		return *this;
	}
};

int main()
{
	People p1{"홍길동", "서울", 20};
	People p2 = p1;
	People p3 = move(p1);
}
