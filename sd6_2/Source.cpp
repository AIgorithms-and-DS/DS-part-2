#include <iostream>
#include "Kitchen.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int N;
	cout << "Input amount of tableware\n";
	cin >> N;

	Table table(N);
	WashMashine washmashine(N);
	Shelf shelf(N);

	for (int i = 0; i < N; ++i)
	{
		Tableware tableware;			//������ (1 �����)

		table.put(tableware);
		tableware.error = true;			//���� ������ �� ���������� � �����/����/�������, �� ������� ������
		tableware = table.take();


		i & 1 ? washmashine.loadFirst(tableware) : washmashine.loadSecond(tableware);
		tableware.error = true;
		tableware = (i & 1 ? washmashine.takeFirst() : washmashine.takeSecond());

		washmashine.wash(tableware);

		i & 1 ? shelf.putFront(tableware) : shelf.putBack(tableware);
		tableware.error = true;
		tableware = (i & 1 ? shelf.takeFront() : shelf.takeBack());

		if (!tableware.dirty)
			cout << i + 1 << "-�� ������� ��������\n";

		if (tableware.error)
			cout << "Error\n";
		
	}


	system("pause");

	return 0;
}