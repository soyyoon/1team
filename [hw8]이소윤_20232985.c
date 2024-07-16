#include <stdio.h>

// #1
/*double f(double x, double y)
{
	return 1.5 * x + 3.0 * y;
}

int main(void)
{
	double x, y;

	x = 1.0; y = 2.0;
	printf("x=%lf, y=%lf, f(x,y)=%lf\n", x, y, f(x, y));

	x = 2.0; y = 0.0;
	printf("x=%lf, y=%lf, f(x,y)=%lf\n", x, y, f(x, y));

	x = 2.0; y = 1.0;
	printf("x=%lf, y=%lf, f(x,y)=%lf\n", x, y, f(x, y));
	
	return 0;
}*/

// #2
/*double get_bigger(double x, double y)
{
	if (x >= y)
		return x;
	else
		return y;
}

int main(void)
{
	double x, y;
	printf("실수를 입력하시오: ");
	scanf("%lf", &x);
	printf("실수를 입력하시오: ");
	scanf("%lf", &y);
	printf("더 큰 수는 %lf입니다.", get_bigger(x,y));

	return 0;
}*/

// #3
/*void draw_stars(void)
{
	printf("****************************\n");
}

int main(void)
{
	draw_stars();
	printf("Hello World!\n");
	draw_stars();

	return 0;
}*/

// #4
/*int get_divisor(int n)
{
	printf("%d의 약수: ", n);
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			printf("%d ", i);
	printf("\n");
}

int main(void)
{
	int num;
	printf("어떤 양의 정수의 약수를 구할까요: ");
	scanf("%d", &num);
	get_divisor(num);
	return 0;
}*/

// #5
/*int check_prime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	printf("2 ");
	for (int i = 3; i <= 100; i++)
		if (check_prime(i))
			printf("%d ", i);

	return 0;
}*/

// #6
/*#include <math.h>

int power(int x, int y)
{
	for (int i = 0; i <= y; i++)
	{
		int result = pow(x, i);
		printf("%d ", result);
	}
}

int main(void)
{
	power(3, 10);
	return 0;
}*/

// #7
/*#include <math.h>

double dist_2d(int x1, int y1, int x2, int y2)
{
	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return d;
}

int main(void)
{
	int x1, y1, x2, y2;
	printf("첫 번째 점의 좌표를 입력하시오(x, y): ");
	scanf("%d %d", &x1, &y1);

	getchar();

	printf("두 번째 점의 좌표를 입력하시오(x, y): ");
	scanf("%d %d", &x2, &y2);

	printf("두 점 사의 거리는 %lf입니다.", dist_2d(x1, y1, x2, y2));

	return 0;
}*/

// #8
/*#include <math.h>

double quad_eqn(int a, int b, int c)
{
	double x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2;
	double x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2;
	printf("첫 번째 근 = %lf\n", x1);
	printf("두 번째 근 = %lf\n", x2);

}

int main(void)
{
	int a, b, c;
	printf("2차 방정식의 계수를 입력하시오:\n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%d", &b);
	printf("c: ");
	scanf("%d", &c);

	quad_eqn(a, b, c);
	return 0;
}*/

// #9
/*#include <stdlib.h>
#include <time.h>

int win = 0; lose = 0;

void dj(int i)
{
	int user;

	printf("앞(0) 또는 뒤(1)를 선택하시오(종료는 -1):");
	scanf("%d", &user);

	if (user == -1)
		exit(1);

	else if (user == i) {
		printf("사용자가 이겼습니다.\n");
		win++;
	}
	else {
		printf("컴퓨터가 이겼습니다.\n");
		lose++;
	}
}

int main(main) 
{
	int coin;

	srand((unsigned int)time(NULL));

	while (1 == 1) 
	{
		coin = rand() % 2;

		dj(coin);
	}

	return 0;
}*/

// #10
/*#include <stdlib.h>
#include <time.h>

int dice(int*);

int main(void)
{
	static int dice_num[3] = { 0, };

	srand(time(NULL));

	int tries = 3;
	int user_sum = 0;
	int com_sum = 0;

	user_sum = dice(dice_num);
	printf("사용자 주사위 = (%d, %d, %d) = %d\n", dice_num[0], dice_num[1], dice_num[2], user_sum);

	com_sum = dice(dice_num);
	printf("컴퓨터 주사위 = (%d, %d, %d) = %d\n", dice_num[0], dice_num[1], dice_num[2], com_sum);

	if (user_sum > com_sum)
		printf("사용자 승리\n");
	else if (user_sum < com_sum)
		printf("컴퓨터 승리\n");
	else
		printf("비김\n");

	return 0;
}

int dice(int* arrayTmp)
{
	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		arrayTmp[i] = rand() % 6 + 1;
		sum += arrayTmp[i];
	}
	return sum;
}*/


