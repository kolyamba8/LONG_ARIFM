#include "second.h"
#include "stdio.h"

int main(int argc, char * argv[])
{
	CSECOND a(argv[1],0);
	CSECOND b(argv[3],0);
	CSECOND c;
	char *znak = argv[2];
	if(znak[0] == '+')
		c = a+b;
	if(znak[0] == '-')
		c = a-b;
	if(znak[0] == '*')
		c = a*b;
	if(znak[0] == '/')
		c = a/b;
	if(znak[0] == '%')
		c = a%b;
	if(znak[0] == '^')
		c = a^b;
	c.output(argv[4]);
	return 0;
}
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
CSECOND CSECOND::operator+(CSECOND left)
{
	unsigned char *temp = NULL;
	int s;
	if(!*left.sign && !*sign)//+ +
	{
		temp = add(str_num,left.str_num);
		s = 0;
	}
	if(*left.sign && *sign)//- -
	{
		temp = add(str_num,left.str_num);
		s = 1;
	}
	if(!*left.sign && *sign)//+ -
	{
		if(greater(str_num,left.str_num) || equal(str_num,left.str_num))
		{
			temp = sub(str_num,left.str_num);
			s = 0;
		}
		else
		{
			temp = sub(str_num,left.str_num);
			s = 1;
		}
	}
	if(*left.sign && !*sign)//- +
	{
		if(greater(str_num,left.str_num) || equal(str_num,left.str_num))
		{
			temp = sub(str_num,left.str_num);
			s = 1;
		}
		else
		{
			temp = sub(str_num,left.str_num);
			s = 0;
		}
	}

	return CSECOND(temp, s);
}

/*------------------------SUBMISSION---------------------------------*/
CSECOND CSECOND::operator-(CSECOND left)
{
	unsigned char *temp = NULL;
	int s;
	if(!*left.sign && !*sign)//+ +
	{
		if(greater(str_num,left.str_num) || equal(str_num,left.str_num))
		{
			temp = sub(str_num,left.str_num);
			s = 0;
		}
		else
		{
			temp = sub(str_num,left.str_num);
			s = 1;
		}
		
	}
	if(*left.sign && *sign)//- -
	{
		if(greater(str_num,left.str_num) || equal(str_num,left.str_num))
		{
			temp = sub(str_num,left.str_num);
			s = 1;
		}
		else
		{
			temp =  sub(str_num,left.str_num);
			s = 0;
		}
		
	}
	if(!*left.sign && *sign)//+ -
	{
		temp =  add(str_num,left.str_num);
		s = 0;
	}
	if(*left.sign && !*sign)//- +
	{
		temp =  add(str_num,left.str_num);
		s = 1;
	}
	return CSECOND(temp, s);
}

/*------------------------MULTIPLY---------------------------------*/
CSECOND CSECOND::operator*(CSECOND left)
{
	unsigned char *temp= NULL;
	int s;
	if(!*left.sign && !*sign)//+ +
	{
		temp = mul(str_num,left.str_num);
		s = 0;
	}
	if(*left.sign && *sign)//- -
	{
		temp = mul(str_num,left.str_num);
		s = 0;
	}
	if(!*left.sign && *sign)//+ -
	{
		temp = mul(str_num,left.str_num);
		s = 1;
	}
	if(*left.sign && !*sign)//- +
	{
		temp = mul(str_num,left.str_num);
		s = 1;
	}

	return CSECOND(temp, s);
}

/*------------------------DIVIDE---------------------------------*/
CSECOND CSECOND::operator/(CSECOND left)
{
	unsigned char *temp= NULL;
	int s;
	if(equal(str_num,(unsigned char*)"0")) 
		throw "ERROR";

	if(!*left.sign && !*sign)//+ +
	{
		temp = deg(str_num,left.str_num);
		s = 0;
	}
	if(*left.sign && *sign)//- -
	{
		temp = deg(str_num,left.str_num);
		s = 0;
	}
	if(!*left.sign && *sign)//+ -
	{
		temp = deg(str_num,left.str_num);
		s = 1;
	}
	if(*left.sign && !*sign)//- +
	{
		temp = deg(str_num,left.str_num);
		s = 1;
	}

	return CSECOND(temp, s);
}

/*------------------------MODULE---------------------------------*/
CSECOND CSECOND::operator%(CSECOND left) 
{
	unsigned char *temp= NULL;
	int s;
	if(!*left.sign && !*sign)//+ +
	{
		temp = mod(str_num,left.str_num);
		s = 0;
	}
	if(*left.sign && *sign)//- -
	{
		temp = mod(str_num,left.str_num);
		s = 0;
	}
	if(!*left.sign && *sign)//+ -
	{
		temp = mod(str_num,left.str_num);
		s = 1;
	}
	if(*left.sign && !*sign)//- +
	{
		temp = mod(str_num,left.str_num);
		s = 1;
	}

	return CSECOND(temp, s);
}

/*------------------------POWER---------------------------------*/
CSECOND CSECOND::operator^(CSECOND left) 
{
	unsigned char *temp= NULL;
	int s;
	
	if(*left.sign)
	{
		if(mod(str_num,(unsigned char*)"2"))
			s = 0;
		else
			s = 1;
	}
	else
	{
		s = 0;
	}
	temp = pows(str_num,left.str_num);
	
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
