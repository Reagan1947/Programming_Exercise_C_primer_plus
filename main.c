//Float Type for calculate
//Power by Reaganlee
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double calculate(double before,double after,char symblor_1);
double f_result(double *number_result,char *character_find,int length);

int main(void)
{
    char formula[100];
    char number_find[100];
    char character_find[100];
    double number_result[100];
    double result;
    int character_find_flag=0;
    int number_find_flag=0;
    int number_result_flag=0;
    int add_tag=0;
    int tag=0;
    int length=0;
    int character_tag=1;
    int length_2;
    int t=0;

    printf("Please enter.\n");
    scanf("%s",formula);
    length=strlen(formula);
    for(;character_find_flag<=length;character_find_flag++) {
        if ((formula[character_find_flag] == '+') || (formula[character_find_flag] =='-') || (formula[character_find_flag] =='*') ||
            (formula[character_find_flag] == '/') || (character_find_flag==length)){
            character_find[character_tag]=formula[character_find_flag]; t++;
            character_tag=character_tag+2;
            for(;number_find_flag<character_find_flag;number_find_flag++)
            {
                tag=1;
                number_find[add_tag]=formula[number_find_flag];
                add_tag++;
            }
            if(tag==1)
            {
                add_tag=0;
                number_find_flag++;
                character_find_flag=number_find_flag;
                number_result[number_result_flag]=atof(number_find);t++;
                memset(number_find,0,sizeof(number_find));
                number_result_flag=number_result_flag+2;
            }
        }
    }
    length_2=t-1;
    result=f_result(number_result,character_find,length_2);
    printf("The result is %lf",result);

    return 0;
}

double calculate(double before,double after,char symblor_1)
{
    if(symblor_1=='+') return (before*1.0)+(after*1.0);
    if(symblor_1=='-') return (before*1.0)-(after*1.0);
    if(symblor_1=='*') return (before*1.0)*(after*1.0);
    if(symblor_1=='/') return (before*1.0)/(after*1.0);
}

double f_result(double *number_result,char *character_find,int length)
{
    int flag;
    int forever=0;

    if(length==1) {
        return number_result[0];
    }
    for(flag=0;flag<length;flag++)
    {
        if((character_find[flag]=='+')||(character_find[flag]=='-'))
        {
            forever=1;

            return calculate(f_result(number_result,character_find,flag),
                             f_result(number_result+flag+1,character_find+flag+1,length-flag-1),character_find[flag]);
        }
    }
    if(forever==0)
    {
        for(flag=0;flag<length;flag++)
            if((character_find[flag]=='*')||(character_find[flag]=='/'))
            {
                forever=1;

                return calculate(f_result(number_result,character_find,flag),
                                 f_result(number_result+flag+1,character_find+flag+1, length-flag-1),character_find[flag]);
            }
    }
}

