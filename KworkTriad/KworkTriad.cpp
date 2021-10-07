#include <iostream>
#include <string>

/// <summary>
/// класс Триада
/// </summary>
class Triad
{
private:
	/// <summary>
	/// первое число
	/// </summary>
	int _a;

	/// <summary>
	/// Второе число
	/// </summary>
	int _b;

	/// <summary>
	/// Третье число
	/// </summary>
	int _c;

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Triad() : _a(0), _b(0), _c(0) {}

	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="a">перваое число</param>
	/// <param name="b">второе число</param>
	/// <param name="c">третьие число</param>
	Triad(int a, int b, int c) : _a(a), _b(b), _c(c) {}

	/// <summary>
	/// Оператор сравнении Логическое И. Сравнивает два объекта типа Triad
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Возвращает истину в случае если все ячейки равны</returns>
	bool operator==(const Triad& triad)
	{
		return this->_a == triad._a && this->_b == triad._b && this->_c == triad._c;
	}

	/// <summary>
	/// Оератор сравнения Логическое ИЛИ Сравнивает два объекта типа Triad
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Возвращает истину в случае если хотя бы одна ячейка будет отличаться от другой/returns>
	bool operator !=(const Triad& triad)
	{
		return this->_a != triad._a || this->_b != triad._b || this->_c != triad._c;
	}

	/// <summary>
	/// Оператор сравнение больше 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта больше всех ячеек второго объекта</returns>
	bool operator > (const Triad& triad)
	{
		return this->_a > triad._a && this->_b > triad._b && this->_c > triad._c;
	}

	/// <summary>
	/// Оператор сравнения меньше
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта меньше всех ячеек второго объекта</returns>
	bool operator < (const Triad& triad)
	{
		return this->_a < triad._a&& this->_b < triad._b&& this->_c < triad._c;
	}

	/// <summary>
	/// Оператор сравнения больше или равно
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта больше или равны всех ячеек второго объекта</returns>
	bool operator >= (const Triad& triad)
	{
		return this->_a >= triad._a && this->_b >= triad._b && this->_c >= triad._c;
	}

	/// <summary>
	/// Оператор сравнения меньше или равно
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта меньше или равны всех ячеек второго объекта</returns>
	bool operator <= (const Triad& triad)
	{
		return this->_a <= triad._a && this->_b <= triad._b && this->_c <= triad._c;
	}

	/// <summary>
	/// Возравщает значение первой ячейки
	/// </summary>
	/// <returns></returns>
	int getA()
	{
		return _a;
	}

	/// <summary>
	/// Возравщает значение второй ячейки
	/// </summary>
	/// <returns></returns>
	int getB()
	{
		return _b;
	}

	/// <summary>
	/// Возравщает значение третей ячейки
	/// </summary>
	/// <returns></returns>
	int getC()
	{
		return _c;
	}

	/// <summary>
	/// Выводит информацию на монитор
	/// </summary>
	void ShowInfo()
	{
		std::cout << "Triada: (" << _a << ", " << _b << ", " << _c << ")";
	}
};

/// <summary>
/// класс время
/// </summary>
class Time
{
private:
	/// <summary>
	/// Часы
	/// </summary>
	int _h;

	/// <summary>
	/// Минуты
	/// </summary>
	int _m;

	/// <summary>
	/// Секунды
	/// </summary>
	int _s;

public:
	/// <summary>
	/// Конструктор по умолчанию 
	/// </summary>
	Time() : _h(0), _m(0), _s(0) {}

	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="h"></param>
	/// <param name="m"></param>
	/// <param name="s"></param>
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

	/// <summary>
	/// Оператор сравнении Логическое И. Сравнивает два объекта типа Time
	/// </summary>
	/// <param name="t"></param>
	/// <returns>Возвращает истину в случае если все ячейки равны</returns>
	bool operator==(const Time& t)
	{
		return this->_h == t._h && this->_m == t._m && this->_s == t._s;
	}

	/// <summary>
	/// Оператор сравнении Логическое И. Сравнивает два объекта типа Time
	/// </summary>
	/// <param name="t"></param>
	/// <returns>Возвращает истину в случае если хотя бы одна ячейка не равна другой</returns>
	bool operator !=(const Time& t)
	{
		if (this->_h != t._h)
		{
			return true;
		}
		else
		{
			if (this->_m != t._m)
			{
				return true;
			}
			else
			{
				return this->_s != t._s;
			}
		}
	}

