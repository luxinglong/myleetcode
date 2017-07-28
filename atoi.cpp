/********************************************************************************** 
* 
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge, 
*       please do not see below and ask yourself what are the possible input cases.
* 
* Notes: 
*   It is intended for this problem to be specified vaguely (ie, no given input specs). 
*   You are responsible to gather all the input requirements up front. 
* 
* 
* Requirements for atoi:
* 
* The function first discards as many whitespace characters as necessary until the first 
* non-whitespace character is found. Then, starting from this character, takes an optional 
* initial plus or minus sign followed by as many numerical digits as possible, and interprets 
* them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, 
* which are ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, 
* or if no such sequence exists because either str is empty or it contains only whitespace 
* characters, no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value 
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) 
* is returned.
*               
**********************************************************************************/
#include <iostream>

using namespace std;

#define DEBUG_CHECK(cond, out_stream, oss){if (!cond) oss << out_stream << endl;}

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int atoi(const char* str)
{
	int sign = 1, base = 0, i = 0;
	while (str[i] == ' '){i++;}
	if (str[i] == '-' || str[i] == '+'){
		sign = 1 - 2 * (str[i++] == '-');
	}
	while (str[i] >= '0' && str[i] <= '9'){
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)){
			if (sign == 1) return INT_MAX;
			else return INT_MIN;
		}
		base = 10*base + (str[i++] - '0');
	}
	return base*sign;
}

int main(int argc, char** argv)
{
	DEBUG_CHECK((atoi("") == 0), "Input NULL not return 0.", cout);
	cout << "NULL: " << atoi("") << endl;

	DEBUG_CHECK((atoi("  12a12") == 12), "Input \"  12a12\" not return 12", cout);
	cout << "  12a12: " << atoi("  12a12") << endl;

	DEBUG_CHECK((atoi("+12512") == 12512), "Input \"+12512\" not return 12512", cout);
	cout << "+12512: " << atoi("+12512") << endl;

	DEBUG_CHECK((atoi("-12512") == -12512), "Input \"-12512\" not return -12512", cout);
	cout << "-12512: " << atoi("-12512") << endl;

	DEBUG_CHECK((atoi("abc12512") == 12512), "Input \"abc12512\" not return 12512", cout);
	cout << "abc12512: " << atoi("abc12512") << endl;

	DEBUG_CHECK((atoi("2147483647") == 2147483647), "Input \"2147483647\" not return 2147483647", cout);
	cout << "2147483647: " << atoi("2147483647") << endl;

	DEBUG_CHECK((atoi("-2147483648") == -2147483648), "Input \"-2147483648\" not return -2147483648", cout);
	cout << "-2147483648: " << atoi("-2147483648") << endl;

	DEBUG_CHECK((atoi("2147483648") == 2147483647), "Input \"2147483648\" not return 2147483647", cout);
	cout << "2147483648: " << atoi("2147483648") << endl;

	DEBUG_CHECK((atoi("-2147483649") == -2147483648), "Input \"-2147483649\" not return -2147483648", cout);
	cout << "-2147483649: " << atoi("-2147483649") << endl;

	return 0;
}
