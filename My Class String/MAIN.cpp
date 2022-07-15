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
	String& operator =(const char* STR)
	{
		int length = strlen(STR);
		delete[]str;
		if (str != nullptr)
		{
			str = nullptr;
		}
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = STR[i];
		}
		str[length] = '\0';
		return *this;
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
	String str("test");
	String str2("second str");

	str2 = str;
	str2.Print();












}