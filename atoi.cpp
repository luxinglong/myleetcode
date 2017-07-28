#include <iostream>

using namespace std;

#define DEBUG_CHECK(cond, out_stream, oss){if (!cond) oss << out_stream << endl;}

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

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
}
