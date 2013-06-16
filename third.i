%module third
%{
#include "second.h"
%}

class  CSECOND {
public:
	CSECOND(void);
	CSECOND(char *fileName, int flag);
	static CSECOND plus(const CSECOND& left, const CSECOND& right);
	static CSECOND minus(const CSECOND& left, const CSECOND& right);
	static CSECOND divide(const CSECOND& left, const CSECOND& right);
	static CSECOND multiply(const CSECOND& left, const CSECOND& right);
	static CSECOND module(const CSECOND& left, const CSECOND& right);
	static CSECOND power(const CSECOND& left, const CSECOND& right);
	void output(char *fileN);
	void b_output(char *fileN);
};
