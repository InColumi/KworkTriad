#include <iostream>

class Triad
{
private:
	int _a;
	int _b;
	int _c;
public:
	Triad(int a, int b, int c) : _a(a), _b(b), _c(c) {}

	/*bool operator==(const Triad& triad)
	{
		return lhs == rhs.middle;

	}

	bool operator !=(const Triad& triad1)
	{
		return lhs == rhs.middle;
	}*/

	int getA()
	{
		return _a;
	}

	int getB()
	{
		return _b;
	}

	int getC()
	{
		return _c;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}