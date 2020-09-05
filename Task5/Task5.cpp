#include <iostream>
using namespace std;
int main()
{
	const char* star = "\x1B[31m * \033[0m";
	printf("   1   2   3   4   5   6  \n");
	printf("  --- --- --- --- --- --- \n");
	printf("A:%s:%s:%s:%s:%s:%s : A\n", star, star, star, star, star, star);
	printf("  --- --- --- --- --- --- \n");
	printf("B:%s:%s:%s:%s:%s:%s : B\n", star, star, star, star, star, star);
	printf("  --- --- --- --- --- --- \n");
	printf("C:%s:%s:%s:%s:%s:%s : C\n", star, star, star, star, star, star);
	printf("  --- --- --- --- --- --- \n");
	printf("D:%s:%s:%s:%s:%s:%s : D\n", star, star, star, star, star, star);
	printf("  --- --- --- --- --- --- \n");
	printf("   1   2   3   4   5   6  \n");
	system("pause");
}
