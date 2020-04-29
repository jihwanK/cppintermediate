#include <iostream>
#include <string>
using namespace std;

class People
{
	string name;
	string addr;
	int age;

	public:
	People(string n, string add, int a) : name(n), addr(add), age(a) {}

	// 복사생성자
	People(const People& p) : name(p.name), addr(p.addr), age(p.age)
	{
		cout << "copy constructor" << endl;

		cout << "name: " << name << endl;
		cout << "addr: " << addr << endl;
		cout << "age: " << age << endl;
	}

	// 대입연산자
	People& operator= (const People& p)
	{
		cout << "= operator" << endl;

		name = p.name;
		addr = p.addr;
		age = p.age;

		cout << "name: " << name << endl;
		cout << "addr: " << addr << endl;
		cout << "age: " << age << endl;

		return *this;
	}

	// Move 생성자
	People(People&& p) : name(move(p.name)), addr(move(p.addr)), age(move(p.age))
	{
		cout << "move constructor" << endl;

		cout << "name: " << name << endl;
		cout << "addr: " << addr << endl;
		cout << "age: " << age << endl;
	}

	// Move 대입연산자
	People& operator= (People&& p)
	{
		cout << "move = operator" << endl;

		name = move(p.name);
		addr = move(p.addr);
		age = move(p.age);

		cout << "name: " << name << endl;
		cout << "addr: " << addr << endl;
		cout << "age: " << age << endl;

		return *this;
	}

	void print()
	{
		cout << name << " " << addr << " " << age << endl;
	}
};


int main()
{
	// 1.
	People* buff = static_cast<People*>(operator new(sizeof(People) * 10));
	for (int i = 0; i < 10; i++)
		new(&buff[i]) People{"홍길동", "서울", 20};

	// 2.
	People* tmp = static_cast<People*>(operator new(sizeof(People) * 20));
	for (int i = 0; i < 10; i++)
		tmp[i] = move_if_noexcept(buff[i]);

	for (int i = 10; i < 20; i++)
		new(&tmp[i]) People{"unknown", "unknown", 0};

	delete(buff);
	buff = tmp;
	tmp = nullptr;

	// 3.
	for (int i = 0; i < 20; i++)
		buff[i].print();

	// 4.
	for (int i = 19; i >= 17; i--)
		buff[i].~People();
}
