#line 142 "bits.c"
int bitXor(int x, int y) {
        int first=(  x & ~y);
        int second=(  ~x & y);
  return ~(~first & ~second);

}
#line 154
int tmin(void) {
 int num=  0xff;

  return num<<31;
}
#line 167
int isTmax(int x) {
 int num=  x + 1;
 int num2=  ~x;
 int num3=  ~0x00;
  return !(num ^ num2) & !!(num2 & num3);
}
#line 180
int allOddBits(int x) {
 int num=(  0x55 << 24) +( 0x55 << 16) +( 0x55 << 8) + 0x55;
 int num2=  num | x;
  return !(num2 ^( ~0x00));
}
#line 192
int negate(int x) {
 int num=  ~x + 1;
  return num;
}
#line 206
int isAsciiDigit(int x) {
 int num=  !((x>>1) ^ 0x1c);
 int num2=  !((x>>3) ^ 0x06);
  return num | num2;
}
#line 218
int conditional(int x, int y, int z) {
 int num=  !!x;
 int num2=  !num;
 int num3=  ~num + 1;
 int num4=  ~num2 + 1;
  return (y & num3) |( z & num4);
}
#line 232
int isLessOrEqual(int x, int y) {
 int num=  !(x ^ y);
 int num2=(  x >> 31) & 1;
 int num3=(  y >> 31) & 1;
 int numx=(  num2 ^ num3);
 int num4=  numx & num2;
 int num5=(  !((((~x + 1) + y) >> 31) & 1)) & !numx;
  return num | num4 | num5;
}
#line 250
int logicalNeg(int x) {
 int num=  ~x + 1;
 int num2=  x >> 31;
 int num3=  num >> 31;
 int num4=(  num2 ^ num3) + 1;
 int num5=  ~(num2 & num3);
  return num4 & num5;
}
#line 270
int howManyBits(int x) {
 int num=  ~0X0;

  return num;
}
#line 287
unsigned float_twice(unsigned uf) {

 unsigned num=  uf + 0x00800000;
 if (uf== 0x00 || uf == 0x80000000 ||( uf > 0x7f800000 && uf <= 0x7fffffff) ||( uf > 0xff800000)) {
  return uf;
 }
 if ((num>= 0x7f800000 && num < 0x80000000) || uf == 0x7f800000) {
  return 0x7f800000;
 }
 if (num>= 0xff800000 || uf == 0xff800000) {
                return 0xff800000;
 }
 if (uf<= 0x007fffff) {
  return uf * 2;
 }
 if (uf<= 0x807fffff && uf > 0x80000000) {
  unsigned num2=  uf & 0x007fffff;
  return uf + num2;
 }
#line 310
  return num;
}
#line 321
unsigned float_i2f(int x) {
 int num=  x;
 int num2=  x;
 int exp=  0;
 int s=  0;
 int ans=  0;
 int e=  0;
 int frac=  0;
 int sfrac=  0;
 int ifrac=  0;
 int xfrac=  0;
 if (x== 0) {
  return 0x00;
 }

 if (x== 0x80000000) {
  return 0xcf000000;
 }

 if (x< 0) {
  s = 1;
  num2 = -num2;
  num = -num;
 }

 while (num>= 2) {
  num /= 2;
  exp += 1;
 }

 if (x>= 2147483584 || x <= -2147483584) {
  exp = 31;
 }


 frac = num2 <<( 32 - exp);
 sfrac = frac << 22;
 ifrac =( sfrac << 1) ^ 0x80000000;
 xfrac = sfrac ^ 0xc0000000;
 if (ifrac> 0) {
  frac = frac + 0x00000200;
 }

 if (xfrac== 0) {
  frac = frac + 0x00000200;
 }

 e = 127 + exp;

 ans =( s << 31) |( e << 23) |(( frac >> 9) & 0x007fffff);
  return ans;
}
#line 385
int float_f2i(unsigned uf) {
  return 2;
}
