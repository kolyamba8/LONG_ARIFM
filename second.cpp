#include "second.h"
#include "stdio.h"

//constructor		
CSECOND::CSECOND()
{
	str_num = new unsigned char[1];
	str_num[0] = '\0';
	sign = new int;
	*sign = 0;
}

//constr from file
CSECOND::CSECOND(char *fileName, int flag)
{
	if (flag == 0)
	{
		sign = new int;
		str_num = reverse(input(fileName,sign));
	}
	else
	{
		sign = new int;
		*sign = 0;	
		str_num = reverse(input_bin(fileName));
	}	
}

//one more constr
CSECOND::CSECOND(unsigned char *str, int s)
{
	sign = new int;
	*sign = s;
	str_num = str;
}


/*------------------------ADDITION---------------------------------*/
const CSECOND CSECOND::plus(const CSECOND& left, const CSECOND& right)
{
	unsigned char *temp = NULL;
	int s;
	if(!*left.sign && !*right.sign)//+ +
	{
		temp = add(left.str_num, right.str_num);
		s = 0;
	}
	if(*left.sign && *right.sign)//- -
	{
		temp = add(left.str_num, right.str_num);
		s = 1;
	}
	if(!*left.sign && *right.sign)//+ -
	{
		if(greater(left.str_num,right.str_num) || equal(left.str_num,right.str_num))
		{
			temp = sub(left.str_num,right.str_num);
			s = 0;
		}
		else
		{
			temp = sub(right.str_num,left.str_num);
			s = 1;
		}
	}
	if(*left.sign && !*right.sign)//- +
	{
		if(greater(left.str_num,right.str_num) || equal(left.str_num,right.str_num))
		{
			temp = sub(left.str_num,right.str_num);
			s = 1;
		}
		else
		{
			temp = sub(right.str_num,left.str_num);
			s = 0;
		}
	}

	return CSECOND(temp, s);
}

/*------------------------SUBMISSION---------------------------------*/
const CSECOND CSECOND::minus(const CSECOND& left, const CSECOND& right)
{
	unsigned char *temp = NULL;
	int s;
	if(!*left.sign && !*right.sign)//+ +
	{
		if(greater(left.str_num,right.str_num) || equal(left.str_num,right.str_num))
		{
			temp = sub(left.str_num,right.str_num);
			s = 0;
		}
		else
		{
			temp = sub(right.str_num,left.str_num);
			s = 1;
		}
		
	}
	if(*left.sign && *right.sign)//- -
	{
		if(greater(left.str_num,right.str_num) || equal(left.str_num,right.str_num))
		{
			temp = sub(left.str_num,right.str_num);
			s = 1;
		}
		else
		{
			temp =  sub(right.str_num,left.str_num);
			s = 0;
		}
		
	}
	if(!*left.sign && *right.sign)//+ -
	{
		temp =  add(left.str_num, right.str_num);
		s = 0;
	}
	if(*left.sign && !*right.sign)//- +
	{
		temp =  add(left.str_num, right.str_num);
		s = 1;
	}
	return CSECOND(temp, s);
}

/*------------------------MULTIPLY---------------------------------*/
const CSECOND CSECOND::multiply(const CSECOND& left, const CSECOND& right)
{
	unsigned char *temp= NULL;
	int s;
	if(!*left.sign && !*right.sign)//+ +
	{
		temp = mul(left.str_num, right.str_num);
		s = 0;
	}
	if(*left.sign && *right.sign)//- -
	{
		temp = mul(left.str_num, right.str_num);
		s = 0;
	}
	if(!*left.sign && *right.sign)//+ -
	{
		temp = mul(left.str_num, right.str_num);
		s = 1;
	}
	if(*left.sign && !*right.sign)//- +
	{
		temp = mul(left.str_num, right.str_num);
		s = 1;
	}

	return CSECOND(temp, s);
}

/*------------------------DIVIDE---------------------------------*/
const CSECOND CSECOND::divide(const CSECOND& left, const CSECOND& right)
{
	unsigned char *temp= NULL;
	int s;
	if(equal(right.str_num,(unsigned char*)"0")) 
		throw "ERROR";

	if(!*left.sign && !*right.sign)//+ +
	{
		temp = deg(left.str_num, right.str_num);
		s = 0;
	}
	if(*left.sign && *right.sign)//- -
	{
		temp = deg(left.str_num, right.str_num);
		s = 0;
	}
	if(!*left.sign && *right.sign)//+ -
	{
		temp = deg(left.str_num, right.str_num);
		s = 1;
	}
	if(*left.sign && !*right.sign)//- +
	{
		temp = deg(left.str_num, right.str_num);
		s = 1;
	}

	return CSECOND(temp, s);
}

/*------------------------MODULE---------------------------------*/
const CSECOND CSECOND::module(const CSECOND& left, const CSECOND& right) 
{
	unsigned char *temp= NULL;
	int s;
	if(!*left.sign && !*right.sign)//+ +
	{
		temp = mod(left.str_num, right.str_num);
		s = 0;
	}
	if(*left.sign && *right.sign)//- -
	{
		temp = mod(left.str_num, right.str_num);
		s = 0;
	}
	if(!*left.sign && *right.sign)//+ -
	{
		temp = mod(left.str_num, right.str_num);
		s = 1;
	}
	if(*left.sign && !*right.sign)//- +
	{
		temp = mod(left.str_num, right.str_num);
		s = 1;
	}

	return CSECOND(temp, s);
}

/*------------------------POWER---------------------------------*/
const CSECOND CSECOND::power(const CSECOND& left, const CSECOND& right) 
{
	unsigned char *temp= NULL;
	int s;
	
	if(*left.sign)
	{
		if(mod(right.str_num,(unsigned char*)"2"))
			s = 0;
		else
			s = 1;
	}
	else
	{
		s = 0;
	}
	temp = pows(right.str_num,left.str_num);
	
	return CSECOND(temp, s);
}

/*------------------------OUTPUT---------------------------------*/
void CSECOND::output(char *fileN)
{
	FILE *F = fopen(fileN, "w");

	if(*sign)
		fprintf(F,"%c",'-');
	
	unsigned char *t1 = reverse(str_num);
	for(int i = 0; i < lenstr(t1); i++)
		fprintf(F, "%c",t1[i]);

	fclose(F);
}

void CSECOND::b_output(char *fileN)
{
	output_bin(fileN, str_num);	
}


void CSECOND::PRINTOUT()
{
	printf("%d", lenstr(str_num));
	printf("%s", lenstr);
}
