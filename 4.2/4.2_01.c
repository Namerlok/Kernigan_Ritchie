#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 10000

struct ATOF_NUMBER{
	double 	number;
	int		i; 
};
typedef struct ATOF_NUMBER atof_number; 

double atof( char line[] );
atof_number atof_mantis( char line[], atof_number variable );
atof_number atof_order( char line[], atof_number variable );
int getline( char line[], int max );

int main(){
	
	freopen( "in.txt", "r", stdin );
	
	double 	number = 0.0;
	char 	line[MAXLINE];
	
	getline( line, MAXLINE );
	
	number = atof( line );
	
	/*
	printf( "output through 'g' = %.5g\n", number );
	printf( "output through 'G' = %.5G\n", number );
	printf( "output through 'e' = %.5e\n", number );
	printf( "output through 'E' = %.5E\n", number );
	printf( "output through 'f' = %.5f\n", number );
	*/
	
	printf( "%.5f\n", number );
	return 0;
}

//---------------------------------------------------------------------------

//Функция для чтения строк
int getline( char line[], int max ){
	
	char 	c 		= 0;
	int 	length 	= 0;
	
	while( (max-- > 0) && ((c = getchar()) != EOF) && (c != '\n') ){
		line[length++] = c;
	}
	if( c == '\n' ){
		line[length++] = c;
	}
	line[length] = '\0';
	
	return length; 
}

//функция для записи десятичного числа
double atof( char line[] ){
	
	atof_number	variable;
	
	variable.number = 0.0;
	variable.i 		= 0;
	
	//пропуск всех пробельных символов
	for( variable.i = 0; isspace( line[variable.i] ); variable.i++ );
	
//	printf( "#	i = %i\n", variable.i );
	
	//запись числа или мантисы числа
	variable = atof_mantis( line, variable );
	/*
	sign_n = ( line[i] == '-' ) ? -1 : +1; 
	if( (line[i] == '+') || (line[i] == '-') )
		i++;
	for( ; isdigit(line[i]); i++ ){
		number = number * 10 + line[i] - '0';
	}
	if( line[i] == '.' )
		i++;
	for( ; isdigit(line[i]); i++ ){
		number = number * 10 + line[i] - '0';
		power *= 10;
	}
	*/
	
	
	//запись порядка (если он есть)
	variable = atof_order( line, variable );
	/*
	if( (line[i] == 'e') || (line[i] == 'E') )
		i++;
	sign_o = ( line[i] == '-' ) ? -1 : +1;
	if( (line[i] == '+') || (line[i] == '-') )
		i++;
	for( ; isdigit(line[i]); i++ ){
		order = order * 10 + line[i];
	}
	*/
	
	//return sign_n * number / power;
	
	return variable.number;
}

//функция для запись числа или мантисы числа
atof_number atof_mantis( char line[], atof_number variable ){
	
	int			sign 	= 0;
	int 		power 	= 1;
	
	sign = ( line[variable.i] == '-' ) ? -1 : +1; 
	
//	printf( "#	sign_number = %i\n", sign );
	
	if( (line[variable.i] == '+') || (line[variable.i] == '-') )
		variable.i++;
	
	for( ; isdigit(line[variable.i]); variable.i++ )
		variable.number = variable.number * 10 + line[variable.i] - '0';
	
//	printf( "#	number = %f\n", variable.number );
	
	if( line[variable.i] == '.' )
		variable.i++;
	
	for( ; isdigit(line[variable.i]); variable.i++ ){
		variable.number = variable.number * 10.0 + line[variable.i] - '0';
		power *= 10;
	}
	
//	printf( "#	power = %i\n", power );
	
	variable.number = sign * variable.number / power; 
	
	return variable;
}


//функция для запись порядка (если он есть)
atof_number atof_order( char line[], atof_number variable ){
	
	int	sign 	= 0;
	int	order 	= 0;
	
	if( (line[variable.i] == 'e') || (line[variable.i] == 'E') )
		variable.i++;
	else
		return variable;
	
	sign = ( line[variable.i] == '-' ) ? -1 : +1;
	
//	printf( "#	sign_order = %i\n", sign );
	
	if( (line[variable.i] == '+') || (line[variable.i] == '-') )
		variable.i++;
	
	for( ; isdigit(line[variable.i]); variable.i++ ){
		order = order * 10 + line[variable.i] - '0';
	}
	
//	printf( "#	order = %i\n", order );
	
	variable.number = variable.number * pow( 10, sign * order );
	
	return variable;
}
