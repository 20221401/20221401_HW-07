#include<iostream>
using namespace std;

class Point {
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend Point& operator+=(Point& pos1, const Point& pos2);
	friend Point& operator++(Point& pos);
};

Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2) {
	return (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos);
}

Point operator-(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

Point& operator+=(Point& pos1, const Point& pos2) {
	pos1.xpos += pos2.xpos;
	pos1.ypos += pos2.ypos;
	return pos1;
}

Point& operator++(Point& pos) {
	++pos.xpos;
	++pos.ypos;
	return pos;
}

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;
	return 0;
}