// #11 - (a)
/*void calc(int x, char op, int y)
{
	static int plus = 0, minus = 0, mul = 0, div = 0;

	if (op == '+') {
		printf("덧셈은 총 %d번 호출되었습니다.\n", ++plus);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x + y);
	}
	else if (op == '-') {
		printf("뺄셈은 총 %d번 호출되었습니다.\n", ++minus);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x - y);
	}
	else if (op == '*') {
		printf("곱셈은 총 %d번 호출되었습니다.\n", ++mul);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x * y);
	}
	else if (op == '/') {
		if (y == 0) {
			printf("0으로 나눌 수 없습니다.\n");
			return;
		}
		printf("나눗셈은 총 %d번 호출되었습니다.\n", ++div);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x / y);
	}
}

int main(void)
{
	int x, y;
	char op;
	while (1)
	{
		printf("연산을 입력하시오(종료는 Ctrl+C) : ");
		scanf("%d %c %d", &x, &op, &y);
		calc(x, op, y);
	}
	return 0;
}*/


// #11 - (b)
/*int plus = 0, minus = 0, mul = 0, div = 0;

void calc(int x, char op, int y);

int main(void)
{
	int x, y;
	char op;
	while (1)
	{
		printf("연산을 입력하시오(종료는 Ctrl+C) : ");
		scanf("%d %c %d", &x, &op, &y);
		calc(x, op, y);
	}
	return 0;
}
void calc(int x, char op, int y)
{
	if (op == '+') {
		printf("덧셈은 총 %d번 호출되었습니다.\n", ++plus);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x + y);
	}
	else if (op == '-') {
		printf("뺄셈은 총 %d번 호출되었습니다.\n", ++minus);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x - y);
	}
	else if (op == '*') {
		printf("곱셈은 총 %d번 호출되었습니다.\n", ++mul);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x * y);
	}
	else if (op == '/') {
		printf("나눗셈은 총 %d번 호출되었습니다.\n", ++div);
		printf("연산 결과 %d%c%d=%d\n", x, op, y, x / y);
	}
}*/


// #12 - (a)
/*int save(int amount);
int total = 0;

int main(void)
{
	int input;
	while (1)
	{
		printf("얼마를 저축하시겠습니까?(종료는-1) : ");
		scanf("%d", &input);

		if (input == -1)
			break;
		save(input);
	}
	return 0;
}
int save(int amount)
{
	total += amount;
	printf("지금까지의 저축액은 %d 입니다.\n", total);
}*/


// #12 - (b)
/*int save(int amount);

int main(void)
{
	int input;
	while (1)
	{
		printf("얼마를 저축하시겠습니까?(종료는-1) : ");
		scanf("%d", &input);

		if (input == -1)
			break;
		save(input);
	}
	return 0;
}
int save(int amount)
{
	static int total = 0;
	total += amount;
	printf("지금까지의 저축액은 %d 입니다.\n", total);
}*/


// #12 - (c)
/*int save(int amount);
int draw(int amount);
int sum = 0;

int main(void)
{
	int total;
	int amount;

	while (1)
	{
		printf("얼마를 저축하시겠습니까?(종료는-1) : ");
		scanf("%d", &amount);

		if (amount == -1)
			break;

		total = save(amount);
		printf("지금까지의 저축액은 %d입니다.\n", total);

		printf("얼마를 인출하시겠습니까?(종료는-1) : ");
		scanf("%d", &amount);

		if (amount == -1)
			break;

		total = draw(amount);
		printf("지금까지의 저축액은 %d입니다.\n", total);
	}
	return 0;
}
int save(int amount)
{
	sum += amount;
	return sum;
}
int draw(int amount)
{
	sum -= amount;
	return sum;
}*/


// #13
/*int show_digit(int x);

int main(void)
{
	int n;

	printf("정수를 입력하시오 : ");
	scanf("%d", &n);

	show_digit(n);

	return 0;
}
int show_digit(int x)
{
	if (x > 0) {
		show_digit(x / 10);
		printf("%d  ", x % 10);
	}

}*/


// #14
/*#include <math.h>

int clac(int);

int main(void) {
	int n;

	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	printf("%d\n", calc(n));

	return 0;
}

int calc(int a) {
	if (a != 1)
		return pow(a, 3) + calc(a - 1);
	return 1;
}
*/