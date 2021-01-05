#include <iostream>
#include <iomanip>

using namespace std;

double a = 0, b = 0, c = 0, d = 0;

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

void root_of_cubic_equation() // asuming that equation has only 1 root
{
	// выключает синхронизацию между сишным вводом, ускоряет ввод/вывод
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> a >> b >> c >> d;
	double l = -1e10, r = 1e10;

	while (r - l > 1e-6)
	{
		// binary search
		double m = (l + r) / 2;
		if (f(l) * f(m) > 0)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}

	/* 
	this is how normal people do

	for (int i = 0; i < 100; ++i)
	{
		double m = (l + r) / 2;
		if (f(l) * f(m) > 0)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	*/
	cout << setprecision(10) << fixed << l;
}