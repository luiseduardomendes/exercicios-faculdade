#include <iostream>
#include <vector>
#include <cmath>
#define NUMPOINTS 100
#define HEIGHT 40
#define WIDTH 75

typedef struct {
	double x, y;
	bool isConvexWrap;
} Coord;

double triangleArea(Coord a, Coord b, Coord c);

using namespace std;

int main(){
	vector<Coord> *pointsHeap = new vector<Coord>;
	vector<Coord> &points = *pointsHeap;
	bool printed;

	srand(time(NULL));

	cout << "size: " << points.size() << endl;

	for (int i = 0; i < NUMPOINTS; i ++){
		points.push_back(Coord());
		points[i].x = round(((double)rand()/RAND_MAX) * (WIDTH-1));
		points[i].y = round(((double)rand()/RAND_MAX) * (HEIGHT-1));
		points[i].isConvexWrap = true;
	}

	for (int i = 0; i < points.size(); i ++){
		cout << round(points[i].x) << ", " << round(points[i].y) << endl;
	}

	bool convexWrapTest;
	double mainTriangleArea;
	double subTriangleArea1;
	double subTriangleArea2;
	double subTriangleArea3;


	for (int i = 0; i < points.size(); i ++){
		for (int j = 0; j < points.size(); j ++){
			for (int k = 0; k < points.size(); k ++){
				if (i != j && j != k && i != k){
					mainTriangleArea = triangleArea(points[i], points[j], points[k]);
					for (int p = 0; p < points.size(); p ++){
						if (p != i && p != j && p != k && points[p].isConvexWrap && mainTriangleArea != 0){
							subTriangleArea1 = triangleArea(points[i], points[j], points[p]);
							subTriangleArea2 = triangleArea(points[i], points[p], points[k]);
							subTriangleArea3 = triangleArea(points[p], points[j], points[k]);
							if (mainTriangleArea == subTriangleArea1 + subTriangleArea2 + subTriangleArea3)
								points[p].isConvexWrap = false;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < HEIGHT; i ++){
		for (int j = 0; j < WIDTH; j++){
			printed = false;
			for (int k = 0; k < points.size(); k++){
				if (round(points[k].x) == j && round(points[k].y) == i){
					if (points[k].isConvexWrap)
						cout << " x";
					else
						cout << " o";
					printed = true;
					break;
				}
			}
			if (!printed)
				cout << " .";
		}
		cout << endl;
	}
	return 0;
}

double triangleArea(Coord a, Coord b, Coord c){
	double det;
	det = (a.x * b.y) + (a.y * c.x) + (b.x * c.y) - ((c.x * b.y) + (c.y * a.x) + (b.x * a.y));
	return abs(det) / 2;
}
