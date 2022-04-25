#include<cmath>
#include<iostream>

/*---integrand---*/
double function(double x)
{
	return sin(x*x);
}

/*---right rectangle method---*/
double rightRectangle(double left, double right, double step)
{
	double sum = 0;
	double runner;

	for (runner = left + step; runner <= right; runner += step)
		sum += function(runner);

	sum *= step;

	return sum;
}

/*---trapezium method---*/
double trapezium(double left, double right, double step)
{
	double sum = 0;
	double runner;

	for (runner = left + step; runner < right; runner += step)
		sum += function(runner);

	sum = (sum + 0.5 * (function(left) + function(right))) * step;

	return sum;
}

int main()
{
	double a, b, step;

	std::cout << "Enter lower limit of integration:\n";
	std::cin >> a;

	std::cout << "Enter upper limit of integration:\n";
	std::cin >> b;

	std::cout << "Enter integration step:\n";
	std::cin >> step;

	std::cout << '\n';

	double rect = rightRectangle(a, b, step);
	double trap = trapezium(a, b, step);

	double divRect = rightRectangle(a, b, step / 2);
	double divTrap = trapezium(a, b, step / 2);

	double rectError = (rect - divRect) / 2; //Runge's error estimation rule
	double trapError = (trap - divTrap) / 2;

	std::cout << "Value by right rectangles method is " << rect << '\n';
	std::cout << "Error: " << rectError << "\n\n";

	std::cout << "Value by trapezium method is " << trap << '\n';
	std::cout << "Error: " << trapError << "\n\n";
}
