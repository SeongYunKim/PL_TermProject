%{
#include <stdio.h>
#include "test.tab.h"
void showError();
%}


//Regular Expression
alphabet		[a-zA-Z]
digit			[0-9]
integer			{digit}+


//Token Specifications
%%
.					{showError(); return(OTHER);}

%%


//C Functions
void showError(){
	printf("Input Error");
}
