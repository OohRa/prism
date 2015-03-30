//mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

typedef double vec_t;
typedef vec_t vec3_t[3];

double absol( double num );
double power( double num, int exp );
double sqrt( double num );

//Vector Functions
void vecAdd( vec3_t c, vec3_t a, vec3_t b );
void vecSub( vec3_t c, vec3_t a, vec3_t b );
double dotProduct( vec3_t a, vec3_t b );
void crossProduct( vec3_t c, vec3_t a, vec3_t b );
double magnitude( vec3_t a );

#endif 
