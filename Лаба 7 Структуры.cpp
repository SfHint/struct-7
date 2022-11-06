#include <iostream>
#include <string.h>
using namespace std;
// Объявить структуру с заданными полями. Динамически выделить память для хранения списка. Ввести данные.
// Выполнить задание, результат вывести на экран

// Имеется список сотрудников предприятия. Каждый элемент списка содержит следующую информацию: фамилия, год рождения
// год поступления на работу. Вывести информацию о сотрудниках фирмы, родившихся после 1985 года в порядке
// убывания стажа работы

// SELECT * FROM сотрудники WHERE год > 1985 ORDER BY стаж DESC
int main()
{
	setlocale(LC_ALL, "RUS");
	struct rabotnic
	{
		char fam[20];
		int god;
		int postup;
	} *spisok;
	int colvo;
	cout << "Введите количество рабочих: " << endl;
	cin >> colvo;
	spisok = new rabotnic[colvo];
	for (int i = 0; i < colvo; i++)
	{
		cout << "Введите фамилию: ";
		cin >> spisok[i].fam;
		cout << "Введите год рождения: ";
		cin >> spisok[i].god;
		cout << "Введите год поступления на службу: ";
		cin >> spisok[i].postup;
		cout << endl;
	}
	int k = 0;
	for(int i=0;i<colvo;i++)
		for (int j = i + 1; j < colvo; j++)
		{
			int godi=2022-spisok[i].postup, godj=2022-spisok[j].postup;
			if (godi < godj) swap(spisok[j], spisok[i]);
		}
	for (int i=0; i < colvo; i++)
	{
		k++;
		if (spisok[i].god > 1985)
		{
			cout << "Фамилия: " << spisok[i].fam << " Год рожд: " << spisok[i].god << " Год поступ.: " << spisok[i].postup << endl;
		}
	}
	delete[]spisok;
	return 0;
}