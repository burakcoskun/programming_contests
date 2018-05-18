#include <iostream>
#include <cmath>

using namespace std;

# define PI           3.14159265358979323846  /* pi */

double angle(double &a, double &b, double &c) 
{
	// apply cosine theorem: c^2 + b^2 + 2*b*c*cos(A) = a^2 
	return acos((-a*a + b*b + c*c)/(2*b*c));
}

// apply euclidean gcd
double gcd(double a, double b)
{
	double small = a, large = b;
	if(a > b){
		small = b; large = a;
	}

	double rem = large;

	while(rem > 0.0031415926){
		rem = large - small * floor(large/small);
		large = small;
		small = rem;
	}

	return large;
}

double gcd(double &a, double &b, double &c)
{
	return gcd(gcd(a, b), c);
}

double area(double &a, double &b, double &c)
{
	double u = (a+b+c)/2.0;
	return sqrt(u * (u-a) * (u-b) * (u-c));	
}

int main()
{
	// points are a, b, c
	double ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	// find first angle by cosine theorem
	double a = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
	double b = sqrt((ax-cx)*(ax-cx) + (ay-cy)*(ay-cy));
	double c = sqrt((bx-cx)*(bx-cx) + (by-cy)*(by-cy));

	double angleA = angle(a, b, c);
	double angleB = angle(b, a, c);
	double angleC = PI - angleA - angleB;

	// find gcd of these angles (also calculate center angle)
	double angleG = gcd(angleA, angleB, angleC);

	int N = (int) round(PI / angleG);

	double R = a*b*c/(4*area(a,b,c));
	double result = 0.5 * N * R * R * sin(2 * angleG);

	cout.precision(17);
	cout << result << endl;

	return 0;
}
