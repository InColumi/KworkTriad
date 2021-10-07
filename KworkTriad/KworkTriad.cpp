#include <iostream>

class Triad
{
private:
	int _a;
	int _b;
	int _c;

public:
	Triad() : _a(0), _b(0), _c(0) {}
	Triad(int a, int b, int c) : _a(a), _b(b), _c(c) {}

	bool operator==(const Triad& triad)
	{
		return this->_a == triad._a && this->_b == triad._b && this->_c == triad._c;
	}

	bool operator !=(const Triad& triad)
	{
		return this->_a != triad._a || this->_b != triad._b || this->_c != triad._c;
	}
	bool operator > (const Triad& triad)
	{
		return this->_a > triad._a && this->_b > triad._b && this->_c > triad._c;
	}

	bool operator < (const Triad& triad)
	{
		return this->_a < triad._a&& this->_b < triad._b&& this->_c < triad._c;
	}

	bool operator >= (const Triad& triad)
	{
		return this->_a >= triad._a && this->_b >= triad._b && this->_c >= triad._c;
	}

	bool operator <= (const Triad& triad)
	{
		return this->_a <= triad._a && this->_b <= triad._b && this->_c <= triad._c;
	}

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

	void ShowInfo()
	{
		std::cout << "Triada: (" << _a << ", " << _b << ", " << _c << ")";
	}
};

class Time
{
private:
	int _h;
	int _m;
	int _s;

public:
	Time(int h, int m, int s)
	{
		if (isHourse(h))
		{
			if (isMinutesOrSeconds(m))
			{
				if (isMinutesOrSeconds(s))
				{
					_h = h;
					_m = m;
					_s = s;
				}
				else
				{
					std::cout << "Секунды должны быть в интервале [0, 59].\n";
					throw - 1;
				}
			}
			else
			{
				std::cout << "Минуты должны быть в интервале [0, 59].\n";
				throw - 1;
			}
		}
		else
		{
			std::cout << "Часы должны быть в интервале [0, 24].\n";
			throw - 1;
		}
	}
private:
	bool isHourse(int h)
	{
		return h >= 0 && h <= 24;
	}

	bool isMinutesOrSeconds(int ms)
	{
		return ms >= 0 && ms < 60;
	}
};

Triad getTriadFromUser()
{
	int a;
	int b;
	int c;
	std::cout << "Введите триаду\n";
	std::cout << "Введите первое число: ";
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Введите третье число: ";
	std::cin >> c;
	return Triad(a, b, c);
}

void ShowСomparison(Triad tr1, Triad tr2)
{
	tr1.ShowInfo();
	std::cout << " == ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 == tr2) << "\n";
	tr1.ShowInfo();
	std::cout << " != ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 != tr2) << "\n";

	tr1.ShowInfo();
	std::cout << " > ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 > tr2) << "\n";
	tr1.ShowInfo();
	std::cout << " < ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 < tr2) << "\n";

	tr1.ShowInfo();
	std::cout << " >= ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 >= tr2) << "\n";
	tr1.ShowInfo();
	std::cout << " <= ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 <= tr2) << "\n";
}

void ShowMenu()
{
	std::cout << "1) Ввести триады.\n";
	std::cout << "2) Вывести триады на монитор.\n";
	std::cout << "3) Вывести сравнения триад.\n";
	std::cout << "4) Просмотреть определенную ячейку триады.\n";
	std::cout << "5) чтобы выйти из программы.\n";
}
int main()
{
	setlocale(LC_ALL, "rus");

	bool isExist = false;
	int numberCommand;
	Triad tr1;
	Triad tr2;
	while (isExist == false)
	{
		ShowMenu();

		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
		{
			tr1 = getTriadFromUser();
			tr2 = getTriadFromUser();
			break;
		}
		case 2:
		{
			tr1.ShowInfo();
			std::cout << '\n';
			tr2.ShowInfo();
			std::cout << '\n';
			break;
		}
		case 3:
		{
			ShowСomparison(tr1, tr2);
			break;
		}
		case 4:
		{
			int index;
			tr1.ShowInfo();
			std::cout << '\n';
			bool isCorrect = false;
			while (isCorrect == false)
			{
				std::cout << "Введите ячейку триады(1, 2, 3): ";
				std::cin >> index;
				switch (index)
				{
				case 1:
				{
					std::cout << tr1.getA() << '\n';
					isCorrect = true;
					break;
				}
				case 2:
				{
					std::cout << tr1.getB() << '\n';
					isCorrect = true;
					break;
				}
				case 3:
				{
					std::cout << tr1.getC() << '\n';
					isCorrect = true;
					break;
				}

				default:
					std::cout << "Неверная ячейка!\n";
					break;
				}
			}
			break;
		}
		case 5:
		{
			isExist = true;
			break;
		}
		default:
			break;
		}
		std::cout << "--------------------\n";
	}
	return 0;
}