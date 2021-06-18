#include <iostream>
#include "Dado.h"
#include "rlutil.h"

void Dado::rectangleDraw(int posx, int posy) const
{
	int tam = 7;
	rlutil::setColor(rlutil::WHITE);
	for (int y = 1; y <= tam / 2; y++) {
		for (int x = 1; x <= tam; x++) {
			rlutil::locate(x + posx, y + posy);
			std::cout << (char)219;
		}
	}
}

void Dado::pointDraw(int posx, int posy) const
{
	int tam = 7;
	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::setColor(rlutil::BLACK);

	switch (_value)
	{
	case 1:
		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		std::cout << (char)254;
		break;

	case 2:

		if (rand() % 2) {
			rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
			std::cout << (char)220;


			rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
			std::cout << (char)223;
		}
		else {

			rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
			std::cout << (char)220;

			rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
			std::cout << (char)223;
		}
		

		break;

	case 3:
		if (rand() % 2) {
			rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
			std::cout << (char)220;


			rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
			std::cout << (char)223;
		}
		else {

			rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
			std::cout << (char)220;

			rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
			std::cout << (char)223;
		}


		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		std::cout << (char)254;

		

		break;


	case 4:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		std::cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		std::cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		std::cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		std::cout << (char)223;

		break;

	case 5:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		std::cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		std::cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		std::cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		std::cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		std::cout << (char)223;

		break;


	case 6:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		std::cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		std::cout << (char)220;


		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		std::cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		std::cout << (char)223;


		if (rand() % 2) {
			rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 / 4 + 1);
			std::cout << (char)220;

			rlutil::locate(posx + tam / 2 + 1, posy + tam / 2 - tam / 4 / 4);
			std::cout << (char)223;
		}
		else {
			rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 + 1);
			std::cout << (char)254;

			rlutil::locate(posx + tam - tam / 4, posy + tam / 4 + 1);
			std::cout << (char)254;
		}

		break;

	default:
		break;
	}
}

void Dado::shadowDraw(int posx, int posy) const
{
	int tam = 7;
	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::GREY);
	// sombra

	for (int y = posy + 2; y <= posy + tam / 2 + 1; y++) {
		rlutil::locate(posx + tam + 1, y);
		std::cout << (char)219;
	}


	for (int x = posx + 2; x <= posx + tam + 1; x++) {
		rlutil::locate(x, posy + tam / 2 + 1);
		std::cout << (char)223;
	}

	rlutil::locate(posx + tam + 1, posy + 1);
	std::cout << (char)220;

	rlutil::locate(2, 20);
}

Dado::Dado(): _value(1)
{}

int Dado::getValue() const
{
	return _value;
}

void Dado::roll()
{
	_value = rand() % 6 + 1;
}

void Dado::render(int x, int y) const
{
	if (_drawable) {
		rectangleDraw(x, y);
		pointDraw(x, y);
		shadowDraw(x, y);
	}
}

void Dado::setDrawable(bool d)
{
	_drawable = d;
}
