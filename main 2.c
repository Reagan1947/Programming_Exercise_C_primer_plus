#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void) {

    int character_find_flag;
    int digit_flag;
    int digit_double_flag = 0;
    double digit_double[100];
    size_t length_formula;
    char formula[100];
    char digit_cha[100];
    char character_find[100];
    int deal_tag=0;
    int judge = 0;
    int length_re;

    printf("Please enter\n");
    scanf("%s", formula);
    length_formula = strlen(formula);
    for (character_find_flag = 0; character_find_flag < length_formula; character_find_flag++) {
        digit_flag = 0;
        while ((isdigit(formula[character_find_flag]) == 1) || (formula[character_find_flag] == '.')) {
            digit_cha[digit_flag] = formula[character_find_flag];
            character_find_flag++;
            digit_flag++;
        }
        digit_double[digit_double_flag] = atof(digit_cha);
        memset(digit_cha, 0, sizeof(digit_cha));
        digit_double_flag++;
        character_find[digit_double_flag++] = formula[character_find_flag];
    }

    length_re = digit_double_flag;
    for(deal_tag;deal_tag<character_find_flag;deal_tag++){
        if(character_find[deal_tag]=='*')
        {
            digit_double[deal_tag+1]=digit_double[deal_tag - 1] * digit_double[deal_tag + 1];
            judge = 1;
            length_re -= 2;
        }
        if(character_find[deal_tag]=='/')
        {
            digit_double[deal_tag+1]=digit_double[deal_tag - 1] / digit_double[deal_tag + 1];
            judge = 1;
            length_re -= 2;
        }
        if(judge == 1)
        {
            for(int tag_move=deal_tag;tag_move<character_find_flag;tag_move++) {
                digit_double[tag_move - 1] = digit_double[tag_move + 1];
                character_find[tag_move - 1] = character_find[tag_move + 1];
                judge = 0;
            }
        }
    }

    for(int low_cal=0;low_cal<length_re;low_cal++)
    {
        if(character_find[low_cal]=='+')
        {
            digit_double[low_cal+1]=digit_double[low_cal - 1] + digit_double[low_cal + 1];
        }
        if(character_find[low_cal]=='-')
        {
            digit_double[low_cal+1]=digit_double[low_cal - 1] - digit_double[low_cal + 1];
        }
    }

    printf("The result is %lf\n",digit_double[length_re-2]);
    for (int tag = 0; tag < character_find_flag; tag++) {
        printf("%lf\n", digit_double[tag]);
    }
    for (int tag = 0; tag < character_find_flag; tag++) {
        printf("%c\n", character_find[tag]);
    }
    return 0;
}