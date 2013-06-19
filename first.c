#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "first.h"

int osn, dop, zapas = 50;
/*----------------------------------------------------ARIPHMETIC----------------------------------------------------*/

/*=========================ADD=============================*/
unsigned char* add(unsigned char *t1, unsigned char *t2)
{
	int i,temp;
	int r = 0;
	unsigned char *a, *b, *c, *t;
	int lenA, lenB;
	if(lenstr(t1) != lenstr(t2))
	{
		if(lenstr(t1) > lenstr(t2))
		{
			a = t1;
			lenA = lenstr(t1);
			b = (unsigned char*)malloc(sizeof(unsigned char)*(lenA+zapas));
			a[lenA] = '\0';
			i = 0;
			while(i < lenstr(t2))
			{
				b[i] = t2[i];
				i++;
			}
			b[i] = '\0';
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
			a = t2;
			lenA = lenstr(a);
			b = (unsigned char*)malloc(sizeof(unsigned char)*(lenA+zapas));
			a[lenA] = '\0';
			i = 0;
			while(i < lenstr(t1))
			{
				b[i] = t1[i];
				i++;
			}
			b[i] = '\0';
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
		a = t1;
		b = t2;
	}

	lenA = lenstr(a);
	c = (unsigned char*)malloc(sizeof(unsigned char)*((lenA+zapas)));
	c[lenA+1] = '\0';
	

	check(a);
	check(b);
	check(c);
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
		if (temp >= dop + osn)
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

	
	check(c);
	c = cutzero(c);
	return c;
}

/*=========================SUB=============================*/
unsigned char* sub(unsigned char *t1, unsigned char *t2)
{
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
		b = t2;
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
		c[i] = a[i] - b[i] + 48;
		if (c[i] < 48)
		{
			c[i]+=osn;
			a[i+1]--;
		}
		i++;
	}
	c[i] = '\0';
	check(c);
	c = cutzero(c);
	return c;
}

/*=========================MUL=============================*/
unsigned char* mul(unsigned char *t1, unsigned char* t2)
{
	//const int osn = 10;
	unsigned char *a,*b,*c,r;
	int i,j,l;
	a = t1;
	b = t2;
	int lenA = lenstr(a), lenB = lenstr(b);
	c = (unsigned char*)malloc(sizeof(unsigned char)*(lenA+lenB));
	j = lenA+lenB;
	c[lenA+lenB] = '\0';
	
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
	
	check(c);
	c = cutzero(c);
	return c;
}

/*=========================MULN=============================*/
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
	
	t1 = mul(t1,b);
	check(t1);
	t1 = cutzero(t1);
	return t1;
}


/*=========================DEG=============================*/
unsigned char* deg(unsigned char *t1, unsigned char *t2)
{
	int len1 = lenstr(t1);
	int len2 = lenstr(t2);
	int i = 0, len;
	unsigned char* res = (unsigned char*)malloc(sizeof(unsigned char)*(len1+len2+zapas));
	res[0] = '0';
	res[1] = '\0';
	unsigned char* a = t1;
	unsigned char *tempB, *tempRes, *tempRes2 = (unsigned char*)malloc(sizeof(unsigned char)*(len1+len2+zapas));
	
	unsigned char* c = copy(t2);
	check(a);
	check(c);

	if(greater(c,a)) return "0";
	else
	{
		i = 1;
		while(greater(a,c) || equal(a,c))
		{
			
			len1 = lenstr(a);
			len2 = lenstr(c);
			len = len1 - len2 -i;
			unsigned char* b = copy(c);
			check(b);
			tempRes2[0] = '1';
			tempRes2[1] = '\0';
			while(len > 0)
			{
				b = mulN(b,osn);
				tempRes2 = mulN(tempRes2,osn);
				len--;
			}
			res = add(res,tempRes2);
			tempB = copy(b);
			check(tempB);
			while(greater(a,b) || equal(a,b))
			{
				b = add(b,tempB);
				res = add(res,tempRes2);
				check(b);
			}
			b = sub(b,tempB);
			res = sub(res,tempRes2);
			
			len1 = lenstr(a);
			if(greater(b,a))
			{
				i++;
			}
			else
			{
				a = sub(a,b);
				i = 1;
			}
			len2 = lenstr(a);
		}
	}

	res = cutzero(res);
	check(res);
	return res;
}

