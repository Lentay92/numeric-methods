#include <iostream>

double func(double const& x, double const& y)
{
	return (-2) * x * (y + 1);
}

void EulerMethod(size_t const& n, double x, double y, double const& step)
{
	std::cout << "Euler Method:\n\n";

	for (size_t i = 0; i <= n; ++i)
	{
		std::cout << 'x' << i << ": " << x << "    \t" << 'y' << i << ": " << y << '\n';

		y += step * func(x, y);
		x += step;
	}

	std::cout << '\n';
}

void CauchyMethod(size_t const& n, double x, double y, double const& step)
{
	std::cout << "Cauchy Method:\n\n";

	for (size_t i = 0; i <= n; ++i)
	{
		std::cout << 'x' << i << ": " << x << "    \t" << 'y' << i << ": " << y << '\n';

		y += step * func(x + step/2, y + (step/2) * func(x, y));
		x += step;
	}

	std::cout << '\n';
}

void RungeKutta4th(double& x, double Y[], double const& step)
{
    double k1, k2, k3, k4;
    
    for (size_t i = 1; i < 3; ++i)
    {
		k1 = step * func(x, Y[i - 1]);
		k2 = step * func(x + step / 2, Y[i - 1] + k1 / 2);
		k3 = step * func(x + step / 2, Y[i - 1] + k2 / 2);
		k4 = step * func(x + step, Y[i - 1] + k3);

		Y[i] = Y[i - 1] + 1./ 6 * (k1 + 2 * k2 + 2 * k3 + k4);

		x += step;

        std::cout << 'x' << i << ": " << x << "    \t" << 'y' << i << ": " << Y[i] << '\n';
    }
}

void AdamsBashforthMethod(size_t const& n, double x, double const& y, double const& step)
{

	std::cout << "Adams-Bashforth Method:\n\n";

    std::cout << "x0: " << x << "    \t" << "y0: " << y << '\n';

	double* Y = new double[n + 1];
	Y[0] = y;

    RungeKutta4th(x, Y, step);
    
	for (size_t i = 3; i <= n; ++i)
    {
        Y[i] = Y[i - 1] + (step / 12) * (23 * func(x, Y[i - 1]) - 16 * func(x - step, Y[i - 2]) + 5 * func(x - 2 * step, Y[i - 3]));\

        x += step;

		std::cout << 'x' << i << ": " << x << "    \t" << 'y' << i << ": " << Y[i] << '\n';
    }

    std::cout << '\n';
}

int main()
{
	EulerMethod(10, 0, 1, 0.1);
	CauchyMethod(10, 0, 1, 0.1);
	AdamsBashforthMethod(10, 0, 1, 0.1);
}

