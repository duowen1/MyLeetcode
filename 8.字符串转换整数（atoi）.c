/*
To do list:没有处理溢出
*/
#include <stdio.h>
#include <limits.h>
char * delspace(char * str){
    char * p=str;
    while(*p==' ') p++;
    return p;
}

int myAtoi(char *str){
    char * newstr=delspace(str);
    if(*newstr!='+'&&*newstr!='-'&&(*newstr<'0'||*newstr>'9')) return 0;
    int negetive_flag=0;
    if(*newstr=='-'){
        negetive_flag=1;
        newstr++;
    }else if(*newstr=='+') newstr++;

    int num=0;
    int overflow_flag=0;
    while(*newstr>='0'&&*newstr<='9'){
        if(INT_MAX/10<num){
            overflow_flag=1;
            break;
        }
        num*=10;
        if(INT_MAX-(*newstr-'0')<num){
            overflow_flag=1;
            break;
        }
        num+=*newstr-'0';
        newstr++;
    }
    
    if(negetive_flag){
        if(overflow_flag) return INT_MIN;
        num*=-1;
    }
    if(overflow_flag) return INT_MAX;
    return num;
}

int main(){
    char * str="42";
    printf("%d",myAtoi(str));
    return 0;
}