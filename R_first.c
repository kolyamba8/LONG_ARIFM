#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "first.h"

int osn, dop;
/*-----------------COPY--------------------*/
unsigned char* copy(unsigned char* t1)
{
	unsigned char *t2;
	int a = lenstr(t1), i = 0;
	t2 = (unsigned char*)malloc(sizeof(unsigned char)*a);
	while(t1[i])
	{
		t2[i] = t1[i];
		i++;
	}
	t2[i] = '\0';
	return t2;
	
}
/*-----------------INPUT-------------------*/
unsigned char* input(char *fileName, int *s)
{
	FILE *f = fopen(fileName,"r");
	int n = 0, i;
	unsigned char temp;
	unsigned char *t1;
	int sign;

	fseek(f,0,SEEK_END);
	n = ftell(f);
	rewind(f);
	temp = fgetc(f);

	if(temp == '-') 
	{
		sign = 1;
		t1 = (unsigned char*)malloc(sizeof(unsigned char)*n);
		t1[n-1] = '\0';
		
	}
	else
	{
		sign = 0;
		t1 = (unsigned char*)malloc(sizeof(unsigned char)*(n+1));
		t1[n] = '\0';
		rewind(f);
	}
	
	
	i = 0;
	while(i < n)
	{
		fscanf(f,"%c",&t1[i]);
		i++;
	}
	t1[lenstr(t1)-1] = '\0';
	fclose(f);
	*s = sign;
	osn = 10;
	dop = 48;
	return t1;
}

/*---------------REVERSE----------------*/
unsigned char* reverse(unsigned char* t1)
{
	int i;
	unsigned char *t2 = (unsigned char*)malloc(sizeof(unsigned char)*lenstr(t1));
	t2[lenstr(t1)] = '\0';
	
	i = 0;
	while(i < lenstr(t1))
	{
		t2[lenstr(t1)-1 -i] = t1[i];
		i++;
	}
 
	return t2;
}

/*-----------------PRINT----------------*/
void print(unsigned char *t1, int *s)
{
	int n = lenstr(t1);
	if(*s == '-')
		printf("%c",'-');
	int i = 0;
	printf("%s", t1);
	
}

/*-----------------EQUAL----------------*/
int equal(unsigned char *t1, unsigned char *t2)
{
	int i = 0;
	if (lenstr(t1) != lenstr(t2))
		return 0;
	while(i < lenstr(t1))
	{
		if (t1[i]!= t2[i])
			return 0;
		i++;
	
	}	
	return 1;
}

/*-----------------GREATER----------------*/
int greater(unsigned char *t1, unsigned char *t2)
{
	if (lenstr(t1) != lenstr(t2))
			return lenstr(t1) > lenstr(t2);

	int i = lenstr(t1)-1;
	while(i >= 0)
	{
		if (t1[i]!=t2[i])
			return t1[i]>t2[i];
		i--;
	}

	return 0;
}

/*-----------------LESS----------------*/
int less(unsigned char *t1, unsigned char *t2)
{
	if (lenstr(t1) != lenstr(t2))
			return lenstr(t1) < lenstr(t2);

	int i = lenstr(t1)-1;
	while(i >= 0)
	{
		if (t1[i]!=t2[i])
			return t1[i]<t2[i];
		i--;
	}
	return 0;
}

/*--------------CUTZERO----------------*/
char* cutzero(char *t1)
{
	while(t1[lenstr(t1)-1] == '0')
	{
		if(lenstr(t1) == 1 && t1[0] == '0') return t1;
		t1[lenstr(t1)-1] = '\0';
	}
	return  t1;
}

/*--------------ADD----------------*/
unsigned char* add(unsigned char *t1, unsigned char *t2)
{
	//const int osn = 10;
	int i,temp;
	char unsigned r = 0;
	char unsigned *a, *b, *c, *t;
	int lenA, lenB;
	if(lenstr(t1) != lenstr(t2))
	{
		if(lenstr(t1) > lenstr(t2))
		{
			a = copy(t1);
			b = (unsigned char*)malloc(sizeof(unsigned char)*lenstr(a));
			i = 0;
			while(i < lenstr(t2))
			{
				b[i] = t2[i];
				i++;
			}
			
			i = lenstr(t2);
			while(i < lenstr(t1))
			{
				b[i] = '0';
				i++;
			}

			b[i] = '\0';
		}
		else
		{
			a = copy(t2);
			lenA = lenstr(a);
			b = (unsigned char*)malloc(sizeof(unsigned char)*lenA);
			i = 0;
			while(i < lenstr(t1))
			{
				b[i] = t1[i];
				i++;
			}

			i = lenstr(t1);
			while(i < lenstr(t2))
			{
				b[i] = '0';
				i++;
			}

			b[i] = '\0';
		}
	}
	else
	{
		a = copy(t1);
		b = copy(t2);
	}

	lenA = lenstr(a);
	c = (unsigned char*)malloc(sizeof(unsigned char)*(lenA+2));
	c[lenA+1] = '\0';
	
	i = 0;
	while(i < lenA+1)
	{
		c[i] = '0';
		i++;
	}
		
	i = 0;
	while(i < lenstr(a))
	{
		temp = a[i] + b[i] + r - dop;
		//c[i] = a[i] + b[i] + r - 48;
		if (temp >= dop + osn) //58
				{
					temp-=osn;
					r = 1;
				}
				else
					r = 0;
		c[i] = temp;
		i++;
	}
	if(r) c[i] += r;

	return cutzero(c);
}

