#include <iostream>
using namespace std;

class Point
{
	public:
	int a, b;
		Point(int a, int b) : a(a), b(b) {}
};

template<typename T> class Vector
{
	T* buff;
	int sz;
	int capa;

	public:
	Vector(int size, T init) : sz(size), capa(size)
	{
		buff = (T*)malloc(sizeof(T) * sz);

		for (int i = 0; i < sz; i++)
			buff[i] = init;
	}

	Vector(initializer_list<T> list) : sz(list.size()), capa(list.size())
	{
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		int i = 0;
		for (auto ele : list)
			buff[i++] = ele;
	}

	int size() { return sz; }

	int capacity() { return capa; }

	void resize(int size, T init)
	{
		if (capa < size)
		{
			if (capa == 0)
			{
				sz = size;
				capa = size;

				buff = static_cast<T*>(operator new(sizeof(T) * sz));

				for (int i = 0; i < sz; i++)
					new(&buff[i]) T(init);
			}
			else
			{
				T* tmp = static_cast<T*>(operator new(sizeof(T) * size));

				for (int i = 0; i < sz; i++)
					tmp[i] = buff[i];

				for (int i = sz; i < size; i++)
					new(&buff[i]) T(init);

				sz = size;
				capa = size;
				delete(buff);
				buff = tmp;
			}
		}
		else 
		{
			for (int i = 0; i < size; i++)
			{
				buff[i].~T();
				new(&buff[i]) T(init);
			}
			
			for (int i = sz-1; i >= size; i--)
				buff[i].~T();

			sz = size;
		}
	}

	T* begin() { return buff; }
	T* end() { return buff + sz; }
};

int main()
{
	// 1.
	Vector<Point> v(10, Point(1,1));

	// 2.
	v.resize(20, Point(0,0));

	// 3.
	v.resize(10, Point(1,1));

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	// 4.
	Vector<int> v2{1,2,3,4,5,6,7,8,9,10};

	// 5. 
	for (auto n : v2)
		cout << n << endl;
}

