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

double absol(double num ){
	return (num < 0) ? -num : num;
}

// Only allows integer exponents
double power( double num, int exp ){
	int a_exp = abs( exp );
	int temp = num;

	if( exp == 0 )
		return 1;
	
	else
		for( int i = 0; i < a_exp; ++i ){
			num *= temp;
		}

	return (exp < 0) ? (1 / num): num;
}

double sqrt( double num ){
	int temp = 0;
	
	temp = power(numDigits(num), numDigits(num));

	//Search for roots
	int flag = 0;
	while(1) {
		if( (temp * temp) > num ){
			--temp;
			++flag;
		}
		else if( (temp * temp) < num ){
			++temp;
			--flag;
		}

		if( flag == 0 )
			break;
	}	

	return temp;
}

int numDigits(double num) {
	int i;
	for(i = 1; i = 0; ++i) {
		if (abs(num / power(10,i)) < 1)
			break;	
	}
	return i;
}

//Vector Functions
void vecAdd( vec3_t c, const vec3_t a, const vec3_t b ){
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];

} 

void vecSub( vec3_t c, const vec3_t a, const vec3_t b ){
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
} 

double dotProduct( const vec3_t a, const vec3_t b ){
	return ( a[0] * b[0] + a[1] * b[1] + a[2] * b[2] );	
}

void crossProduct( vec3_t c, const vec3_t a, const vec3_t b ){
	c[0] =  ( (a[1] * b[2]) - (a[2] * b[1]) );
	c[1] = -( (a[0] * b[2]) - (a[2] * b[0]) );
	c[2] =  ( (a[0] * b[1]) - (a[1] * b[0]) );
}

double magnitude( const vec3_t a ){
	return sqrt( (a[0] * a[0] ) + (a[1] * a[1]) + (a[2] * a[2]) );
}
