#include <iostream>
using namespace std;


class Complex {
public:
	Complex() { cout << "Element " << this << " created" << endl; }
	Complex(const Complex& other) {
		cout << "Element " << this << " created" << endl;
		this->re = other.re;
		this->im = other.im;
	}
	Complex(double re, double im) : re(re), im(im) {}
	~Complex() { cout << "Element " << this << " deleted" << endl; }
private:
	double re;
	double im;
public:
	Complex operator+(const Complex& x) {
		Complex tmp;
		tmp.re = this->re + x.re;
		tmp.im = this->im + x.im;
		return tmp;
	}
	void push() {
		cout << this->re << this->im;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Complex t(1,2), tm, x(2,1);
	tm = t + x;
	tm.push();
	return 0;
}