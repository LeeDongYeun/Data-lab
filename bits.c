/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	int n_x, n_y, result;
	
	n_x = ~x;
	n_y = ~y;
	
	result = n_x|n_y;
	
	
  	return ~result;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
	int x_1;
	
	x_1 = ~x+1; // -x
  	return x&x_1;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
	int k, new_x, new_c, j;

	j=n+n;
	j=j+j;
	j=j+j;  // n 바이트만큼 옮기기위한 상수 
	
	k= 0xff; // 00000000 00000000 00000000 11111111b
	k= k<<j; 
	k= ~k;   // 11111111 11111111 00000000 11111111b (n이 1이라면) 
	new_x = x&k;// 
	
	new_c = c<<j;
	new_x = new_x + new_c;
	
	return new_x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	int nega_x, x_1;
	int result;
	
	nega_x = ~x+1;// -x
  	nega_x = nega_x >>31;
  	x_1 = x >> 31;  //  if x>=0 x_1=0, else x=1
  	
  	result = nega_x | x_1;
  	result = ~result +1;
	
  	return result^1;
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
	/*
	 this result is 32 - (log(~x))
	 so using hamming weight, I made log(k).
	*/
	int nx_1=~x; //
	int a=0x55,b=0x33,c=0x0f,d=0xff,e=0xff;
	
	a = a | (a<<8);
	a = a | (a<<16);
	
	b = b | (b<<8);
	b = b | (b<<16);
	
	c = c | (c<<8);
	c = c | (c<<16);
	
	d = d | (d<<16);
	
	e = e | (e<<8);
	
	//printf("%x\n", nx_1);	
	nx_1 = nx_1 | (nx_1>>1); //printf("%x\n", nx_1);
	nx_1 = nx_1 | (nx_1>>2); //printf("%x\n", nx_1);
	nx_1 = nx_1 | (nx_1>>4); //printf("%x\n", nx_1);
	nx_1 = nx_1 | (nx_1>>8); //printf("%x\n", nx_1);
	nx_1 = nx_1 | (nx_1>>16); //printf("%x\n", nx_1);
	
	
	nx_1 = (nx_1 & a) + ((nx_1 >> 1) & a) ;//printf("%x\n", nx_1);
	nx_1 = (nx_1 & b) + ((nx_1 >> 2) & b) ;//printf("%x\n", nx_1);
	nx_1 = (nx_1 & c) + ((nx_1 >> 4) & c) ;//printf("%d\n", nx_1);
	nx_1 = (nx_1 & d) + ((nx_1 >> 8) & d) ;//printf("%d\n", nx_1);
	nx_1 = (nx_1 & e) + ((nx_1 >> 16) & e) ;//printf("%d\n", nx_1);
	
	

  	return  32 + ~(nx_1) +1;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	int k=1;
	k = k<<31;
  return ~k;
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
	int result;
	result = x^1;
    return result|y;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int n_x= !x; //x가 0이면 1, 아니면 0   
	int result;
	
	n_x =  ~0 + n_x; // n_x 가 0 일때 111111111, n_x 가 1 일때 0000000000 
	n_x = ~n_x;
	
	result = (~n_x&y)|(n_x&z); 
	
  return result;
}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y){
	int x_test,y_test,t_test;
	int total = x+y;
	int result;
	
	x_test = (x>>31)&1;
	y_test = (y>>31)&1;
	t_test = (total>>31)&1;
	
	result = !((!(x_test^y_test))&(x_test^t_test));
	
	
	return result;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y){
	int x_test, _y_test, t_test, r_test;
	int total = x+~y;
	int addOKresult;
	int result;
	
	x_test = (x>>31)&1;
	_y_test = (~y>>31)&1;
	t_test = (total>>31)&1;
	
	addOKresult = !((!(x_test^_y_test))&(x_test^t_test));
	
	
	result = total;
	r_test = !((result>>31)&1);
	
	return (addOKresult&r_test)|(!addOKresult&!r_test);
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x){
	int xx=x+x,xxx=xx+x,x_t,x_tt,xx_t, xxx_t;
	int TMin = 1<<31, TMax = ~TMin;
	int xxaddOK,xxxaddOK;
	int k,s,result;
	
	x_tt=(x>>31);
	x_t=x_tt&1;
	xx_t = (xx>>31)&1;
	xxx_t =(xxx>>31)&1;
	
	xxaddOK= !(x_t^xx_t);
	xxxaddOK= xxaddOK&(!(x_t^xxx_t));
	s=~xxxaddOK+1;
	
	k=(~x_tt&TMax)|(x_tt&TMin);
	result = (s&xxx)|(~s&k);
	
	return result;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	unsigned l=255<<23;
	unsigned m=~(1<<31);
	unsigned result = uf & m;
	
	if(result>l)
		return uf;
	else 
		return result;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	unsigned s= uf>>31; // 0 or 1
	unsigned exp = (uf>>23)&0xff;
	unsigned frac = uf&(~((~0)<<23)); // 
	int e = exp - 127; //-126<=e<=127 11111111~01111111
	
	//printf("%d\n", e);
	if(e>=31){
		//printf("a");
		return 0x80000000u;
	}
	else{
	
		if(s){
			
			if(e>22 && e<31){
				//printf("b");
				return -((frac<<(e-23))+1);
			}
			else if(e>=0 && e<=22){
				//printf("c");
				return -((frac>>(23-e))+1);
			}
			else{
				//printf("d");
				return 0;
			}
		}
		else{
			
			if(e>22 && e<31){
				//printf("f");
				return (frac<<(e-23))+1;
			}
			else if(e>=0 && e<=22){
				//printf("g");
				return (frac>>(23-e))+1;
			}
			else{
				//printf("h");
				return 0;
			}
		}
	}
}
