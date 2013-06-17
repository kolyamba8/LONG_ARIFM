%module third
%{
#include "second.h"
%}

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
	void output(char *fileN);
	void b_output(char *fileN);
};
