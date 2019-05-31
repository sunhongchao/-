#include<stdio.h> 
#include <string.h>
#include <stdlib.h>
#define INT_LEN sizeof(int)
struct ss_t{
    int s_id;
    int len;
    char msg[];
};

    
    

int main(void)
{
    int id;
    int len;
    char msg[] = "123456";
    char *buf;
    struct ss_t *st;
    buf = (char *)malloc(sizeof(char) * 100);
    if (buf == NULL) {
        return 1;
    }
    memset(buf, 0, 100);
    id = 65;
    len = 66;
    memcpy(buf, &id, INT_LEN);
    memcpy(buf + INT_LEN, &len, INT_LEN);
    memcpy(buf + 2 * INT_LEN, msg, strlen(msg));  
    st = (struct ss_t *)buf;
    printf("st->s_id %d st->len %d\n", st->s_id, st->len);
    printf("st->msg %s\n", st->msg+1); 
	  
    return 0;
}

