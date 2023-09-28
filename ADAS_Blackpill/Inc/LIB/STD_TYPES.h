/**********************************************************************************/
/***						Date: 20/9/2023	Day: Wednesday						***/
/***    GPIO driver for STM32F401 a graduation project for thE NTI 	program	    ***/
/**********************************************************************************/

#ifndef STD_types_h
#define STD_types_h

// Decimal type unsigned value with 8 bits size
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;
typedef double f64;

// Function standard return
typedef unsigned char STD_ReturnType;

// Standard TRUE and FALSE
#define STD_TRUE										0b1u
#define STD_FALSE										0b0u

#endif
