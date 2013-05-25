

#include <cstdio>
#include <float.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

double tempmin=FLT_MAX;
int minx1,minx2,miny1,miny2;
struct Point
{
	int x, y;
};


int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a,  *p2 = (Point *)b;
	return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a,   *p2 = (Point *)b;
	return (p1->y - p2->y);
}


double dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
			(p1.y - p2.y)*(p1.y - p2.y)
		   );
}


double bruteForce(Point P[], int n)
{
	double mini = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < mini)
			{
				mini = dist(P[i], P[j]);
				if(mini<tempmin)
				{
					tempmin=mini;
					minx1=P[i].x,miny1=P[i].y,minx2=P[j].x,miny2=P[j].y;
				}
			}
	return mini;
}


double stripClosest(Point strip[], int size, double d)
{
	double min = d;  // Initialize the minimum distance as d

	qsort(strip, size, sizeof(Point), compareY);

	for (int i = 0; i < size; ++i)
	{  
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
		{  
			if (dist(strip[i],strip[j]) < min)
			{
				min = dist(strip[i], strip[j]);
				if(min<tempmin)
				{
					tempmin=min;
					minx1=strip[i].x , miny1=strip[i].y, minx2=strip[j].x,miny2=strip[j].y;
				}
			} 
		}
	}

	return min;
}


double closestUtil(Point P[], int n)
{

	if (n <= 3)
		return bruteForce(P, n);


	int mid = n/2;
	Point midPoint = P[mid];

	double dl = closestUtil(P, mid);
	double dr = closestUtil(P + mid, n-mid);

	// Find the smaller of two distances
	double d = min(dl, dr);
	if(tempmin>d)
		tempmin=d;

	
	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;


	return min(d, stripClosest(strip, j, d) );
}

double closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);

	// Use recursive function closestUtil() to find the smallest distance
	return closestUtil(P, n);
}
int main()
{
	
	int n;
	Point P[56384]; 
	Point P2[56384];
	double minidist; 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&P[i].x,&P[i].y);
		P2[i].x=P[i].x;
		P2[i].y=P[i].y;
	}
	minidist = closest(P, n);
	for(int i=0;i<n;i++)
	{
		if( (P2[i].x==minx1 && P2[i].y==miny1) || (P2[i].x==minx2 && P2[i].y==miny2))
			printf("%d ", i);
	}
	printf("%.6lf\n",minidist );
	
	return 0;
}
