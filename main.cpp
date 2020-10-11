// basic test of the random number generator classes


#include "random.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

int main(void)
{

	uniform x;



	cout << " uniform " << x.get() << endl;
	cout << " uniform " << x.get() << endl;
	cout << " uniform " << x.get() << endl;
	cout << " uniform " << x.get() << endl;
	cout << " uniform " << x.get() << endl;
	cout << " uniform " << x.get() << endl;


	return 1;

}