#include<iostream> 

class String
{
private:

	char* str;  //��������� �� ������
	int SizeStr;  //������ ������

public:
	//���������� ��� ����������
	String()
	{
		str = nullptr;
		SizeStr = 0;
	}

	//���������� � ����������� (���������� �������� ������)
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
	//���������� ��������� ������������, ��������� ��� ������������ ���� �������� ������� �������)
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
	//���������� ����������� �������, ��������� ��� �������� ������ ����� ������� �� � ������ ������ ������
	String(const String& other)
	{
		SizeStr= strlen(other.str);
		this->str = new char[SizeStr + 1];
		for (int i = 0; i < SizeStr; i++)
		{
			this->str[i] = other.str[i];
		}
		str[SizeStr] = '\0';
	}
	//���������� �������� �������� + (������������ �����)
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
	//���� ����������� ����� ������ (�������) �� ������������� \0
	int GetSizeStr()
	{
		return SizeStr;
	}
	//����������,������� ���������� ����� ��� ������ ��� �� ������ ���������
	~String()
	{
		delete[]str;
	}

	void Print()
	{
		std::cout << str;
	}


};

void main()
{
	setlocale(0, "RU");
	String str1("111");
	String str2("2222");

	String result;
	result = str1 + str2;

	result.Print();
	std::cout << std::endl;
	std::cout << str1.GetSizeStr() << std::endl;
	std::cout << str2.GetSizeStr() << std::endl;
	std::cout << result.GetSizeStr() << std::endl;












}