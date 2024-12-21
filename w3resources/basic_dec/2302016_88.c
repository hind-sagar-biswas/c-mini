#include <stdio.h>
int main( void ) {
	unsigned char char1 , char2 , char3 , char4 , char5 , char6 , char7 , char8 ;
	printf("|------------------------------------------------------------------------------------------------------------------|\n" );
	printf("|extended ASCII table - excluding control characters                                                               |\n" );
	printf("|------------------------------------------------------------------------------------------------------------------|\n" );
	printf("|   Ch Dec  Hex  |  Ch Dec  Hex   |   Ch Dec  Hex  |  Ch Dec  Hex  |  Ch Dec  Hex  |  Ch Dec  Hex  |  Ch Dec  Hex  |\n" );
	printf("|----------------|----------------|----------------|---------------|---------------|---------------|---------------|\n" );
	for(int i = 0 ; i< 32; i++) {
		char1 = i;
		char2 = i+32;
		char3 = i+64;
		char4 = i+96;
		char5 = i+128;
		char6 = i+160;
		char7 = i+192;
		char8 = i+224;
		printf( "|   %c %4d  %#x " , char2 , char2 , char2 );
		printf( "|   %c %4d  %#x " , char3 , char3 , char3 );

		if( char4 == 127 ) printf("| %s %4d  %#x |" , "DEL" , char4 , char4);
		else printf("|   %c %4d  %#x |" , char4 , char4 , char4);
		printf("   %c %4d  %#x |   %c %4d  %#x |   %c %4d  %#x |   %c %4d  %#x |\n", 
			char5 , char5 , char5 , char6 , char6 , char6 , char7 , char7 , char7 , char8 , char8 , char8  );
	}
	return 0; // Indicate successful execution of the program
}
