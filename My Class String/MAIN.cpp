#include<iostream> 

class String
{
public:
	String()
	{
		str = nullptr;
	}

	//Обьект принимает массив char и записывает в себя
	String(const char* STR)
	{
		int length = strlen(STR);

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = STR[i];
		}

		this->str[length] = '\0';
	}
	//Перегрузка оператора присваивания
	String& operator =(const String& other)
	{
		int length = strlen(other.str);

		if (this->str != nullptr)
		{
			delete[]str;
		}

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;


	}
	//Коструктор копирования обьекта
	String(const String& other)
	{
		int length = strlen(other.str);
		this->str = new char[length+1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}
	//Перегрузка оператор сложения (Конкатонация строк)
	String operator +(const String& other)
	{
		String Together;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		Together.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			Together.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			Together.str[i] = other.str[j];
		}

		Together.str[thisLength + otherLength] = '\0';

		return Together;

	}
	~String()
	{
		delete[]str;
	}

	void Print()
	{
		std::cout << str;
	}


private:
	char* str;
};

void main()
{
	setlocale(0, "RU");
	String str1("1111");
	String str2("2222");
	String result;
	result = str1 + str2;

	result.Print();












}