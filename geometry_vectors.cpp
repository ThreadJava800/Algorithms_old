#include <bits/stdc++.h>

using namespace std;

static const int INF = INT32_MAX;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}

	friend Point operator- (const Point& a, const Point& b);
	friend bool operator== (const Point& a, const Point& b);
	friend istream& operator>> (istream& in, Point& a);
	friend ostream& operator<< (ostream& out, const Point& a);
};

// overload operators

Point operator- (const Point& a, const Point& b)
{
	return Point(a.x - b.x, a.y - b.y);
}

bool operator== (const Point& a, const Point& b)
{
	return a.x == b.x && a.y == b.y;
}

istream& operator>> (istream& in, Point& a)
{
	in >> a.x >> a.y;
	return in;
}

ostream& operator<< (ostream& out, const Point& a)
{
	out << a.x << ' ' << a.y << '\n';
	return out;
}



// basic vector calculations

int scalarMultiply(const Point& a, const Point& b)
{
	return a.x * b.x + a.y * b.y;
}

int vectorMultiply(const Point& a, const Point& b)
{
	return a.x * b.y - a.y * b.x;
}

double vectorLength(const Point& a)
{
	// hypot returns sqrt(x^2 + y^2)
	return hypot(a.x, a.y);
}

double angle(const Point& a, const Point& b)
{
	return atan2(vectorMultiply(a, b), scalarMultiply(a, b));
}

bool pointOnSegment(const Point& a, const Point& b, const Point& c)
{
	// a and b are line points. c is point to be checked
	if (c == a || c == b) return true;
	// vectors are collinear and have opposite directions
	return vectorMultiply(a - c, b - c) == 0 &&
		scalarMultiply(a - c, b - c) < 0;
}




// Some geometry tasks using vectors

double triangleArea(const Point& a, const Point& b, const Point& c)
{
	return abs(vectorMultiply(a - c, b - c)) / 2.0;
}

double pointToBeamDistance(const Point& a, const Point& b, const Point& c)
{
	// a is a starting point. b is just a random point on beam to show its direction
	// c is point to be checked
	if (scalarMultiply(c - a, b - a) >= 0) 	// if height falls on beam
		return abs(vectorMultiply(c - a, b - a)) / vectorLength(a - b); // height
	else return vectorLength(c - a);
}

double pointToLineSegmentDistance(const Point& a, const Point& b, const Point& c)
{
	// a is a first segment border point and b is second
	// c is point to be checked

	// if height falls on beam from a to b and on beam from b to a
	if (scalarMultiply(c - a, b - a) >= 0 && scalarMultiply(c - b, a - b) >= 0)
		return abs(vectorMultiply(c - a, b - a)) / vectorLength(b - a); // height

	// if height falls only on beam from a to b
	else if (scalarMultiply(c - b, a - b) < 0) return vectorLength(c - b);

	// if height falls only on beam from b to a
	else return vectorLength(c - a);
}

double polygonArea(vector<Point> points)
{
	double area = 0;
	for (int i = 0; i < points.size() - 1; i++)
		area += vectorMultiply(points[i], points[i + 1]);
	area += vectorMultiply(points.back(), points.front());
	return abs(area / 2.0);
}


bool isPolygonConvex(vector<Point> points)
{
	if (points.size() == 0 || points.size() == 1 || points.size() == 2) return false;
	if (points.size() == 3) return true;

	// sin(a, b) < 0 or > 0 flags
	int positivePointsAngle = 0, negativePointsAngle = 0;
	// case (points[n-1], points[0], points[1])
	if (vectorMultiply(points.front() - points.back(), points[1] - points.front()) > 0)
		positivePointsAngle++;
	else if (vectorMultiply(points.front() - points.back(), points[1] - points.front()) < 0)
		negativePointsAngle++;
	// case (points[n-2], points[n-1], points[0])
	if (vectorMultiply(points.back() - points[points.size() - 2], points.front() - points.back()) > 0)
		positivePointsAngle++;
	else if (vectorMultiply(points.back() - points[points.size() - 2], points.front() - points.back()) < 0)
		negativePointsAngle++;
	// all other cases
	for (int i = 2; i < points.size(); i++)
	{
		if (vectorMultiply(points[i - 1] - points[i - 2], points[i] - points[i - 1]) > 0)
			positivePointsAngle++;
		else if (vectorMultiply(points[i - 1] - points[i - 2], points[i] - points[i - 1]) < 0)
			negativePointsAngle++;
	}
	return positivePointsAngle == 0 || negativePointsAngle == 0;
}
