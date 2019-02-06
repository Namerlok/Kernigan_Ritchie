#include 	<math.h>
#include 	<stdio.h>
#include	<ctype.h>
#include 	<stdlib.h>

#define 	MAXOP 		100 	// МАКСИМАЛЬНЫЙ РАЗМЕР ЗНАКА ИЛИ ОПЕРАТОРА
#define 	NUMBER 	'0'		// СИГНАЛ,ЧТО ОБНАРУЖЕНО ЧИСЛО
#define 	MAXBUF 	100		// МАКСИМАЛЬНЫЙ РАЗМЕР БУФЕРА buf []

int 	getop ( char line [] );	// ИЗВЛЕКАЕТ СЛЕДУЮЩИЙ ОПЕРАНД ИЛИ ЗНАК ОПЕРАЦИИ
int 	getch ( void );			// ВВОД СИМВОЛА (ВОЗМОЖНО ВОЗВРАЩЕННОГО В ПОТОК)
void 	ungetch ( int c );		// ВОЗВРАЩЕНИЕ СИМВОЛА В ПОТОК
void 	push ( double f );		// ПОМЕЩАЕТ ЧИСЛО В СТЕК ОПЕРАНДОВ
double 	pop ( void );			// ИЗВЛЕКАЕТ И ВОЗВРАЩАЕТ ВЕРХНЕЕ ЧИСЛО В СТЕК ОПЕРАНДОВ

int 	index_b = 0;			// СЧЕТЧИК ДЛЯ БУФЕРА buf []
int 	index_r = 0;			// СЧЕТЧИК БУФЕРА ВОЗРАТА buf_r [] 
char 	buf_r [MAXBUF];			// БУФЕР ВОЗРАТА
double 	buf [MAXBUF];			// БУФЕР ДЛЯ СТЕКА


// ERROR_001-ERROR_006