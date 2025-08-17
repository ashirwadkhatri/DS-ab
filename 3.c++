#include <stdio.h>

int main() {
	int i;
	int arr[5] = {1};
	for (i = 0; i < 5; i++)
		printf("%d", arr[i]);
	return 0;
}
//output: 10000 (since only 1 value was initialized i.e arr[0] so rest of the values are 0)

