// random number generator

class uniform {
private:
	long seed;
public:

	uniform(void);	// initialise
	uniform(long);	// initialise
	
	double get(void);

	long get_seed(void);
};



class gauss {
private:
	long seed;
public:

	gauss(void);	// initialise
	gauss(long);	// initialise
	
	double get(void);

	long get_seed(void);
};

