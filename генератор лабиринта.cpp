#include <iostream>
#include <ctime>

using namespace std;

class lab
{
	private:
		int s;
		char** pole;
	public:
		lab(int a)
		{
			cout << "Работает конструктор класса" << endl;
			system("pause");
			system("cls");
			s = a + 2;
			pole = new char* [s];
			for (int i = 0; i < s; i++)
				pole[i] = new char[s];
			for (int i = 0; i < s; i++)
				for (int j = 0; j < s; j++)
					pole[i][j] = 'a' + j - 1;
		}
		~lab()
		{
			cout << endl << "Работает деструктор класса" << endl;
			system("pause");
			system("cls");
		}
		void line(int* i)
		{
			if (((*i) == 0) || ((*i) == (s - 1)))
		}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int a, i = 0;
	cout << "Размер (чётное число)" << endl;
	cin >> a;
	system("cls");
	lab l(a);
	for (; i < (a + 2); i++)
		l.line(&i);
	
}