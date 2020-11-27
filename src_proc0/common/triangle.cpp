#include <cmath>
#include "service.h"

nm32f max_fabs_in_array(const nm32f *array, int cnt)
{
	nm32f max = 0.0;
	for (int i = 0; i < cnt; ++i){
		if (fabs(array[i]) > max){
			max = fabs(array[i]);
		} else {
			// Do nothing 
		}
	}
	return max;
}

nm32f min_fabs_in_array(const nm32f *array, int cnt)
{
	nm32f min = array[0];
	for (int i = 1; i < cnt; ++i){
		if (fabs(array[i]) < min){
			min = fabs(array[i]);
		} else {
			// Do nothing 
		}
	}
	return min;
}

nm32f Triangle::edgeSize(int i) const
{
	Point p1 = points[edges[i].p1];
	Point p2 = points[edges[i].p2];

	nm32f dx = fabs(p1.x - p2.x);
	nm32f dy = fabs(p1.y - p2.y);

	nm32f size = pow(dx, 2) + pow(dy, 2);
	return size;
}

edgeProjection Triangle::edgeGetProjection(int i) const
{
	Point p1 = points[edges[i].p1];
	Point p2 = points[edges[i].p2];
	struct edgeProjection res;

	res.dx = fabs(p1.x - p2.x);
	res.dy = fabs(p1.y - p2.y);

	return res;
}

bool Triangle::isTooBig(nm32f xMax, nm32f yMax) const
{
	// If the projection of at least one edge is more than allowed value
	// then split the triangle
	edgeProjection edge0Projection = this->edgeGetProjection(0);
	edgeProjection edge1Projection = this->edgeGetProjection(1);
	edgeProjection edge2Projection = this->edgeGetProjection(2);
	if (edge0Projection.dx > xMax || edge0Projection.dy > yMax ||
		edge1Projection.dx > xMax || edge1Projection.dy > yMax ||
		edge2Projection.dx > xMax || edge2Projection.dy > yMax ) {
			return true;
	} else {
			return false;
	}
}

nm32f Triangle::GetWidth(void) const
{
	nm32f widths[3] = {points[0].x - points[1].x, 
						points[1].x - points[2].x, 
						points[2].x - points[0].x};
	return max_fabs_in_array(widths, 3);
}

nm32f Triangle::GetHeight(void) const
{
	nm32f heights[3] = {points[0].y - points[1].y, 
						 points[1].y - points[2].y, 
						 points[2].y - points[0].y};
	return max_fabs_in_array(heights, 3);
}
