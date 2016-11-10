#include <stdio.h>
/*
 * bitwise_nor  - implement ~(x|y) using only ~ and &.
 *  Example biwise_nor(6, 5) = 0xFFFFFFF8
 *  Max. # of operators: 8
 *	Should be 8 if you input 3 and 5
 * 	WORKS
 */
int bitwise_nor(int x, int y) {
	int b;
	b = ~x & ~y;
  return b;

}

nadn
/*
 * bitwise_xor - implement x xor y using only ~ and &.
 * Example bitwise_xor(4,5) = 0x1
 * Max # of operators: 14
 * should be 6 if you inout 3 and 5
 * WORKS
 */
int bitwise_xor(int x, int y) {
	int a ,b, c, d;
	a = x & y;
	b = ~(a);
	c = ~x & ~y;
	d = b & (~c);
  return d;
}

/*
 * eval_not_equal - implement x!=y.
 *  using only !, ~, &, |, ^, +, << and >>
 *   returns 0 if x == y, otherwise 1
 * Examples: eval_not_equal(2,2) = 0, eval_not_equal(3,4) = 1
 * Max # of operators: 6
 * WORKS
 */
int eval_not_equal(int x, int y) {
	int b;
	b =  !!(x ^ y);
 return b;

}


/*
 * get_byte - extract byte n from word x.
 *  using only !, ~, &, |, ^, +, << and >>
 * do not use any constant values of more than 1 byte in size
 * assume ordering as 0=least significant byte,
 * 3 = most significant byte.
 * Example: get_byte(0x12345678, 1) = 0x56
 * Example: get_byte(305419896, 1) = 0x56
 * Max # of operators: 6
 * WORKS
*/
int get_byte(int x, int n) {
	int b;
	n = n << 3;
	b = x >> n;
	b = b & 0xFF;
  	return b;


}



/*
* copy_lsbit - set all bits of result value to the least significant bit of x
*  using only !, ~, &, |, ^, +, << and >>
* do not use any constant values of more than 1 byte in size
*  Examples: copy_lsbit(5) = 0xFFFFFFFF, copy_lsbit(8) = 0x0
*  Max # of operators: 5
*  WORKS
*/
int copy_lsbit(int x) {
	x = x << 31;
	x = x >> 31;

  return x;
}

/*
 * bit_count - returns the # of bits in x that are 1.
 *  using only !, ~, &, |, ^, +, << and >>
 * do not use any constant values of more than 1 byte in size
 * examples: bit_count(2) = 1, bit_count(10) = 2, bit_count(7) = 3
 * Max # of operators: 40
 */
int bit_count(int x) {
int mask1 = 0x55;
int mask2 = 0x33;
int mask3 = 0x0f;
int y;
int z;

	x = (x & (x << 1) & (mask1 << 1)) | (mask1 & (x ^ (x >> 1)));
	y = x & mask2;
	z = (x >>  2) & mask2;
	x = y ^ z ^ ((y & z) << 1);
	y = (x & mask3 ) ^ ((x >>  4) & mask3);
	z = (x & ((x >>  4) & mask3)) << 1;
	x = y ^ z ^ ((y & z) << 1);

return x;
}
