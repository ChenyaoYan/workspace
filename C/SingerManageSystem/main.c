/***************************************
* @file  
* @brief: 歌手管理系统
* @since  日期
* Function List:  省略
* Related Files:
* Maintained by: 
* Copyright . All Rights Reserved.
* CONFIDENTIALITY AND LIMITED USE
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define N 100
///< 结构体定义
/**
 * @brief 结构体保存与歌手相关信息
 */
typedef struct Singer
{
    char number[10];
    char name[20];

    int grades;
} SINGER;

///< 全局变量定义

unsigned int Count = 0; /**用在数组中表示保存歌手数量*/
SINGER Singers[N];      /**存放歌手数据*/

/***************************************
* @Function     : menu()
* @Description  : 展示主菜单
* @Calls        : 
* @Called By    : main()
* @Input        : 
* @Output       : 
* @Return       : 功能编号
* @Others       : 
* @Modify		：
***************************************/
int menu()
{
    int select;
    printf("***************Singer Management Menu*************\n");
    printf("                  --1,Add Singer                --\n");
    printf("                  --2,Search Singer             --\n");
    printf("                  --3,Delete Singer             --\n");
    printf("                  --4,Show All Singer           --\n");
    printf("                  --0,Exit                      --\n");
    printf("**************************************************\n\n");
    printf("Please select the function number:(0~4)");
    scanf("%d", &select);
    system("cls");
    if (select != 0 && select != 1 && select != 2 && select != 3 && select != 4)
    {
        do
        {
            printf("Please select the function number (0-4)");
            scanf("%d", &select);
            if (select == 0 || select == 1 || select == 2 || select == 3 || select == 4)
                break;
        } while (1);
    }
    return select;
}

/***************************************
* @Function     : DisplayTableHead()
* @Description  : 显示表头
* @Calls        : 
* @Called By    : main()
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void DisplayTableHead(void)
{
    printf("NUMBER        NAME         GRADES \n");
}
/***************************************
* @Function     : DisplayRecord(SINGER *singer)
* @Description  : 显示一条数据
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void DisplayRecord(SINGER *singer)
{
    printf("%-10s    %s     %d\n", singer->number, singer->name, singer->grades);
}

/***************************************
* @Function     : 
* @Description  : 找到对应信息的歌手
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/

SINGER *SearchPrimarySinger(const char *data, int sing)
{
    int i = 0;
    if (sing == 0)
    {
        for (i; i < Count; i++)
        {
            if (strcmp(Singers[i].number, data) == 0)
                break;
        }
    }
    else
    {
        for (i; i < Count; i++)
        {
            if (strcmp(Singers[i].name, data) == 0)
                break;
        }
    }
    if (i == Count)
        return NULL;
    else
        return Singers + i;
}

/***************************************
* @Function     : Save()
* @Description  : 
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void Save()
{
    FILE *fp;
    int i = 0;
    fp = fopen("Singers.txt", "w");
    if (fp == NULL)
    {
        printf("\n=====>Opening the file failed!\n");
        system("PAUSE");
        return;
    }
    for (i = 0; i < Count; i++)
    {
        if (fwrite(&Singers[i], sizeof(SINGER), 1, fp) == 1)
            continue;
        else
            break;
    }
    if (i > 0)
    {

        system("cls");
        printf("=====>Data has been saved in total: %d bar\n", Count);
        printf("Now return to the main menu...\n");
        system("PAUSE");
    }
    else
    {
        system("cls");
        printf("无新纪录被保存！\n");
        printf("现在返回主菜单...");
        system("PAUSE");
    }
    fclose(fp); /*关闭此文件*/
}
/***************************************
* @Function     : AddSinger()
* @Description  : 
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void AddSinger()
{
    int i, select;
    if(Count == N)
    {
        printf("The message is full and you are returning to the main menu...");
        Sleep(2000);
        return;
    }
    else
    {
        do
        {
            system("cls");
            printf("------------- enter the %d singer information-----------\n", Count + 1);
            printf("Please input singer name : \n");
            scanf("%s", Singers[Count].name);
            // gets_s(Singers[Count].name, 20);
            printf("Please input singer number : \n");
            // gets_s(Singers[Count].number, 15);
            scanf("%s", Singers[Count].number);
            printf("Please input singer grades : \n");
            scanf("%d", &Singers[Count].grades);
            Count++;
            if (Count == N)
            {
                printf("The message is full and you are returning to the main menu...");
                Sleep(2000);
                break;
            }
            printf("\nDo you want to continue entering information? \nEnter 1 to continue, enter 0 to exit: ");
            scanf("%d", &select);
            for (; select != 0 && select != 1;)
            {
                printf("\nDo you want to continue entering information?\nEnter 1 to continue, enter 0 to exit！\n");
                scanf("%d", &select);
            }
        } while (select == 1);
        Save();

    }
    
}

/***************************************
* @Function     : SearchSinger()
* @Description  : 
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void SearchSinger()
{
}

/***************************************
* @Function     : DeleteSinger()
* @Description  : 
* @Calls        : 
* @Called By    : main()
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void DeleteSinger()
{
}

/***************************************
* @Function     : ShowAllSinger()
* @Description  : cCNT * 100
* @Calls        : 
* @Called By    : 
* @Input        : cCNT
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void ShowAllSinger()
{
}

/***************************************
* @Function     : main()
* @Description  : 
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
int main()
{
    int select;
    FILE *fp;
    fp = fopen("Singers.txt", "a++");
    if (fp == NULL)
    {
        printf("Not found, creating a folder....");
        Sleep(2000);
    }
    else
    {
        while (!feof(fp))
            if (fread(&Singers[Count], sizeof(SINGER), 1, fp) == 1)
                Count++;
        fclose(fp);
        printf("The file you opened already has a record of %d. \n\nPlease return to the main menu.......\n", Count);
        system("PAUSE");
    }
    do
    {
        system("cls");
        select = menu();
        if (select == 1)
            AddSinger();
        else if (select == 2)
            SearchSinger();
        else if (select == 3)
            DeleteSinger();
        else if (select == 4)
            ShowAllSinger();
        else
            break;
    } while (1);
    system("cls");
    printf("********************************Thank you for using it**************************************\n");
    printf("Closing the program........\n");
    Sleep(2000);
    system("cls");
    return 0;
}
