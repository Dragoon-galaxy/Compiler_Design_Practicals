%{
#include <stdio.h>
%}

%%
(a|b)*abb$  { printf("Valid string: %s\n", yytext); }
.           { /* Do nothing for invalid strings */ }
%%

int yywrap() {
    return 1;  // Indicates the end of input to Flex
}

int main() {
    yylex();
    return 0;
}