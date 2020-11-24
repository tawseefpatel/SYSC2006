#include <stdio.h>
#include <stdlib.h>

/* main: generate some simple output */

int main(void)
{
	printf("Hello World!\n"); 
	printf("C programming is fun!\n");
	return EXIT_SUCCESS;
}
/* 
a)
D:\c\Lab 1\hello\main.c(12): error #2001: Syntax error: expected '}' but found 'end of input'.
*** Error code: 1 *** 


b)
D:\c\Lab 1\hello\main.c(8): error #2001: Syntax error: expected ';' but found 'printf'.
D:\c\Lab 1\hello\main.c(8): warning #2099: Missing type specifier; assuming 'int'.
D:\c\Lab 1\hello\main.c(8): error #2001: Syntax error: expected ')' but found 'string constant'.
D:\c\Lab 1\hello\main.c(8): error #2120: Redeclaration of 'printf', previously declared at C:\Program Files\PellesC\Include\stdio.h(140); expected 'int function(const char * restrict, ...)' but found 'int function()'.
D:\c\Lab 1\hello\main.c(8): error #2001: Syntax error: expected ';' but found ')'.
D:\c\Lab 1\hello\main.c(9): warning #2099: Missing type specifier; assuming 'int'.
D:\c\Lab 1\hello\main.c(9): error #2001: Syntax error: expected ')' but found 'string constant'.
D:\c\Lab 1\hello\main.c(9): error #2001: Syntax error: expected ';' but found ')'.
D:\c\Lab 1\hello\main.c(10): error #2156: Unrecognized declaration.
D:\c\Lab 1\hello\main.c(10): error #2156: Unrecognized declaration.
D:\c\Lab 1\hello\main.c(11): error #2156: Unrecognized declaration.
*** Error code: 1 ***


c)
D:\c\Lab 1\hello\main.c(6): warning #2099: Missing type specifier; assuming 'int'.
 
d)
POLINK: error: Unresolved external symbol 'main'.
POLINK: fatal error: 1 unresolved external(s).
*** Error code: 1 ***

e)
POLINK: error: Unresolved external symbol 'main'.
POLINK: fatal error: 1 unresolved external(s).
*** Error code: 1 ***

f)
POLINK: error: Unresolved external symbol 'pintf'.
POLINK: fatal error: 1 unresolved external(s).
*** Error code: 1 ***
*/
