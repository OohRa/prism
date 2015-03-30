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

double absol( double num ){
	(num < 0 ) ? num *= -1: ;
	
	return num;
}

// Only allows integer exponents
double power( double num, int exp ){
	//Positive exponents
	for( int i = 0; i < exp; ++i ){
		num *= num;
	}
}
