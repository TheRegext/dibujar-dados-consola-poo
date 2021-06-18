#pragma once
class Dado
{
private:
	int _value;
	bool _drawable=true;

	void rectangleDraw(int x, int y) const;
	void pointDraw(int x, int y) const;
	void shadowDraw(int x, int y) const;
	

public:
	Dado();
	int getValue() const;
	void roll();
	void render(int x, int y) const;
	void setDrawable(bool d);
};

