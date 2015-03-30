//mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

typedef double vec_t;
typedef vec_t[3] vec3_t;

#define PI 3.1415926535897932

double abs( double num );
double pow( double num, int exp );
double sqrt( double num );
int numDigits(double num);

//Vector Functions
void vecAdd( vec3_t c, const vec3_t a, const vec3_t b );
void vecSub( vec3_t c, const vec3_t a, const vec3_t b );
double dotProduct( const vec3_t a, const vec3_t b );
void crossProduct( vec3_t c, const vec3_t a, const vec3_t b );
double magnitude( const vec3_t a );

#endif 
