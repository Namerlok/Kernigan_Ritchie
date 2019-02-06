#include "Header.h"

// КАЛЬКУЛЯТОР С ОБРАТНОЙ ПОЛЬСКОЙ ЗАПИСЬЮ 
int main (){
	
	freopen ( "in.txt", "r", stdin );
	freopen ( "out.txt", "w", stdout );
	
	int 	type = 0;
	char	line [MAXOP];
	double	op2 = 0.0;
	
	while ( ( type = getop(line) ) != EOF ){
		switch (type){
		case NUMBER:
			push( op2 = atof(line) );
//			printf ( "#	%.6f\n", op2 );
			break;
			
		case '+':
			push( ( op2 = pop() + pop() ) );
//			printf ( "#	%.6f\n", op2 );
			break;
			
		case '-':
			op2 = pop();
			push( op2 = pop() - op2 ); 
//			printf ( "#	%.6f\n", op2 );
			break;
			
		case '*':
			push( op2 = pop() * pop() );
//			printf ( "#	%.6f\n", op2 );
			break;
			
		case '/':
			op2 = pop ();
			if ( op2 == 0.0 )
				printf ( "ERROR_001: деление на нуль\n" );
			else
				push( op2 =  pop() / op2 );
//			printf ( "#	%.6f\n", op2 );
			break;
			
		case '%':
			op2 = pop();
			if ( op2 == 0.0 )
				printf ( "ERROR_006: деление на нуль\n" );
			else 
//				if ( op2 > 0 )
				push( fmod(pop(), op2) );
//			else
//				push( - 1.0 * fmod(pop(), fabs(op2)) );
			break;
			
		case '\n':
			printf( "%.6g\n", pop() );
			break;
			
		default:
			printf ( "ERROR_002: неизвестная операция %s\n", line );
			break;
		}
	}
	
	return 0;
}


// ИЗВЛЕКАЕТ СЛЕДУЮЩИЙ ОПЕРАНД ИЛИ ЗНАК ОПЕРАЦИИ
int 	getop ( char line[] ){
	
	int		c = 0;
	int 	j = 0;
	
	// пропуск пробелов
	while ( ( c = line[0] = getch() ) == ' ' || c == '\t' );
	
	line[1] = '\0';
	
	// проверка на знак операции
	if ( !isdigit(c) && c != '.'){
//		printf ( "#	%c\n", c );
		if ( c != '-' ) {
			return c;
		} else if ( !isdigit( c = line[++j] = getch() ) ) {
			ungetch(c);
			line[1] = '\0';
			return '-';
		}
/*
		if ( c == '-' && !isdigit( c = line[++j] = getch() ) ){
			ungetch(c);
			line[1] = '\0';
			return '-';
		}
		else if ( c == '-' && isdigit(c) ) {}
		else{
			return c;
		}
*/
	}
//	printf ( "#	%c\n", c );
	
	while ( isdigit( c = getch() ) || c == '.' ){
		line[++j] = c;
//		printf ( "#	%c\n", c );
	}
//	printf ( "#	%s\n", line );
	
	line[++j] = '\0';
	
	if ( c != EOF )
		ungetch( c );
	
	return NUMBER;
}	

// ВВОД СИМВОЛА (ВОЗМОЖНО ВОЗВРАЩЕННОГО В ПОТОК)
int 	getch ( void ){
	
	return ( index_r > 0 ) ? buf_r [--index_r] : getchar();
}

// ВОЗВРАЩЕНИЕ СИМВОЛА В ПОТОК		
void 	ungetch ( int c ){
	
	if ( index_r >= MAXBUF )
		printf ( "ERROR_003: ungetch: слишком много символов\n" );
	else
		buf_r [index_r++] = c;
}	

// ПОМЕЩАЕТ ЧИСЛО В СТЕК ОПЕРАНДОВ	
void 	push ( double f ){
	
	if ( index_b >= MAXBUF )
		printf ( "ERROR_005: push: слишком много символов\n" );
	else
		buf [index_b++] = f;
}		

// ИЗВЛЕКАЕТ И ВОЗВРАЩАЕТ ВЕРХНЕЕ ЧИСЛО В СТЕК ОПЕРАНДОВ
double 	pop ( void ){
	
	if (index_b >= 0 )
		return buf [--index_b];
	else{
		printf ( "ERROR_004: стек пуст\n" );
		return 0.0;
	}
}			
