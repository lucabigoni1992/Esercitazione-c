#include <iostream>
using namespace std;

int main() {
	int n = 5;

	do {
		n += 5;
		printf("%d\n", n );
	} while (n < 100);

	return 0;
}