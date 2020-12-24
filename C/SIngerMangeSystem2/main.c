/***************************************
* @file  
* @brief: 歌手比赛系统
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
    int ranking;//排名
    char number[10];//编号
    char name[20];//姓名
    char class[15];//班级
    char snum[10];//学号
    int grades[10];//十个裁判的打分
    int endgrades;//最终成绩
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
    printf("               --1,Add singer data              --\n");//添加歌手信息
    printf("               --2,Scoring by judges            --\n");//裁判打分
    printf("               --3,Score query                  --\n");//查询一个歌手信息
    printf("               --4,Score ranking                --\n");//显示所有
    printf("               --5,Delete singer data           --\n");//删除一个歌手信息
    printf("               --6,Save                         --\n");//保存
    printf("               --0,Exit                         --\n");//返回
    printf("**************************************************\n\n");
    printf("Please select the function number:(0~6)");//提示用户输入对应功能
    scanf("%d", &select);//输入
    system("cls");//清屏

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
void DisplayTableHead()
{
    printf("\nRANKING    NUMBER      NAME      CLASS     SCHOOLNUM     ENDGRADES\n");//打印表头信息
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
void DisplayRecord(int i)
{
    printf("%5d    %5s    %10s     %5s       %5s     %5d\n", Singers[i].ranking, Singers[i].number, Singers[i].name, Singers[i].class, Singers[i].snum, Singers[i].endgrades);//输出一条歌手信息
}

/***************************************
* @Function     : Data processing.
* @Description  : 整理所有歌手信息，写入排名，并且排序
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void DataProcess()
{
    int i, t = 0;
    SINGER temp;
    for (i = 1; i < Count; i++)/**将歌手信息按成绩排名*/
        for (int j = 0; j < (Count - i); j++)
            if (Singers[j].endgrades < Singers[j + 1].endgrades)
            {
                temp = Singers[j + 1];
                Singers[j + 1] = Singers[j];
                Singers[j] = temp;
            }
    for (int j = 0; j < Count; j++)/**写入歌手对应排名*/
    {
        Singers[j].ranking = j + 1;
    }
}

/***************************************
* @Function     : Save()
* @Description  : 将歌手信息保存文件
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
    char name[20];
    char full_pass[30];
    DataProcess();
    printf("Please enter the name of the file you want to save : ");//提示用户输入保存文件名称
    scanf("%s", name);
    sprintf(full_pass, "./%s.csv", name);//实现字符串拼接得到完整路径
    fp = fopen(full_pass, "w");
    if (fp == NULL)
    {
        printf("\n=====>Opening the file failed!\n");
        system("PAUSE");
        return;
    }
    for (i = 0; i < Count; i++)
    {
        fprintf(fp, "%d,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", Singers[i].ranking, Singers[i].number, Singers[i].name, Singers[i].class, Singers[i].snum,
                Singers[i].endgrades, Singers[i].grades[0], Singers[i].grades[1], Singers[i].grades[2], Singers[i].grades[3], Singers[i].grades[4], Singers[i].grades[5],
                Singers[i].grades[6], Singers[i].grades[7], Singers[i].grades[8], Singers[i].grades[9]);
    }

    system("cls");
    printf("=====>Data has been saved in total: %d bar\n", Count);
    printf("Now return to the main menu...\n");
    system("PAUSE");

    fclose(fp); /*关闭此文件*/
}

/***************************************
* @Function     : SearchSinger()
* @Description  : 查找一个歌手信息，并返回对应编号
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
int SearchSinger()
{
    int i = 0;
    int sign;
    char data[20];
    printf("Please enter how to find action object?\n 1, find by name      2,find by number  ");//提示用户输入是按姓名还是编号查找
    scanf("%d", &sign);
    printf("Please input data: ");
    scanf("%s", data);
    if (sign == 2)//输入信息与编号匹配
    {
        for (i; i < Count; i++)
        {
            if (strcmp(Singers[i].number, data) == 0)
                break;
        }
    }
    else
    {
        for (i; i < Count; i++)//将输入的数据与姓名比较
        {
            if (strcmp(Singers[i].name, data) == 0)
                break;
        }
    }
    if (i == Count)/**判断是有多少条数据写入*/
    {
        printf("The query singer was not found!\n");
        system("PAUSE");
        system("cls");
        return -1;
    }
    else
    {
        DisplayTableHead();
        DisplayRecord(i);
        system("PAUSE");
        system("cls");
        return i;
    }
}

