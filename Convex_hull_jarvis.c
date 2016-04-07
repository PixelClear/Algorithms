#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x,y;
};

int Orientation(Point p, Point q, Point r)
{
	/*Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
	Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

	If  σ < τ, the orientation is counterclockwise (left turn)
	If  σ = τ, the orientation is collinear
	If  σ > τ, the orientation is clockwise (right turn)

	Using above values of σ and τ, we can conclude that, 
	the orientation depends on sign of  below expression: 

	(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)*/

	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if(val == 0) return 0; // Collinear lines 

	return (val > 0) ? 1 : 2;
}

void ConvexHull(Point points[], int n)
{
	vector<Point> hull;
	int leftmost_index = 0;

	if(n < 3) 
		return;

	for(int i =0 ;i<n ;i++)
	{
		if(points[i].x < points[i].x)
			leftmost_index = i;
	}

	int temp_leftmost = leftmost_index;
	int next_point;

	do
	{
		/*Add point to convex hull*/
		hull.push_back(points[temp_leftmost]);
		next_point = (temp_leftmost + 1)%n;

		for(int i = 0;i < n ;i++)
		{
			/* Start with line segment points[temp_leftmost] and points[next_point]
			   and see if any point lies on left side of it. If there exists we 
			   modify next point*/
			if(Orientation(points[temp_leftmost],points[i],points[next_point]) == 2)
				next_point = i;
		}

		temp_leftmost = next_point;
	}
	while(temp_leftmost != leftmost_index);


	for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";

}


int main()
{
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    ConvexHull(points, n);
    return 0;
}
