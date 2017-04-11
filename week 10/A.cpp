#include <iostream>
 class Point {
 public:
 	Point(int x, int y);
 	void setX(int x);
 	void setY(int y);
 	int getX();
 	int getY();
 	void printAddress();
 private:
    long _y;
 	long _x;
 	long *_z; //test
 };

void Point::printAddress() {
    std::cout << &_x << " " << &_y << " " << &_z << '\n';
}

Point::Point (int x, int y){
	_x = x;
	_y = y;
}
void Point::setX(int x){
	_x = x;
}
void Point::setY(int y){
	_y = y;
}

int Point::getX (){
	return _x;
}
int Point::getY (){
	return _y;
}

void passValue (Point p){
    std::cout << &p;
	p.setX(3);
}

void passRef (Point& p){
    std::cout << &p;
    p.setX(6);
}

 int main() {
 	Point A(0,3);
    std::cout << "&A: " << &A << '\n';
 	Point *B = new Point(0,2);
 	Point *C = new Point(0,3);
 	B = C;
 	passValue(A);
 	std::cout << '\n';
 	passRef(A);
 	std::cout << '\n';
 	B->printAddress();
    C->printAddress();
 	return 0;
 }