/*=========================MOD=============================*/
unsigned char* mod(unsigned char *t1, unsigned char *t2)
{
	int len1 = lenstr(t1);
	int len2 = lenstr(t2);
	int i = 0, len;
	unsigned char* res = (unsigned char*)malloc(sizeof(unsigned char)*(len1+len2+zapas));
	res[0] = '0';
	res[1] = '\0';
	unsigned char* a = t1;
	unsigned char *tempB, *tempRes, *tempRes2 = (unsigned char*)malloc(sizeof(unsigned char)*(len1+len2+zapas));
	
	unsigned char* c = copy(t2);
	check(a);
	check(c);

	if(greater(c,a)) return "0";
	else
	{
		i = 1;
		while(greater(a,c) || equal(a,c))
		{
			
			len1 = lenstr(a);
			len2 = lenstr(c);
			len = len1 - len2 -i;
			unsigned char *b = copy(c);
			check(b);
			tempRes2[0] = '1';
			tempRes2[1] = '\0';
			while(len > 0)
			{
				b = mulN(b,osn);
				tempRes2 = mulN(tempRes2,osn);
				len--;
			}
			res = add(res,tempRes2);
			tempB = copy(b);
			check(tempB);
			while(greater(a,b) || equal(a,b))
			{
				b = add(b,tempB);
				res = add(res,tempRes2);
				check(b);
			}
			b = sub(b,tempB);
			res = sub(res,tempRes2);
			
			if(greater(b,a))
			{
				i++;
			}
			else
			{
				a = sub(a,b);
				i = 1;
			}
		}
	}

	a = cutzero(a);
	check(a);
	return a;
}

/*=========================POW=============================*/
unsigned char *pows(unsigned char *t1, unsigned char *t2)
{
	unsigned char *res = (unsigned char*)malloc(sizeof(unsigned char)*2);
	res[0] = '1';
	res[1] = '\0';
	unsigned char *z = (unsigned char*)malloc(sizeof(unsigned char)*2);
	z[0] = '0';
	z[1] = '\0';
	unsigned char *a = copy(t1);
	unsigned char *n = copy(t2);
	int *s = (int*)malloc(sizeof(int));


	while (!(equal(n,z)))
	{
		if (!(equal(mod(n,"2"),z)) || equal(n,"1")) 
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
	check(res);
	return res;
}

/*----------------------------------------------------LOGIC----------------------------------------------------*/

/*=========================EQUAL=============================*/
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

/*=========================GREATER=============================*/
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

/*=========================LESS=============================*/
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

/*----------------------------------------------------OTHER----------------------------------------------------*/

/*=======================INPUT=============================*/
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
		t1 = (unsigned char*)malloc(sizeof(unsigned char)*(n+zapas));
		
	}
	else
	{
		sign = 0;
		t1 = (unsigned char*)malloc(sizeof(unsigned char)*(n+1+zapas));
		rewind(f);
	}
	
	
	i = 0;

	fscanf(f,"%s",t1);
	i++;
	osn = 10;
	dop = 48;
	fclose(f);
	*s = sign;
	check(t1);
	return t1;
}

/*=======================CHECK=============================*/
void check(unsigned char *ch)
{
	int i = 0;
	while(ch[i] >= 48 && ch[i] < 58)
	{
		i++;
	}
	ch[i] = '\0';
}

/*=======================COPY=============================*/
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
	check(t2);
	return t2;
	
}

/*=======================REVERSE=============================*/
unsigned char* reverse(unsigned char* t1)
{
	int i;
	check(t1);
	unsigned char *t2 = (unsigned char*)malloc(sizeof(unsigned char)*lenstr(t1));
	t2[lenstr(t1)] = '\0';
	
	i = 0;
	while(i < lenstr(t1))
	{
		t2[lenstr(t1)-1 -i] = t1[i];
		i++;
	}
	t2[i] = '\0';
	check(t2);
	return t2;
}

/*=======================OUTPUT=============================*/
void output(unsigned char *t1, int *s)
{
	if(*s == '-')
		printf("%c",'-');
	int i = 0;
	while(t1[i])
	{

		printf("%c", t1[i]);
		i++;
	}
	printf("\n");
	
}

/*=======================CUTZERO=============================*/
unsigned char* cutzero(unsigned char *t1)
{
	while(t1[lenstr(t1)-1] == '0')
	{
		if(lenstr(t1) == 1 && t1[0] == '0') return t1;
		t1[lenstr(t1)-1] = '\0';
	}
	check(t1);
	return  t1;
}

/*=======================LENSTR=============================*/
int lenstr(unsigned char *t1)
{
	int i = 0;
	while(t1[i])
		i++;

	return i;
}





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
	check(t2);
	return t2;

}

unsigned char* leveldown(unsigned char *t1)
{
	unsigned char *t2 = (unsigned char*)malloc(sizeof(unsigned char)*lenstr(t1));
	int i = 0;
	while(i < lenstr(t1))
	{
		t2[i] = t1[i+1];
		i++;
	}
	check(t2);
	return t2;
}





/*-----------_BINARY-----------------*/
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

void output_bin(char *fileName, unsigned char *t1)
{
	FILE *f = fopen(fileName,"wb");
	fwrite(t1,sizeof(unsigned char),lenstr(t1),f);
	fclose(f);
}