/***************************************
* @Function     : Grade()
* @Description  : 裁判打分函数
* @Calls        : 
* @Called By    : 
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void Grade()
{
    int i, sign, t = 1, r = 0, min = 0, max = 0, temp = 0, sum = 0;
    system("cls");
    i = SearchSinger();
    if (i != -1)
    {
        printf("Whether to continue to score? 1,YES   0,NO\n");
        scanf("%d", &sign);
        while (sign != 1 && sign != 0)//判断是否正确输入，如果不正确，提示重新输入
        {
            printf("Your input is incorrect!please enter it again.\n");
            scanf("%d", &sign);
        }
        if (sign == 1)
        {
            for (int j = 0; j < 10; j++)//分别输入十位裁判打分,并得到总成绩，与最大值最小值
            {
                printf("Please enter the number %d judges' score : ", j + 1);
                scanf("%d", &temp);
                Singers[i].grades[j] = temp;
                sum += temp;
                if (temp > max)
                    max = temp;
                if (temp < min)
                    min = temp;
            }
            Singers[i].endgrades = (sum - max - min) / 8;/**计算平均分*/

            for (int j = 0; j < Count; j++)//得到当前歌手的排名并写入
                if (Singers[i].endgrades < Singers[j].endgrades)
                    t++;
            Singers[i].ranking = t;
            system("cls");
            printf("------------------A new data is added---------------------\n");
            DisplayTableHead();
            DisplayRecord(i);
            system("PAUSE");
        }
    }
}

/***************************************
* @Function     : AddSinger()
* @Description  : 添加歌手信息
* @Calls        : 
* @Called By    : main()
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void AddSinger()
{
    int i, select;
    if (Count == N)//判断数据是否满
    {
        printf("The message is full and you are returning to the main menu...");
        Sleep(2000);
        return;
    }
    else
    {
        do
        {
            system("cls");//输入歌手信息
            printf("------------- enter the %d singer information-----------\n", Count + 1);
            printf("Please input singer name : \n");
            scanf("%s", Singers[Count].name);
            printf("Please input singer number : \n");
            scanf("%s", Singers[Count].number);
            printf("Please input singer class : \n");
            scanf("%s", &Singers[Count].class);
            printf("Please input singer school number : \n");
            scanf("%s", &Singers[Count].snum);
            Count++;
            if (Count == N)
            {
                printf("The message is full and you are returning to the main menu...");
                Sleep(2000);
                break;
            }
            printf("\nDo you want to continue entering information? \nEnter 1 to continue, enter 0 to exit: ");
            scanf("%d", &select);//输入是否继续添加信息
            for (; select != 0 && select != 1;)
            {
                printf("\nDo you want to continue entering information?\nEnter 1 to continue, enter 0 to exit！\n");
                scanf("%d", &select);
            }
        } while (select == 1);
    }
}

/***************************************
* @Function     : DeleteSinger()
* @Description  : 删除一条歌手信息
* @Calls        : SearchSinger()
* @Called By    : main()
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void DeleteSinger()
{
    int i, sign;
    i = SearchSinger();
    if (i != -1)
    {
        printf("Warning! it cannot be recovered after deletion.\n");//提示用户是否继续删除
        printf("Whether to continue? 1,YES   0,NO\n");
        scanf("%d", &sign);
        while (sign != 1 && sign != 0)//规范用户输入
        {
            printf("Your input is incorrect!please enter it again.\n");
            scanf("%d", &sign);
        }
        if (sign == 1)//删除数字元素
        {
            for (int j = i; j < Count - 1; j++)
            {
                Singers[j] = Singers[j + 1];
            }
            Count--;
        }
    }
}

/***************************************
* @Function     : ShowAllSinger()
* @Description  : 打印所有歌手信息
* @Calls        : DataProcess()
* @Called By    : main()
* @Input        : 
* @Output       : 
* @Return       : 
* @Others       : 
* @Modify		：
***************************************/
void ShowAllSinger()
{
    system("cls");
    DataProcess();
    printf("--------------->There are a total of %d records<-----------------", Count);
    DisplayTableHead();
    for (int i = 0; i < Count; i++)//循环打印
        DisplayRecord(i);
    system("PAUSE");
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
    int flag = 1;

    do
    {
        system("cls");
        select = menu();//调用菜单函数
        switch (select)
        {
        case 1:
            AddSinger();//添加歌手信息
            break;
        case 2:
            Grade();//裁判打分
            break;
        case 3:
            SearchSinger();//查找歌手
            break;
        case 4:
            ShowAllSinger();//打印所有歌手信息
            break;
        case 5:
            DeleteSinger();//删除歌手信息
            break;
        case 6:
            Save();//保存成文件
            break;
        case 0:
            flag = 0;//将标志置零结束循环
            break;
        default:
            printf("Please select the function number (0-6)\n");//提示输入有误
            system("PAUSE");
            getchar();
        }

    } while (flag == 1);
    system("cls");
    printf("********************************Thank you for using it**************************************\n");
    printf("Closing the program........\n");
    Sleep(2000);//延迟两秒结束程序
    system("cls");
    return 0;
}
