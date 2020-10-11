#include <iostream>
using namespace std;

#include "random.h"

extern "C" {

#include <stdlib.h>
}


#define  a 16807
#define  m 2147483647
#define  q 127773
#define  r 2836
#define  rm 2147483647.0
#define  scale 1.414213562 /* 12/N where N = 6 */


/*
  This procedure generates a random number with a uniform
distribution on the interval (0,1).  The method is based on Lehmer's
version of the linear congruence method.

See Stephen K Park and Keith W Miller

  "Random number generators: good ones are hard to find."

Comm. of the ACM, October 1988, pp 1192-1201

*/
double uniform::get(void)
{
	register long hi, lo, test;
	register double u;
/*
Code...
*/
	hi = seed/q;
	lo = seed - q*hi;

	test = a*lo - r*hi;

	if( test > 0)
	  seed = test;
	else
	  seed = test + m;

	u = seed/rm;

	return(u);
}

// Constructor
uniform::uniform(void)
{

	  seed = 1;

}

uniform::uniform(long initialseed)
{
	if( initialseed == 0 )
	{
		cerr << "Illegal seed" << '\n';
		exit(EXIT_FAILURE);
	}
	else
	  seed = initialseed;

}

long uniform::get_seed(void)
{
  return (seed);
}





/*

Description

Generates a normally distributed random number with mean 0 and
standard deviation 1.

The method is to add N U(0,1) random numbers together.

The mean of such a combination is N/2; the variance is N/12.

In the code N=6.  The function uniform produces the U(0,1)
random numbers.  The random number generator should be
initialised with by the call

	FORTRAN: call Initialise Random (seed)
              C:  InitialiseRandom(seed)

where seed, of type long, is the user spacified seed.

*/

double gauss::get(void)

{
	uniform	u;
	register double g;
/*
Code...
*/
	g = u.get();
	g += u.get();
	g += u.get();
	g += u.get();
	g += u.get();
	g += u.get();

	g -= 3.0;

	g = scale * g;

	return(g);

}

gauss::gauss(long initialseed)
{

	if( initialseed == 0 )
	{
		cerr << "Illegal seed" << '\n';
		exit(EXIT_FAILURE);
	}
	else
	  seed = initialseed;

}

gauss::gauss(void)
{

	  seed = 1;

}


long gauss::get_seed(void)
{
	return seed;
}