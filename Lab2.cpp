#include <iostream>
using namespace std;

class Complex {
public:
	Complex() {}
	Complex(double re, double im) : re(re), im(im) {}
private:
	double re;
	double im;
public:
	void Init(double re, double im) {
		this->re = re;
		this->im = im;
	}
	void Print(Complex* x) {
		if (this->im < 0) cout << this->re << this->im << "i" << endl; 
		else cout << this->re << "+" << this->im << "i" << endl;
	}

	void Add(Complex* x, Complex* y) {
		double a, b;
		a = x->re + y->re;
		b = x->im + y->im;
		result.Init(a, b);
		Complex::Print(&result);
	}

	void Sub(Complex* x, Complex* y) {
		double a, b;
		a = x->re - y->re;
		b = x->im - y->im;
		result.Init(a, b);
		Complex::Print(&result);
	}

	void Mul(Complex* x, Complex* y) {
		double a, b;
		a = x->re * y->re - x->im * y->im;
		b = x->re * y->im + x->im * y->re;
		result.Init(a, b);
		Complex::Print(&result);
	}

	void Div(Complex* x, Complex* y) {
		double a, b; 
		a = (x->re * y->re + x->im * y->im) / (y->re * y->re + y->im * y->im);
		b = (y->re * x->im - x->re * y->im) / (y->re * y->re + y->im * y->im);
		result.Init(a, b);
		Complex::Print(&result);
	}
}result, t;

int main()
{
	setlocale(LC_ALL, "ru");
	Complex* x = new Complex(1, 2);
	Complex* y = new Complex(2, 1);
	cout << "x = ";
	x->Print(x);
	cout << "y = ";
	y->Print(y);
	cout << "Результат сложения:";
	result.Add(x, y);
	cout << "Результат вычитания:";
	result.Sub(x, y);
	cout << "Результат умножения:";
	result.Mul(x, y);
	cout << "Результат деления:";
	result.Div(x, y);
	return 0;
}