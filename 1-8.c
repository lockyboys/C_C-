/*
	구조체 포인터 
*/
typedef struct score
{
	int kor, eng, mat;
	int total;
}score;

int main()
{
	score s[3]={
				{70,70,70},
				{80,80,80},
				{90,90,90}
			  };
	score * p= s;
	s[0].total = s[0].kor + s[0].eng + s[0].mat;
	(p + 0) -> total = (p + 0) -> kor + (p + 0) -> eng + (p + 0) -> mat;
	(p + 1) -> total = (p + 1) -> kor + (p + 1) -> eng + (p + 1) -> mat;
	(p + 2) -> total = (p + 2) -> kor + (p + 2) -> eng + (p + 2) -> mat;
	
	printf("%d\n",s[0].total);
	printf("%d\n",s[1].total);
	printf("%d",s[2].total);
	
	
	return 0;
}
