#include <iostream>
using namespace std;


class Complex {
public:
	Complex() { }
	Complex(const Complex& other) {
		this->re = other.re;
		this->im = other.im;
	}
	Complex(double re, double im) : re(re), im(im) {}
	~Complex() { /*cout << "Element " << this << " deleted" << endl;*/ }
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
	Complex operator=(const Complex& x) {
		this->re = x.re;
		this->im = x.im;
		return *this;
	}
	Complex operator-(const Complex& x) {
		Complex tmp;
		tmp.re = this->re - x.re;
		tmp.im = this->im - x.im;
		return tmp;
	}
	Complex operator*(const Complex& x) {
		Complex tmp;
		tmp.re = this->re * x.re - this->im * x.im;
		tmp.im = this->re * x.im + this->im * x.re;
		return tmp;
	}
	void push() {
		if (this->im < 0) cout << this->re << this->im << "i" << endl;
		else cout << this->re << "+" << this->im << "i" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Complex t(1,2), x(2, 1);
	Complex tm;
	tm = x + t;
	tm.push();
	tm = x;
	tm.push();
	tm = tm - t;
	tm.push();
	tm = t * x;
	tm.push();
	return 0;
}