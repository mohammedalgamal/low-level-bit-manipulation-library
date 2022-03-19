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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
        int first = (x & ~y);
        int second = (~x & y);
  return ~(~first & ~second);

}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	int num = 0xff;

  return num<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
	int num = x + 1;
	int num2 = ~x;
	int num3 = ~0x00;
  return !(num ^ num2) & !!(num2 & num3);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int num = (0x55 << 24) + (0x55 << 16) + (0x55 << 8) + 0x55;
	int num2 = num | x;
  return !(num2 ^ (~0x00));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	int num = ~x + 1;
  return num;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int num = !((x>>1) ^ 0x1c);
	int num2 = !((x>>3) ^ 0x06);
  return num | num2;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int num = !!x;
	int num2 = !num;
	int num3 = ~num + 1;
	int num4 = ~num2 + 1;
  return (y & num3) | (z & num4) ;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int num = !(x ^ y);
	int num2 = (x >> 31) & 1;
	int num3 = (y >> 31) & 1;
	int numx = (num2 ^ num3);
	int num4 = numx & num2;
	int num5 = (!((((~x + 1) + y) >> 31) & 1)) & !numx;
  return num | num4 | num5;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	int num = ~x + 1;
	int num2 = x >> 31;
	int num3 = num >> 31;
	int num4 = (num2 ^ num3) + 1;
	int num5 = ~(num2 & num3);	
  return num4 & num5;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int sign, bit16, bit8, bit4, bit2, bit1, bit0, result;
	sign = x >> 31;
	x = (sign & ~x) | (~sign & x);
	bit16 = !!(x >> 16) << 4;
  	x = x >> bit16;
  	bit8 = !!(x >> 8) << 3;
  	x = x >> bit8;
  	bit4 = !!(x >> 4) << 2;
  	x = x >> bit4;
  	bit2 = !!(x >> 2) << 1;
  	x = x >> bit2;
  	bit1 = !!(x >> 1);
  	x = x >> bit1;
  	bit0 = x;
  	result = bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
  return result;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	//unsigned exp = (uf << 1) >> 24;
	unsigned num = uf + 0x00800000;
	if(uf == 0x00 || uf == 0x80000000 || (uf > 0x7f800000 && uf <= 0x7fffffff) || (uf > 0xff800000)){
		return uf;
	}
	if((num >= 0x7f800000 && num < 0x80000000) ||  uf == 0x7f800000){
		return 0x7f800000;
	}
	if(num >= 0xff800000 || uf == 0xff800000){
                return 0xff800000;
	}
	if(uf <= 0x007fffff){
		return uf * 2; 
	}	
	if(uf <= 0x807fffff && uf > 0x80000000){
		unsigned num2 = uf & 0x007fffff;
		return uf + num2;
	}
	//if((num > 0x7f800000 && num <= 0x7fffffff) || num > 0xff800000){
	//	return num
	//}

  return num;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	/*int num = x;
	int num2 = x;
	int exp = 31;
	int s = 0;
	int ans = 0;
	int e = 0;
	int frac;
	int sfrac = 0;
	int ifrac = 0;
	int xfrac = 0;
	//int minus = 1 << 31;
	if(x == 0){
		return 0x00;
	}

	if(x == 0x80000000){
		return 0xcf000000;
	}

	if(x < 0){
		s = 1;
		num2 = -num2;
		num = -num;
	}

	while(!(num & (1 << 31))){
		num <<= 1;
		exp -= 1;
	}

	frac = num2 << (32 - exp);
	sfrac = frac << 22;
	ifrac = (sfrac << 1) ^ 0x80000000;
	xfrac = sfrac ^ 0xc0000000;

	if(ifrac > 0){
		frac = frac + 0x00000200;
	}

	if(xfrac == 0){
		frac = frac + 0x00000200;
	}
	frac = (((~minus) & num) >> 8);
        if(num & 0x80 && ((frac & 1) || ((num & 0x7f) > 0))){
        	frac++;
        }      

	e = (127 + exp + ((frac >> 8) & 0x00ffffff)) << 23;

	ans = (s << 31) | e  | ((frac >> 9) & 0x007fffff);
	return ans;
}*/
	int sign = x & (1 << 31);
	int minus = 1 << 31;
	int exp = 31;
	int bias = 127;
	int frac;
	if(!x)
		return 0;
	if(x == minus)
		return minus | ((exp + bias) << 23);
	if(sign)
		x = ~x + 1;
	while(!(x & minus)){
		x <<= 1;
		exp -= 1;
	}
	frac = (((~minus) & x) >> 8);
       if(x & 0x80 && ((frac & 1) || ((x & 0x7f) > 0))){
       	frac++;
       }	       

  return sign + ((exp + bias) << 23) + frac;
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
	unsigned exp = (uf >> 23) & 0x000000ff;
	unsigned sign = (uf >> 31) & 0x00000001;
      	unsigned frac = uf & 0x007fffff;
	unsigned e;
	int ans;
	//unsigned c_frac = uf & 0x007fffff;
	//int num = 1;

	if(exp >= 158){
		return 0x80000000;
	}

	if(exp < 127){
		return 0;
	}

	if(exp == 0xff){
		return 0x80000000u;
	}
	
	e = exp - 127;

	if(e >= 23){
		ans = ((1 << e) | (frac << (e - 23)));
	}
	else{
		ans = ((1 << e) | (frac >> (23 - e)));
		/*while(c_frac != 0x00){
			c_frac = c_frac >> 1;
			num = num << 1;
		}*/
	}
		

	//ans = (frac | num) << (exp - 127);
	if(sign){
		ans = ((~ans) + 1);
	}

	
  return ans;
}
