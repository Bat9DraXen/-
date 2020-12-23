#include <iostream>
#include <ctime>

using namespace std;

class lab
{
	private:
		int v, g;
		char** pole;
	public:
		lab(int a, int b)
		{
			cout << "Работает конструктор класса" << endl;
			system("pause");
			system("cls");
			v = b + 2;
			g = a + 2;
			pole = new char* [v];
			for (int i = 0; i < v; i++)
				pole[i] = new char[g];
			for (int i = 0; i < v; i++)
				for (int j = 0; j < g; j++)
					pole[i][j] = 'a' + j - 1;
		}
		~lab()
		{
			cout << endl << "Работает деструктор класса" << endl;
			system("pause");
			system("cls");
		}
		void first(int* i)
		{
			for (int j = 0; j < g; j++)
			{
				pole[0][j] = '#';
				cout << pole[0][j];
			}
			cout << endl;
			(*i)++;
		}
		void vert(int* i)
		{
			if ((*i) == 1)
			{
				int a = 0, b = -1;
				for (int j = 0; j < g; j++)
				{
					b++;
					if (((a < ((g / 4) + 1)) && (rand() % (6 - b) == 0) && (pole[(*i)][j - 1] != '#') && (pole[(*i)][j + 1] != '#') && (j < (g - 2))) || (j == 0) || (j == (g - 1)))
					{
						pole[(*i)][j] = '#';
						a++;
						b = 0;
					}
					else
					{
						if ((pole[(*i)][j - 1] != '#') && (pole[(*i)][j + 1] != '#'))
						{
							pole[(*i)][j] = pole[(*i)][j - 1];
						}
						b++;
					}
					cout << pole[(*i)][j];
				}
				cout << endl;
				(*i)++;
			}
			else
			{

			}
		}
		void gor(int* i)
		{
			for (int j = 0; j < g; j++)
			{
				pole[(*i)][j] = pole[(*i) - 1][j];
				cout << pole[(*i)][j];
			}

			cout << endl;
		}
		void end()
		{
			system("cls");
			for (int i = 0; i < v; i++)
			{
				for (int j = 0; j < g; j++)
				{
					if (pole[i][j] != '#')
						pole[i][j] = ' ';
					cout << pole[i][j];
				}
				cout << endl;
			}
		}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int a, b, i = 0;
	cout << "Введите длину" << endl;
	cin >> a;
	system("cls");
	cout << "Введите ширину" << endl;
	cin >> b;
	system("cls");
	lab l(a, b);
	l.first(&i);
	for (;i <= (b + 2); i++)
	{
		switch (i % 2)
		{
			case 0:
			{
				l.gor(&i);
				break;
			}
			case 1:
			{
				l.vert(&i);
				break;
			}
			default:
			{
				cout << "Ты как из дурки сбежал. Из какой ты палаты? Быстро вернись обратно, шизоид!" << endl;
				break;
			}
		}
	}
	
}