#include <iostream>
#include <string>

using namespace std;

#define DEBUG_CHECK(cond, out_stream, oss){ if (!cond) oss << out_stream << endl; }

// primer -> rprime -> erprim -> merpri -> imerpr -> rimerp -> primer
// primer -> rimerp -> imerpr -> merpri -> erprim -> rprime -> primer

// time: O(n^2) mem: O(1)
int shift(string & str, int k)
{
	if (str.empty())
	{
		cerr << "Please input a valid string." << endl;
		return -1;
	}

	int N = str.size();
	char temp;

	if (k > 0)
	{
		while (k--)
		{
			temp = str[N - 1];
			for (int i = 1; i < N; i++)
			{
				str[N - i] = str[N - i - 1];
			}
			str[0] = temp;
		}
	}
	else
	{
		while (-(k++))
		{
			temp = str[0];
			for (int i = 1; i < N; i++)
			{
				str[i-1] = str[i];
			}
			str[N - 1] = temp;
		}
	}
	return 0;
}

// primer -> remirp
// abcde -> edcba
void reverse(string & str, int begin, int end)
{
	char temp;
	for (; begin < end; begin++, end--)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
	}
}

// primer -> erprim: prim+er -> mirp+re=mirpre -> erprim
// primer -> imerpr: pr+imer -> rp+remi=rpremi -> imerpr

// time: O(n) mem: O(1)
/* 1. segment string as two part: str = str1 + str2
*  2. reverse str1 and str2 seperately
*  3. reverse str1+str2
*/
int shift_optimal(string & str, int k)
{
	if (str.empty())
	{
		cerr << "Please input a valid string." << endl;
		return -1;
	}

	int N = str.size();
	char temp;

	if (k > 0)
	{
		reverse(str, 0, N-k-1);
		reverse(str, N-k, N-1);
		reverse(str, 0, N-1);
	}
	else
	{
		reverse(str, 0,  -k - 1);
		reverse(str,  -k, N - 1);
		reverse(str, 0, N - 1);
	}
	return 0;
}



int main(int argc, char** argv)
{
	string str = "primer_cpp_lxl";
	int shift_bit = -6;

	string src = str;

	cout << "Shift " << str << " " << shift_bit << " bits." << endl;

	//shift(str, shift_bit);
	//cout << "Shift result is: " << str << endl;

	shift_optimal(str, shift_bit);
	cout << "Shift_optimal result is: " << str << endl;
	bool flag = str == "_cpp_lxlprimer";
	DEBUG_CHECK(flag, "shift "+src+" error", cout);

	system("pause");
	return 0;
}