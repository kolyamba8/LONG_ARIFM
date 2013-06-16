extern "C"
{
#include "first.h"
}

class  CSECOND {
public:
	CSECOND(void);
	CSECOND(char *fileName, int flag);
	const static CSECOND plus(const CSECOND& left, const CSECOND& right);
	const static CSECOND minus(const CSECOND& left, const CSECOND& right);
	const static CSECOND divide(const CSECOND& left, const CSECOND& right);
	const static CSECOND multiply(const CSECOND& left, const CSECOND& right);
	const static CSECOND module(const CSECOND& left, const CSECOND& right);
	const static CSECOND power(const CSECOND& left, const CSECOND& right);
	void b_output(char *fileN);
	void output(char *fileN);
	void PRINTOUT();
private:
	CSECOND(unsigned char *str, int s);
	unsigned char *str_num;
	int *sign;
};
