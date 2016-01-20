    int addDigits(int num) {
	while (num >= 10)
		num = num % 10 + addDigits(num / 10); 
	return num;
}
