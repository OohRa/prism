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
	int a_exp = absol( exp );
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
	
	//Find power of ten
	for( int i = 1; i != 0; ++i ){
		if( num / power(10,i) < 1 )
			break;
		else  
			temp = power( i + 1, 2 );	
	}

	//Search for roots
	int flag = 0;
	while( i != 0 ){
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