/*--------------SUB----------------*/
unsigned char* sub(unsigned char *t1, unsigned char *t2)
{
	//const int osn = 10;
	int i;
	unsigned char *a, *b, *c, *t;
	unsigned char r = 48;

	if(lenstr(t1) > lenstr(t2))
	{
		a = copy(t1);
		b = (unsigned char*)malloc(sizeof(unsigned char)*(lenstr(a)));
		for( i = 0; i < lenstr(t2); i++)
			b[i] = t2[i];

		for( i = lenstr(t2); i < lenstr(t1); i++)
			b[i] = '0';
		b[i] = '\0';
	}
	else
	{
		a = copy(t1);
		b = copy(t2);
	}

	
	c = (unsigned char*)malloc(sizeof(unsigned char)*(lenstr(a)+1));
	c[lenstr(a)] = '\0';

	i = 0;
	while(i < lenstr(c))
	{
		c[i] = '0';
		i++;
	}
	
	i = 0;
	while(i < lenstr(a))
	{
		c[i] = a[i] - b[i] + dop;
		if (c[i] < dop)
		{
			c[i]+=osn;
			a[i+1]--;
		}
		i++;

	}

	return cutzero(c);
}


/*--------------MUL----------------*/
unsigned char* mul(unsigned char *t1, unsigned char* t2)
{
	//const int osn = 10;
	unsigned char *a,*b,*c,r;
	int i,j,l;
	a = t1;
	b = t2;
	c = (unsigned char*)malloc(sizeof(unsigned char)*(lenstr(a)+lenstr(b)));
	j = lenstr(a)+lenstr(b);
	c[lenstr(a)+lenstr(b)] = '\0';
	
	i = 0;
	while(i < j)
	{
		c[i] = '0';
		i++;
	}
	
	i = 0;
	while(i < lenstr(a))
	{
		r = 0;
		j = 0;
		while(j < lenstr(b))
		{
			l = c[i+j];
			l += ((a[i] - dop) * (b[j] - dop)) + r;
			r = (l-dop) / osn;
			l -= r*osn;
			c[i+j] = l;
			j++;
		}
		if(r) c[i+j] += r;
		i++;
	}

	return cutzero(c);


}

/*--------------MULN----------------*/
unsigned char* mulN(unsigned char *t1, long t2)
{
	unsigned char *b= NULL;
	int t2_lenth = 0;
	long c = t2;
	int i;
	while(c != 0)
	{
		t2_lenth++;
		c /= osn;
	}
	if(t2_lenth == 0)
	{
		b = (unsigned char*)malloc(sizeof(unsigned char)*2);
		b[0] = '0';
		b[1] = '\0';
	}
	else
	{
		b = (unsigned char*)malloc(sizeof(unsigned char)*(t2_lenth+1));
		c = t2;
		i = 0;
		while(i < t2_lenth)
		{
			b[i] = c % osn + dop;
			c /= osn;
			i++;
		}
		b[t2_lenth] = '\0';
	}

	return cutzero(mul(t1,b));
}


/*--------------DEG----------------*/
unsigned char* deg(unsigned char *t1, unsigned char *t2)
{
	unsigned char *a = NULL,*b= NULL,*c= NULL, *buf= NULL, *res= NULL;
	int x,y,d,k,i;
	int lenA, lenB, lenC;
	unsigned char *z = (unsigned char*)malloc(sizeof(unsigned char)*2);
	z[0] = '0';
	z[1] = '\0';
	res = (unsigned char*)malloc(sizeof(unsigned char)*1);
	res[0] = '\0';
	a = t1;
	b = t2;

	while(greater(a, b) || equal(a,b))
	{
		lenB = lenstr(b);
		c = (unsigned char*)malloc(sizeof(unsigned char)*(lenB+1));
		c[lenB] = '\0';
		lenA = lenstr(a);
		lenC = lenB;
		i = 0;
		while(i < lenB)
		{
			c[i] = a[lenA+i-lenC];
			i++;
		}
		//
		if(less(c,b))
		{
			c = levelup(c);
			c[0] = a[lenA-lenC-1];
		}
		//
		x = 0;

		while(less(mulN(b,x),c) || equal(mulN(b,x),c))
			x++;
		x--;

		
		res  = levelup(res);
		res[0] = x + dop;

		buf = mulN(b,x);

		y = 0;
		d = 1;
		while(less(buf,a) || equal(buf,a))
		{
			y++;
			buf = mulN(buf,osn);
		}
		buf = leveldown(buf);
		a = sub(a,buf);
		if(equal(a,z))
		{
			k = 0;
			while(k < y-1)
			{
				d *= osn;
				k++;
			}

			res = mulN(res,d);
		}
		
	}
	return res;

}

