int main(){
	int a = 10;
	double d = 3.14;
	
	int *ap;
	double * dp;
	
	ap = &a;
	dp = &d;
	//a[0]=20;
	printf("%p\n", ap);
	printf("%p\n", dp);
	printf("%d\n", *ap);
	printf("%lf\n", *dp);
	
	return 0;
}
