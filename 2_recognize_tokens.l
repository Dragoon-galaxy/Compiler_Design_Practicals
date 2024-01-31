%option noyywrap
%{
#include<stdio.h>
%}

digit       [0-9]
hex_digit    [0-9a-fA-F]
alpha        [a-zA-Z]

%%
{alpha}({alpha}|{digit})*    { printf("Valid Identifier: %s\n", yytext); }
0[0-7]*                       { printf("Octal constant: %s\n", yytext); }
0[xX]{hex_digit}+             { printf("Hexadecimal constant: %s\n", yytext); }
{digit}+"."{digit}+           { printf("Floating point constant: %s\n", yytext); }
{digit}+                       { printf("Integer constant: %s\n", yytext); }
{digit}+"."{digit}+[eE][+-]?{digit}+ { printf("Exponential constant: %s\n", yytext); }
.                             { /* Ignore any other characters */ }

%%
int main(){
    yylex();
    return 0;
}