	/// <summary>
	/// Оператор сравнение больше 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта больше всех ячеек второго объекта</returns>
	bool operator > (const Time& t)
	{
		if (this->_h > t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m > t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s > t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// Оператор сравнение меньше 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта меньше всех ячеек второго объекта</returns>
	bool operator < (const Time& t)
	{
		if (this->_h < t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m < t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s < t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// Оператор сравнение меньше или равны 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта меньше или равны всех ячеек второго объекта</returns>
	bool operator <= (const Time& t)
	{
		if (this->_h < t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m < t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s <= t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// Оператор сравнение больше или равны 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>Истина в случае если все ячейки первого объекта больше или равны всех ячеек второго объекта</returns>
	bool operator >= (const Time& t)
	{
		if (this->_h < t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m < t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s >= t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// Возвращает часы
	/// </summary>
	/// <returns></returns>
	int getHours()
	{
		return _h;
	}

	/// <summary>
	/// Возвращает минуты
	/// </summary>
	/// <returns></returns>
	int getMinutes()
	{
		return _m;
	}

	/// <summary>
	/// Возвращает секунды
	/// </summary>
	/// <returns></returns>
	int getSeconds()
	{
		return _s;
	}

	/// <summary>
	/// Выводит информацию о времени на монитор
	/// </summary>
	/// <returns></returns>
	void ShowInfo()
	{
		std::cout << "Time: (";
		printLessTime(_h);
		std::cout << ":";
		printLessTime(_m);
		std::cout << ":";
		printLessTime(_s);
		std::cout << ")";
	}

private:
	/// <summary>
	/// Корректный вывод времени
	/// </summary>
	/// <param name="value"></param>
	void printLessTime(int value)
	{
		std::cout << ((value < 9) ? "0" + value : std::to_string(value));
	}

	/// <summary>
	/// Проверка на корректность часов
	/// </summary>
	/// <param name="h"></param>
	/// <returns></returns>
	bool isHourse(int h)
	{
		return h >= 0 && h <= 24;
	}

	/// <summary>
	/// Проверка на корректность минут или секунд
	/// </summary>
	/// <param name="h"></param>
	/// <returns></returns>
	bool isMinutesOrSeconds(int ms)
	{
		return ms >= 0 && ms < 60;
	}
};

/// <summary>
/// Ввод пользователя 
/// </summary>
/// <returns>объект типа Triad</returns>
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

/// <summary>
/// Ввод пользователя 
/// </summary>
/// <returns>объект типа Time</returns>
Time getTimeFromUser()
{
	int a;
	int b;
	int c;
	std::cout << "Введите Время\n";
	std::cout << "Введите часы: ";
	std::cin >> a;
	std::cout << "Введите минуы: ";
	std::cin >> b;
	std::cout << "Введите секунды: ";
	std::cin >> c;
	try
	{
		return Time(a, b, c);
	}
	catch (...)
	{

	}
}

/// <summary>
/// Вывод сравнений Triad
/// </summary>
/// <param name="tr1"></param>
/// <param name="tr2"></param>
void ShowСomparisoTriad(Triad tr1, Triad tr2)
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

/// <summary>
/// Вывод сравнений Time
/// </summary>
/// <param name="tr1"></param>
/// <param name="tr2"></param>
void ShowСomparisoTime(Time t1, Time t2)
{
	t1.ShowInfo();
	std::cout << " == ";
	t2.ShowInfo();
	std::cout << " = " << (t1 == t2) << "\n";
	t1.ShowInfo();
	std::cout << " != ";
	t2.ShowInfo();
	std::cout << " = " << (t1 != t2) << "\n";

	t1.ShowInfo();
	std::cout << " > ";
	t2.ShowInfo();
	std::cout << " = " << (t1 > t2) << "\n";
	t1.ShowInfo();
	std::cout << " < ";
	t2.ShowInfo();
	std::cout << " = " << (t1 < t2) << "\n";

	t1.ShowInfo();
	std::cout << " >= ";
	t2.ShowInfo();
	std::cout << " = " << (t1 >= t2) << "\n";
	t1.ShowInfo();
	std::cout << " <= ";
	t2.ShowInfo();
	std::cout << " = " << (t1 <= t2) << "\n";
}

/// <summary>
/// Вывод меню для работы с Triad
/// </summary>
void ShowMenuTriad()
{
	bool isExist = false;
	int numberCommand;
	Triad tr1;
	Triad tr2;
	while (isExist == false)
	{
		std::cout << "1) Ввести триады.\n";
		std::cout << "2) Вывести триады на монитор.\n";
		std::cout << "3) Вывести сравнения триад.\n";
		std::cout << "4) Просмотреть определенную ячейку триады.\n";
		std::cout << "5) чтобы выйти из программы.\n";
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
			ShowСomparisoTriad(tr1, tr2);
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
}

/// <summary>
/// Вывод меню для работы с Time
/// </summary>
void ShowMenuTime()
{
	bool isExist = false;
	int numberCommand;
	Time t1;
	Time t2;
	while (isExist == false)
	{
		std::cout << "1) Ввести время.\n";
		std::cout << "2) Вывести вермя на монитор.\n";
		std::cout << "3) Вывести сравнения времени.\n";
		std::cout << "4) Просмотреть определенную ячейку времени.\n";
		std::cout << "5) чтобы выйти из программы.\n";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
		{
			t1 = getTimeFromUser();
			t2 = getTimeFromUser();
			break;
		}
		case 2:
		{
			t1.ShowInfo();
			std::cout << '\n';
			t2.ShowInfo();
			std::cout << '\n';
			break;
		}
		case 3:
		{
			ShowСomparisoTime(t1, t2);
			break;
		}
		case 4:
		{
			int index;
			t1.ShowInfo();
			std::cout << '\n';
			bool isCorrect = false;
			while (isCorrect == false)
			{
				std::cout << "Введите ячейку Времени(1, 2, 3): ";
				std::cin >> index;
				switch (index)
				{
				case 1:
				{
					std::cout << t1.getHours() << '\n';
					isCorrect = true;
					break;
				}
				case 2:
				{
					std::cout << t1.getMinutes() << '\n';
					isCorrect = true;
					break;
				}
				case 3:
				{
					std::cout << t1.getSeconds() << '\n';
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
			std::cout << "Неверная команда!\n";
			break;
		}
		std::cout << "--------------------\n";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	bool isExist = false;
	int numberCommand;
	while (isExist == false)
	{
		std::cout << "1) Работа со временем.\n";
		std::cout << "2) Работа с триадами.\n";
		std::cout << "3) Выйти из приложения.\n";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
		{
			ShowMenuTime();
			break;
		}
		case 2:
		{
			ShowMenuTriad();
			break;
		}
		case 3:
		{
			isExist = true;
			break;
		}
		default:
			std::cout << "Неверная команда!\n";
			break;
		}
	}
	return 0;
}