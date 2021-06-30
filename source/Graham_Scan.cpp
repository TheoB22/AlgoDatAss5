#include <vector>
#include <iostream>
#include <math.h>
#include <limits>
#include <cmath>	
#include "matplotlibcpp.h"

//struct for creeating a point
struct point
{
	int name_ = 0;
	float x_ = 0.0f;
	float y_ = 0.0f;
};

namespace plt = matplotlibcpp;
void plot_convex_hull(std::vector<point> const& points) {
	/*std::vector<float> x = { 1, 2, 3, 4, 2 };
	std::vector<float> y = { 1, 4, 9, 16, 20 };

	plt::plot(x, y);
	plt::show();*/

	std::vector<float> x, y;
	for (auto p : points) {
		x.push_back(p.x_);
		y.push_back(p.y_);
	}
	plt::scatter(x, y, 2);
	plt::show();
}



int main() {
	srand((unsigned)time(NULL));
	
	//input for number of points
	int number_points = 0;
	while (true) {
		std::cout << "Enter integer number of points: ";
		std::cin >> int(number_points);
		if (number_points >= 2) {
			break;
		}
		else {
			std::cout << "Invalid number of points! (Enter a number greater than 1)" << std::endl;
		}
	}

	//input for x Axis size
	float x_Axis = 0.0f;
	while (true) {
		std::cout << "Enter floating point number of the size of your x-Axis: ";
		std::cin >> float(x_Axis);
		if (x_Axis > 0) {
			break;
		}
		else {
			std::cout << "Invalid x Axis size! (Enter positive floating point number)" << std::endl;
		}
	}

	//input for y Axis size
	float y_Axis = 0.0f;
	while (true) {
		std::cout << "Enter floating point number of the size of your y-Axis: ";
		std::cin >> float(y_Axis);
		if (y_Axis > 0) {
			break;
		}
		else {
			std::cout << "Invalid y Axis size! (Enter positive floating point number)" << std::endl;
		}
	}

	//calculating vector X based on input
	std::vector<point> X{};
	for (int i = 0; i < number_points; i++) {
		float x = floor(static_cast <float> (rand()) / static_cast <float> (RAND_MAX / x_Axis) * 100) / 100;
		float y = floor(static_cast <float> (rand()) / static_cast <float> (RAND_MAX / y_Axis) * 100) / 100;
		X.push_back(point{ i, x,y });
	}

	plot_convex_hull(X);
}