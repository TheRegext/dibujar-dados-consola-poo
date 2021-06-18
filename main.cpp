#include <iostream>
#include <time.h>
#include "Dado.h"
#include "rlutil.h"
using namespace std;

void clear(int x, int y, int w, int h) {
	for (int i = x; i < x + w; i++)
	{
		for (int j = y; j < y + h; j++)
		{
			rlutil::locate(i, j);
			std::cout << " ";
		}
	}
}

int main() {

	srand(time(NULL));

	Dado dados[6];

	for (Dado& d : dados) {
		d.roll();
	}

	for (Dado& d : dados) {
		std::cout << d.getValue() << "  ";
	}

	int pos = 10;
	for (int i = 0; i < 6; i++)
	{
		dados[i].render(pos + (rand() % 3), 7 + (rand() % 3));
		pos += 10;
	}

	rlutil::anykey();

	dados[3].setDrawable(false);

	clear(10, 7, pos - 13, 13);

	pos = 10;
	for (int i = 0; i < 6; i++)
	{
		dados[i].render(pos + (rand() % 3), 7 + (rand()%3));
		pos += 10;
	}


	return 0;
}