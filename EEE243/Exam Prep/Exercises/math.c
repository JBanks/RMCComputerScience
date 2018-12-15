#include <stdlib.h>
#include <stdio.h>

#define DEBUG 1
#define PI 3.14159
#define HALF_CIRCLE 180

double fabsolute(double a){
	//absolute value of a float
	if (a < 0)
		return -a;
	else
		return a;
}

double deg_to_rad(double deg){
	//degrees in radians
  return deg * ( PI / HALF_CIRCLE );
}

double power(double x, double y) {

  double x_0 = x;
  for (int i = 1; i < y; i++){
      x *= x_0;
  }
  if (y == 0){
      x = 1;
  }
  return x;
}

float square_root(float x, float tolerance){
	//Newton's method for calculating square roots
	float current = x;
	float previous = 0;

	while (fabsolute(current - previous) > tolerance){
		previous = current;
		current = previous - (power(previous, 2) - x) / (2 * previous);
	}
	return current;
}

double factorial(int x) {
    double x_0 = 1;
    for (int i = x; i>0; i--){
        x_0 *= i;
    }
    return x_0;
}

double sinus(double x, int n) {
    double ret = 0;
    for (int i = 0; i<=n; i++){
        ret += (power(-1, i)*power(x, 2*i + 1))/factorial(2*i + 1);
    }
    return ret;
}

int main() {
	//playing with function pointers incase the topic comes up on the theory portion.
	double (*fp_double[2]) (double) = {fabsolute, deg_to_rad};
	printf("fabsolute(-3.4): %f\ndeg_to_rad(180): %f\n", fp_double[0](-3.4), fp_double[1](180));
	
	printf("Sqrt(5): %f\n", square_root(5, 0.000001));
	return EXIT_SUCCESS;
}
