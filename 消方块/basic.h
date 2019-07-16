//The header file includes some basic functions,
//making it convenient to achieve some definately goals.
//Powered by Windows 5.1,All rights reserved.
#pragma once
#include <stdio.h>
#include <math.h>
#include <time.h>
void randominit()
{
	time_t timenow;
	timenow=time(NULL);
	srand(timenow);
}
bool judge_if_prime(int t)
{
	if (t<2) return false;
	int i;
	int max=(int)sqrt((double)t);
	for (i=2;i<=max;i++)
	{
		if (t%i==0) return false;
	}
	return true;
}
int quickmod(int p,int q,int u)
{
	int tmp=p;
	int sum=1;
	while (q)
	{
		if (q&1)
		{
			sum*=tmp;
			sum%=u;
		}
		tmp*=tmp;
		tmp%=u;
	}
	return sum;
}
int getdigit(int n)
{
	int sum=0;
	while (n!=0)
	{
		n/=10;
		sum++;
	}
	return sum;
} 
