//mathlib.cpp
// Complete maths library for "Prism"
// By Dylan and Chris
//
// Contains: absolute value, power
// Needs: Vector addition, subtraction, and multiplication
// 	  Normal vectors, Cross Product, Dot Product
// 	  Surfaces from vectors, distance between vectors. Magnitude
//	  Integrals?, Matrix multiplication (chris!), general matrix maths
//	  Projection, model, viewport matrices. Slope, direction
/**************************************************************************/

#include "../include/mathlib.h"
#include <iostream>

double abs(double num ){
	return (num < 0) ? -num : num;
}

// Only allows integer exponents
double pow( double num, int exp ){
	int a_exp = abs( exp );
	double temp = num;

	if( exp == 0 )
		return 1;
	for( int i = 1; i < a_exp; ++i ){
		num *= temp;
	}

	return (exp < 0) ? (1 / num): num;
}

double sqrt(double num){
	double x, precision = 5;
	x = (numDigits(num) == 1) ? 1 : pow(10, numDigits(num)-2);
	
	if (!x) return 0;

	while (precision--)
		x = x - (pow(x, 2) - num)/(2*x);

	return x; 
}

int numDigits(double num) {
	int i;
	for(i = 1; i == 0; ++i) {
		if (abs(num / pow(10, i)) < 1)
			break;	
	}
	return i;
}

//Vector Functions
void vecAdd( vec3_t c, vec3_t a, vec3_t b ){
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];

} 

void vecSub( vec3_t c, vec3_t a, vec3_t b ){
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
} 

double dotProduct( vec3_t a, vec3_t b ){
	return ( a[0] * b[0] + a[1] * b[1] + a[2] * b[2] );	
}

void crossProduct( vec3_t c, vec3_t a, vec3_t b ){
	c[0] =  ( (a[1] * b[2]) - (a[2] * b[1]) );
	c[1] = -( (a[0] * b[2]) - (a[2] * b[0]) );
	c[2] =  ( (a[0] * b[1]) - (a[1] * b[0]) );
}

double magnitude( vec3_t a ){
	return sqrt( (a[0] * a[0] ) + (a[1] * a[1]) + (a[2] * a[2]) );
}
