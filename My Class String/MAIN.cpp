#include<iostream> 

class String
{
private:

	char* str;  //Указатель на строку
	int SizeStr;  //Размер строки

public:
	//Конструтор без параметров
	String()
	{
		str = nullptr;
		SizeStr = 0;
	}

	//Конструтор с параметрами (необходимо передать строку)
	String(const char* STR)
	{
		SizeStr = strlen(STR);

		this->str = new char[SizeStr + 1];

		for (int i = 0; i < SizeStr; i++)
		{
			this->str[i] = STR[i];
		}

		this->str[SizeStr] = '\0';
	}
	//Метод оператора присваивания = , необходим для присваивания всех значений обьекта другому)
	String& operator =(const String& other)
	{
		SizeStr = strlen(other.str);

		if (this->str != nullptr)
		{
			delete[]str;
		}

		this->str = new char[SizeStr + 1];

		for (int i = 0; i < SizeStr; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[SizeStr] = '\0';

		return *this;


	}
	//Коструктор копирования обьекта, необходим для создания точной копии обьекта но в другой обасти памяти
	String(const String& other)
	{
		SizeStr = strlen(other.str);
		this->str = new char[SizeStr + 1];
		for (int i = 0; i < SizeStr; i++)
		{
			this->str[i] = other.str[i];
		}
		str[SizeStr] = '\0';
	}
	//Метод оператор сложения + (Конкатонация строк)
	String operator +(const String& other)
	{
		String Together;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		Together.SizeStr = thisLength + otherLength;
		Together.str = new char[Together.SizeStr + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			Together.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			Together.str[i] = other.str[j];
		}

		Together.str[Together.SizeStr] = '\0';

		return Together;

	}
	//Метод двозвращает длину строки (обьекта) до теминирующего \0
	int GetSizeStr()
	{
		return SizeStr;
	}
	//Метод оператора равенства == , необходим для сравнивания двох или больше обьектов на равность
	bool operator == (const String& other)
	{
		if (this->SizeStr != other.SizeStr)
		{
			return false;
		}
		for (int i = 0; i < this->SizeStr; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}
	//Метод оператора не равенства != 
	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}
	//Метод возвращает символ по индексу,который лежит в строке
	char& operator[](int index)
	{
		return this->str[index];
	}
	//Конструктор премещения служит для оптимизации кода , мы не копируем обькт ,а проста начинаем на его указывать 
	//(компилятор выбирает более оптиимизированый констурктор)
	String(String&& other)
	{
		this->SizeStr = other.SizeStr;
		this->str = other.str;

		other.str = nullptr;

	}
	//Деструктор,который уничтожает обькт при выхода его из обасти видимости
	~String()
	{
		delete[]str;
	}
	//Метод выводит строку в консоль
	void Print()
	{
		std::cout << str << std::endl;
	}


};

void main()
{
	setlocale(0, "RU");
	String str1("1234");
	String str2("world");


	String result;
	result = str1 + str2;

	result.Print();










}