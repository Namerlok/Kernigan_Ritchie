#include "Header.h"

//поиск всех строк содержащих шаблоны
int main(){

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	char	line[MAXLINE];
	char	pattern[] = "if";
	int 	length = 0;
	
//	printf("#	pattern[] = %s\n",pattern);
	
	while((length = getline_(line, MAXLINE)) > 0){
		if(strcheck_(line, pattern, length) >= 0){
			printf("%s",line);
		}
	}

	return 0;
}

//------------------------------------------------------------------------------

//Функция для чтения строк
int getline_(char line[], int max){
	
	char 	c 		= 0;
	int 	length 	= 0;
	
	while( (max-- > 0) && ((c = getchar()) != EOF) && (c != '\n') ){
		line[length++] = c;
	}
	if(c == '\n'){
		line[length++] = c;
	}
	line[length] = '\0';
	
	return length; 
}

/*
//Функция для проверши строки на наличие шаблонности 
int strcheck_(char line[], char pattern[], int length){

	int i 		= 0;
	int j 		= 0;
	int	flag	= -1;
	int l_pat	= strlen(pattern);
	
//	printf("#	length = %i, l_pat = %i \n", length, l_pat);

	for(i = 0, flag = -1; i < length, flag < 0; i++){
		for(j = 0; j < l_pat; j++){
			if( line[i+j] != pattern[j] )
				break;
			if( j + 1 == l_pat )
				flag = 1;
		}
	}
	
	return flag;
}
*/

//Функция для проверши строки на наличие шаблонности 
int strcheck_(char line[], char pattern[], int length){

	int i 	=  0;
	int j 	=  0;
	int k 	=  0;
		
//	printf("#	length = %i, l_pat = %i \n", length, l_pat);

	for(i = 0; line[i] != '\0'; i++){
		for(j = i, k = 0; pattern[k] != '\0', 
			line[j] != '\0', line[j] == pattern[k]; j++, k++);
							
			if(k > 0 && pattern[k] == '\0'){
				return i; 
			}
	}
	
	return -1;
}