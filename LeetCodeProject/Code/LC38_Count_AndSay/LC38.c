#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * countAndSay(int n){
    if ( n == 0 ) {
        return NULL;
    }
    char * pre = (char *)malloc(sizeof(char) * (5000));
    memset(pre,0,sizeof(char) * (5000));
    char * target = (char *)malloc(sizeof(char) * (5000));
    memset(target,0,sizeof(char) * (5000));
    pre[0] = '1';
    for (int i = 1;i<n;++i) {
        int strLen = strlen(pre);
        if (strLen == 0) {
            break;
        }
        char continuStr = '\0';
        int indexPre = 0;
        int num = 0;
        int indexTar = 0;
        while (pre[indexPre] != '\0') {
            if( continuStr == '\0' ) {
               //表示初始化，碰见第一个元素了,进行记录
               continuStr = pre[indexPre++]; 
               num++;
            }
            else if (continuStr == pre[indexPre]) {
                //相等，那么说明该数字连续出现，num自增
                num++;
                indexPre++;
            }
            else {
                //不相等，那么就是遇到新的元素了，更新continuStr，并计算当前已经弄好的字符串
                // printf("%d,%c\n",num,continuStr);
                target[indexTar++] = num + '0';
                target[indexTar++] = continuStr;
                continuStr = pre[indexPre++]; 
                num = 1;
            }
        }
        // printf("%d,%c\n",num,continuStr);
        //下面此部分是为末尾元素进行控制
        target[indexTar++] = num + '0';
        target[indexTar++] = continuStr;
        strcpy(pre,target);
    }
    free(target);
    return pre;
}
int main (void) {
    int n = 0;
    printf("Please enter number between 0~20: ");
    scanf("%d",&n);
    char * res = countAndSay(n);
    printf("result = %s\n",res);
    free(res);
    system("pause");
    return 0;
}