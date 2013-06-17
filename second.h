extern "C"
{
#include "first.h"
}

class  CSECOND {
public:
	CSECOND(void);
	CSECOND(char *fileName, int flag);
	CSECOND operator+(CSECOND );
	CSECOND operator-(CSECOND );
	CSECOND operator*(CSECOND );
	CSECOND operator/(CSECOND );
	CSECOND operator%(CSECOND );
	CSECOND operator^(CSECOND );
	void b_output(char *fileN);
	void output(char *fileN);
	void PRINTOUT();
private:
	CSECOND(unsigned char *str, int s);
	unsigned char *str_num;
	int *sign;
};
