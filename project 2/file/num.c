#include <stdio.h>

typedef struct {
    char * name;
    char * auth;
    int page;
} book;

int main()
{
    book b[3];
    
    for(int i=0; i<3; i++)
    {
        printf("저자: ");
        scanf("%s", b[i].name);
        printf("제목: ");
        scanf("%s", b[i].auth);
        printf("페이지 수: ");
        scanf("%d", &b[i].page);
    }
    
    for(int i=0; i<3; i++)
    {
        printf("저자: ");
        printf("%s", b[i].name);
        printf("제목: ");
        printf("%s", b[i].auth);
        printf("페이지 수: ");
        printf("%d", b[i].page);
    }

}