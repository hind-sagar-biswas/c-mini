#include <stdio.h>
int main() {
	int size;
	printf( "Size [0 to 10]: " );
	scanf( "%d", &size );
	if(size < 1 || size > 10) return printf("Size should be in the range 1 to 10\n");
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1) printf(" #");
			else printf("  ");
		}
		printf("\n");
	}
	return 0;
}
