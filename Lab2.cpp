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
	Complex& operator+(const Complex& x) {
		Complex* tmp = new Complex();
		tmp->re = this->re + x.re;
		tmp->im = this->im + x.im;
		return *tmp;
	}
	Complex& operator=(const Complex& x) {
		this->re = x.re;
		this->im = x.im;
		return *this;
	}
	Complex& operator-(const Complex& x) {
		Complex* tmp = new Complex();
		tmp->re = this->re - x.re;
		tmp->im = this->im - x.im;
		return *tmp;
	}
	Complex& operator*(const Complex& x) {
		Complex* tmp = new Complex();
		tmp->re = this->re * x.re - this->im * x.im;
		tmp->im = this->re * x.im + this->im * x.re;
		return *tmp;
	}
	Complex& operator/(const Complex& x) {
		Complex* tmp = new Complex();
		tmp->re = (x.re * this->re + x.im * this->im) / (this->re * this->re + this->im * this->im);
		tmp->im = (this->re * x.im - x.re * this->im) / (this->re * this->re + this->im * this->im);
		return *tmp;
	}
	Complex& operator+=(const Complex& x) {
		this->re = this->re + x.re;
		this->im = this->im + x.im;
		return *this;
	}
	Complex& operator-=(const Complex& x) {
		this->re = this->re - x.re;
		this->im = this->im - x.im;
		return *this;
	}
	Complex& operator*=(const Complex& x) {
		this->re = this->re * x.re - this->im * x.im;
		this->im = this->re * x.im + this->im * x.re;
		return *this;
	}
	Complex& operator/=(const Complex& x) {
		this->re = (x.re * this->re + x.im * this->im) / (this->re * this->re + this->im * this->im);
		this->im = (this->re * x.im - x.re * this->im) / (this->re * this->re + this->im * this->im);
		return *this;
	}
	friend ostream& operator<<(ostream& stream, const Complex& x) {
		if (x.im < 0) stream << x.re << x.im << "i" << endl;
		else stream << x.re << "+" << x.im << "i" << endl;
		return stream;
	}
	friend istream& operator>>(istream& istream, Complex& x) {
		istream >> x.re;
		istream >> x.im;
		return istream;
	}
	void print() {
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
	cout << tm;
	tm = x;
	cout << tm;
	tm = tm - t;
	cout << tm;
	tm = t * x;
	cout << tm;
	tm = x / t;
	cout << tm;
	tm += x;
	cout << tm;
	tm -= t;
	cout << tm;
	tm *= x;
	cout << tm;
	tm /= t;
	cout << tm;
	cin >> tm;
	cout << tm;
	return 0;
}