/*--------------MOD----------------*/
unsigned char* mod(unsigned char *t1, unsigned char *t2)
{
	unsigned char *a = NULL,*b= NULL,*c= NULL, *buf= NULL, *res= NULL;
	int x,y,d,k,i;
	int lenA, lenB, lenC;
	unsigned char *z = (unsigned char*)malloc(sizeof(unsigned char)*2);
	z[0] = '0';
	z[1] = '\0';
	res = (unsigned char*)malloc(sizeof(unsigned char)*1);
	res[0] = '\0';
	a = t1;
	b = t2;

	while(greater(a, b) || equal(a,b))
	{
		lenB = lenstr(b);
		c = (unsigned char*)malloc(sizeof(unsigned char)*(lenB+1));
		c[lenB] = '\0';
		lenA = lenstr(a);
		lenC = lenB;
		i = 0;
		while(i < lenB)
		{
			c[i] = a[lenA+i-lenC];
			i++;
		}
		//
		if(less(c,b))
		{
			c = levelup(c);
			c[0] = a[lenA-lenC-1];
		}
		//
		x = 0;

		while(less(mulN(b,x),c) || equal(mulN(b,x),c))
			x++;
		x--;

		
		res  = levelup(res);
		res[0] = x + 48;

		buf = mulN(b,x);

		y = 0;
		d = 1;
		while(less(buf,a) || equal(buf,a))
		{
			y++;
			buf = mulN(buf,10);
		}
		buf = leveldown(buf);
		a = sub(a,buf);
		if(equal(a,z))
		{
			k = 0;
			while(k < y-1)
			{
				d *= 10;
				k++;
			}

			res = mulN(res,d);
		}
		
	}
	return a;

}

/*--------------POWS----------------*/
unsigned char *pows(unsigned char *t1, unsigned char *t2)
{
	unsigned char *res = "1";
	unsigned char *a = t1;
	unsigned char *n = t2;
	unsigned char *z = "0";


	while (!(equal(n,z)))
	{
		if (!(equal(mod(n,"2"),z))) 
		{
			res = mul(res,a);
			n = sub(n,"1");
		}
		else 
		{
			a = mul(a,a);
			n = deg(n,"2");
		}
	}
	return res;
}

/*--------------LEVELUP----------------*/
unsigned char* levelup(unsigned char *t1)
{
	int i;
	unsigned char *t2 = (unsigned char*)malloc(sizeof(unsigned char)*(lenstr(t1)+2));
	
	i = lenstr(t1)+1;
	while(i >= 1)
	{
		t2[i] = t1[i-1];
		i--;
	}
	return t2;

}

/*--------------LEVELDOWN----------------*/
unsigned char* leveldown(unsigned char *t1)
{
	unsigned char *t2 = (unsigned char*)malloc(sizeof(unsigned char)*lenstr(t1));
	int i = 0;
	while(i < lenstr(t1))
	{
		t2[i] = t1[i+1];
		i++;
	}
	return t2;
}

/*--------------LENSTR----------------*/
int lenstr(unsigned char *t1)
{
	int i = 0;
	while(t1[i])
		i++;

	return i;
}

/*================BINARY==============*/

/*---------------INPUT---------------*/
unsigned char* input_bin(char *fileName)
{
	FILE *f = fopen(fileName,"rb");
	long n = 0, i;
	unsigned char temp;
	unsigned char *t1;
	
	while(!feof(f))
	{
		fread(&temp,sizeof(unsigned char),1,f);
		n++;
	}

	rewind(f);
	t1 = (unsigned char*)malloc(sizeof(unsigned char)*(n+1));
	n = 0;
	while(!feof(f))
	{
		fread(&temp,sizeof(unsigned char),1,f);
		t1[n] = temp;
		n++;
	}
	t1[n] = '\0';
	osn = 255;
	dop = 0;
	fclose(f);
	return t1;
}

/*---------------OUTPUT---------------*/
void output_bin(char *fileName, unsigned char *t1)
{
	FILE *f = fopen(fileName,"wb");
	fwrite(t1,sizeof(unsigned char),lenstr(t1),f);
	fclose(f);
}

