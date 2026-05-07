/*struct student
{
	char name[10];
	char phone[20];
	char gender;
	int score;
	
	
};

int main()
{
	int a;
	struct student s1, s2;
	
	a=5;
	s1.score =100;
	s1.gender ='F';
	
	s2.score = 200;
	s2.gender ='M';
}*/
typedef struct score
{
	int kor, eng, mat;
	int total;
}score;

int main()
{
	score sco={70,80,90};
	score * p= &sco;
	//sco.total = sco.kor + sco.eng + sco.mat;
	p-> total = p -> kor + p -> eng + p -> mat;
	
	printf("%d",(sco.total));
	
	return 0;
}
