int power(int base, int n) {
	if(n = 1) {
		return base;
	}

	return(base * power(base, n - 1));
}