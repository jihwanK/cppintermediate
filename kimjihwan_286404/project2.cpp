template <typename Type>
class Singleton
{
protected:
	Singleton() = default;

private:
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;

public:
	static Type& getInstance()
	{
		static Type instance;
		return instance;
	}
};

/*
class Mouse : public Singleton<Mouse>
{
public:
	Mouse() {}
};

int main()
{
	Mouse &c = Mouse::getInstance();
}
*/


class Cursor: public Singleton<Cursor>
{
	public:
		Cursor(int x, int y ) {}
};

int main()
{
	Cursor& c = Cursor::getInstance(1, 2);
}
