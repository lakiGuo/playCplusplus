
#ifndef GCD_H
#define GCD_H
#include "myException.h"
int gcd(int a,int b);
/*求最大公约数，输入正整数
gcd = x if y==0
gcd = gcd(y,x mod y)
*/
int gcd(int a, int b)
{
	if (a < 0 || b < 0) {
		throw illegalParameterValue("All parameters should be >0");
	}
	if (b == 0) return a;
	else
	{
		return gcd(b, a % b);
	}
}

#endif // !GCD_H
