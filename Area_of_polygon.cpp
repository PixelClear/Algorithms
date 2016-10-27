#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

typedef struct point
{
	int x;
	int y;
}Point;

double CrossProduct(Point& p1,Point& p2)
{
	return ((p1.x * p2.y) - (p2.x * p1.y));
}

double FindArea(vector<Point>& points)
{
	double area = 0.0;
	int num_vertice = points.size();

	for(int i =0; i<num_vertice;i++)
	{
		int j=(i+1) % num_vertice;
		area+=CrossProduct(points[i],points[j]); 
	}
	area = fabs(area) * 0.5;
	return area;
}

int Orientation(Point p, Point q, Point r)
{
	/*Slope of line segment (p1, p2): s = (y2 - y1)/(x2 - x1)
	Slope of line segment (p2, p3): t = (y3 - y2)/(x3 - x2)
	If  s < t, the orientation is counterclockwise (left turn)
	If  s = t, the orientation is collinear
	If  s > t, the orientation is clockwise (right turn)
	Using above values of s and t, we can conclude that, 
	the orientation depends on sign of  below expression: 
	(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)*/

	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if(val == 0) return 0; // Collinear lines 

	return (val > 0) ? 1 : 2;
}

double ConvexHull(vector<Point>& points, int n)
{
	vector<Point> hull;
	int leftmost_index = 0;

	if(n < 3) 
		return 0.0;

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

	double area = FindArea(hull);
	area*=2;
	return area;
}

int main ()
{
	string total_cases;
	string input;
	string n;
	long int cases;
	long int total_number;
	long int temp_num;
	vector<int> num_array;
	vector<Point> points;
	vector<double> area;

	getline(cin, total_cases);
	istringstream iss_temp1(total_cases);
	iss_temp1 >> cases;

	for(int k = 0;k < cases; ++k)
	{
		getline(cin, n);
		getline(cin, input);
		istringstream iss_temp2(n);
		istringstream iss_temp3(input);

		iss_temp2 >> n;

		while(iss_temp3 >> temp_num)
		{
			num_array.push_back(temp_num);
		}

		for(int i =0; i<num_array.size(); ++i)
		{
			for(int j=0; j<num_array.size();++j)
			{
				if(i<j)
				{
					Point temp;
					temp.x = num_array[i];
					temp.y = num_array[j];

					points.push_back(temp);

				}
			}
		}

		area.push_back(ConvexHull(points,points.size()));
		num_array.clear();
		points.clear();
	}

	for(int i = 0;i<area.size();++i)
		cout<<area[i]<<endl;

}

