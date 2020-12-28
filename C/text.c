#include <stdio.h>
#include <stdlib.h>
//  void writeExcel()
//  {
    //  char chy[4] = {'x', 'a', 'h', 'w'};
    //  int data[4] = {1, 3, 6, 9};
    //  int i;
    //  FILE *fp = NULL;
    //  fp = fopen("./test.csv", "w++");
    //  for (i = 0; i < 4; i++)
        //  fprintf(fp, "%c,%d\n", chy[i], data[i]);
    //  fclose(fp);
//  }
int text()
{
    int a = 3, b = 4, c = 2;
    if ((a + b) > c * 2 && b != 5 || !(1/2))
        return 3;
    else
        
        return 0;
        
}

void text1()
{
    int x =1 , a=0, b =0;
    switch(x)
    {
        case 0 : b++;
        case 1 : a++;
        case 2 : a++;b++;
    }

    printf("a = %d, b= %d\n",a,b);
}
void fun(char s[], int num)
{
    char temp;
    for (int i = 1; i < num-2; i++)
        for(int j = num-2; j > i ;j--)
        {
            if (s[j] > s[j-1])
            {
                temp = s[j];
                s[j] = s[j-1];
                s[j-1] = temp;
            }
        }
}

void main()
{
    char s[10] = "CEAedca";
    fun(s, 7);
    printf("%s", s);
}