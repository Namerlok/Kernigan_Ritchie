#include <stdio.h>
//#include <stdlib.h>

void qsort(int v[], int left, int right);

int ind;

int main(){

	freopen( "in", "r", stdin );

	int n = 0, i = 0;
	scanf( "%i", &n );
	int v[n];

	ind = n;

	for( i = 0; i < n; i++ ){ scanf( "%i", &v[i] ); }
	for( i = 0; i < n; i++ ){ printf( "%i ", v[i] ); }
	printf( "\n" );

	qsort( v, 0, n - 1 );

	for( i = 0; i < n; i++ ){ printf( "%i ", v[i] ); }
	printf( "\n" );

	return 0;
}

/* qsort: сортирует v[left]...v[right] по возрастанию */
void qsort(int v[], int left, int right)
{
	int i = 0, last = 0;
	int j = 0;
//	printf( "#	" );
//        for( i = 0; i < ind; i++ ){ printf( "%i ", v[i] ); }
//        printf( "\n" );

	void swap( int v[], int i, int j );
	if (left >= right){			/* ничего не делается, если */
		return;				/* в массиве менее двух элементов */
	}
//	swap(v, left, (left + right)/2);	/* делящий элемент */
	last = left;				/* переносится в v[0] */

//        for( i = 0; i < ind; i++ ){ printf( "%i ", v[i] ); }
//        printf( "\n" );

	for( i = left + 1; i <= right; i++ ){ 	/* деление на части */

//		for( j = 0; j < ind; j++ ){ printf( "%i ", v[j] ); }
//        		printf( "\n" );

		if (v[i] < v[left]){
			swap( v, ++last, i );
		}
		printf( "i = %i\tlast = %i\t", i, last );
                for( j = 0; j < ind; j++ ){ printf( "%2.i ", v[j] ); }
                        printf( "\n" );

	}

	printf( "\n" );

	swap( v, left, last ); 			/* перезапоминаем делящий элемент */
	qsort( v, left, last - 1 );
	qsort( v, last + 1, right );
}

/* swap: поменять местами v[i] и v[j] */
void swap(int v[], int i, int j)
{
	int temp = 0;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
