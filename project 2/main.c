#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct add{
    char name[30];
    char num[30];
} Address;

int main()
{
    int item,count=0, max=10,exept=100;
    Address *per[max];
    FILE * fp = fopen("./dial.txt", "r+");
    
    if(fp == NULL)
        fp=fopen("./dial.txt", "w+"); //파일이 없다면 생성하기
    
    while(feof(fp) == 0) //카운팅
    {
        char searN[30],searM[30];
        per[count]=(Address*)malloc(sizeof(Address));
        fscanf(fp, "%s", searN);
        strcpy(per[count]->name, searN);
        //printf("%s\n", searN);
        
        fscanf(fp, "%s", searM);
        // printf("%s\n", searM);
        strcpy(per[count]->num, searM);
        
        if(strcmp(searN, searM) != 0)
            count ++;
        if(strcmp(per[count-2]->name, per[count-1]->name)==0)
            count--;
        
    }

    //printf("%d \n\n", count);
    
    fclose(fp);
    
    
    while(1)
    {
        printf("**** MENU ****\n");
        printf("1. insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print All\n");
        printf("5. Exit\n");
        printf("Choose the item: ");
        scanf("%d", &item);
         while(getchar() != '\n');
        
        switch (item) {
            case 1: //입력
                per[count]=(Address*)malloc(sizeof(Address));
                printf("[Insert]\n");
                printf("Input Name: ");
                scanf("%s", per[count]->name);
                
                
                printf("Input Tel Number: ");
                scanf("%s", per[count]->num);
                printf("\n\t\t\tData Inserted\n\n");
                count++;
                break;
            case 2: //지우기
                printf("[Delete]\n");
                char sear[30];
                printf("Input Name to Delete: ");
                scanf("%s", sear);
                int found=0;
                for(int i=0; i<count; i++)
                {
                    if(strcmp(sear, per[i]->name) == 0)
                    {
                        //free(per[i]);
                        printf("%s is Deleted\n\n", sear);
                        found++;
                        exept=i;
                    }
                    
                }
                if(found == 0)
                    printf("No data\n\n");
                break;
                
                
            case 3:
                printf("[Search]\n");
                char searc[30];
                printf("Input name to search: ");
                scanf("%s", searc);
                for(int i=0; i<count; i++)
                {
                    if(strcmp(searc, per[i]->name) == 0)
                        printf("%s`s Tel Number is %s\n\n", searc, per[i]->num);
                }
                break;
                
            case 4:
                printf("[Print All Data]\n");
                for(int i=0; i<count; i++)
                {
                    if(i != exept)
                        printf("Name: %s, Tel: %s\n\n", per[i]->name, per[i]->num);
                }
                break;
                
            case 5:
                printf("[Exit]\n");
                fp=fopen("/Users/Oliver/Desktop/dial.txt", "w");
                for(int i=0; i<count; i++){
                    if(i != exept)
                    {
                        fprintf(fp, "%s ", per[i]->name);
                        fprintf(fp, "%s ", per[i]->num);
                    }
                }
                return 0;
                break;
        }
        
    
                      }
}


