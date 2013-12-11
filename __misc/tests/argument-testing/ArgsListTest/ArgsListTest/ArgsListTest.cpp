// ArgsListTest.cpp
// @author Mathew Kurian
// calcASM @StackExchange

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

#define ITERATIONS_ 1000000
#define ITERATIONS 1000000000

// Look at the difference in psuedo-assembly code
// My knowledge in compiler is little, but I can see that
// that there are unncessary cycles being wasted for this part.

// **** With array (this example) *****
// LOAD         Reg, memAddressOfArray
// WRITETOMEM   Reg, ptrToVar1
// INCREMENT    sp
// WRITETOMEM   Reg, ptrToVar2
// DECREMENT    sp
// PUSH         ptrToArray
// JUMP         test

//  ***** IDEALLY SUPPOSED TO LIKE THIS *****
// PUSH        ptrToVar2
// PUSH        ptrToVar1
// JUMP        test


int r = 0;

class Base
{
public:
	virtual int test(void* arguments[])
	{
		int x = 5;      
		x += r;

		return x;
	}
};

class Derived : public Base
{
public:
	virtual int test(void* arguments[])
	{
		int x = 5;      
		x += r;

		return x;
	}
};

class Base2
{
public:
	virtual int test(void* arg1 = NULL, void* arg2 = NULL, void* arg3 = NULL, void* arg4 = NULL,
		void* arg5 = NULL, void* arg6 = NULL, void* arg7 = NULL, void* arg8 = NULL,
		void* arg9 = NULL, void* arg10 = NULL, void* arg11 = NULL, void* arg12 = NULL)
	{
		int x = 5;      
		x += r;

		return x;
	}

	virtual int test2(int * o)
	{
		int x = 5;      
		x += r;

		return x;
	}
};

void calcuC(int *x, int *y, int length)
{
	for (int i = 0; i < ITERATIONS_; i++)
	{
		for (int j = 0; j < length; j++)
			x[j] += y[j];
	}
}

void calcuAsm(int *x, int *y, int lengthOfArray)
{
	__asm
	{
			mov ebx, ITERATIONS_
		start :
			mov ecx, lengthOfArray
			mov esi, x
			shr ecx, 1
			mov edi, y
		label :
			movq xmm0, QWORD PTR[esi]
			paddd xmm0, QWORD PTR[edi]
			add edi, 8
			movq QWORD PTR[esi], xmm0
			add esi, 8
			dec ecx
			jnz label
			dec ebx
			jnz start
	};
}

int _tmain(int argc, _TCHAR* argv[])
{
	Derived * base = new Derived;
	Base2 * base2 = new Base2;
	
	string * str1 = new string("sunny1");
	string * str2 = new string("sunny2");
	string * str3 = new string("sunny3");
	string * str4 = new string("sunny4");
	string * str5 = new string("sunny5");
	string * str6 = new string("sunny6");
	string * str7 = new string("sunny7");
	string * str8 = new string("sunny8");

	int * vale = new int(20);
	int iterations = ITERATIONS;
	int *xC, *xAsm, *yC, *yAsm;

	xC = new int[2000];
	xAsm = new int[2000];
	yC = new int[2000];
	yAsm = new int[2000];

	for (int i = 0; i < 2000; i++)
	{
		xC[i] = 0;
		xAsm[i] = 0;
		yC[i] = i;
		yAsm[i] = i;
	}

	clock_t tStart;
	
	//================================================================================

	printf("Using Pure-C++ [%d iterations]\n", ITERATIONS_);

	tStart = clock();

	calcuC(xC, yC, 2000);

	printf("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	//================================================================================

	printf("Using Raw Assembly [%d iterations]\n", ITERATIONS_);

	tStart = clock();

	calcuC(xC, yC, 2000);

	printf("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	//================================================================================
	
	printf("Using 1 NULL Parameter [%d iterations]\n", iterations);

	tStart = clock();

	for (int x = 0; x < iterations; x++)
	{
		r = base2->test2(vale);
	}

	printf("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	//================================================================================

	printf("Using Array [%d iterations]\n", iterations);

	tStart = clock();

	void * arguments[] = { str1, str2, str3, str4 };

	for (int x = 0; x < iterations; x++)
	{
		arguments[0] = str2;
		arguments[1] = str3;
		arguments[2] = str1;
		arguments[3] = str4;

		r = base->test(arguments);
	}

	printf("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	//================================================================================

	printf("Using Default-Parameters [%d iterations]\n", iterations);

	tStart = clock();

	for (int x = 0; x < iterations; x++)
	{
		r = base2->test(str1, str2, str3, str4);
	}

	printf("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	//================================================================================

	std::getchar();

	return 0;
}