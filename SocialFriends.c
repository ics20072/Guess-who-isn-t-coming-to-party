#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>

int FindMax(int r,int num,int tab[r]);
void RemoveName(int maxindex,int r,int c,string hatenames[r][c],int pl,string names[r],int index);
void printPavles(int n);

int main()
{
    int num,plhates[30],plhates2[30],j,i,pl=0,k,maxindex,plk=0;
    string names[30],hatenames[30][30];

    printf("Give the probable number of people who can come:");
    num = GetInteger();

    for(i=0;i<num;i++)
    {
        printf("Give the name of the %dst people who might come:",i+1);
        names[i] = GetLine();
        printf("Give the number of the people who hates:");
        plhates2[i] = plhates[i] = GetInteger();
        for(j=0;j<plhates[i];j++)
        {
            printf("Give the %dst name of the people who hates:", j+1); //The names that will be given must exist in the names table
            hatenames[i][j] = GetLine();                               //This means that both namespaces must be entered correctly.
        }
    }
    printPavles(40);
    for(i=0;i<num;i++)
    {
        if(plhates[i]!=0)
            pl++;
    }
    while (pl!=0)
    {
        pl = 0;
        maxindex = FindMax(30,num,plhates);
        k = plhates2[maxindex];
        for(i=0;i<k;i++)
        {
                for(j=0;j<num;j++)
                  {
                    if(strcmp(names[j],hatenames[maxindex][i])==0 && strcmp(hatenames[maxindex][i], "0")!=0)
                      {
                       RemoveName(maxindex,30,30,hatenames,plhates2[j],names,j);
                       strcpy(hatenames[maxindex][i], "0");
                       plhates[j] = plhates[j] - 1;
                       break;
                       }
                  }
        }
        plhates[maxindex] = 0;
        strcpy(names[maxindex], "0");
        for(i=0;i<num;i++)
           {
             if(plhates[i]!=0)
                pl++;
           }
    }
    for(i=0;i<num;i++)
        if (strcmp(names[i], "0")!= 0)
                plk++;
    printf("The maximum he can call is %d friends:\n", plk);
    printf("And maybe their names are:\n");
    for(i=0;i<num;i++)
        if(strcmp(names[i],"0")!=0)
            printf("%s\n", names[i]);

    system("pause");
}

int FindMax(int r,int num,int tab[r])
{
    int i,max,index;

    max = tab[0];
    index = 0;
    for(i=1;i<num;i++)
    {
        if (tab[i]>max)
        {
            max = tab[i];
            index = i;
        }
    }
    return index;
}

void RemoveName(int maxindex,int r,int c,string hatenames[r][c],int pl,string names[r],int index)
{
    int j;

    for(j=0;j<pl;j++)
    {
        if (strcmp(hatenames[index][j], names[maxindex])==0)
            {
                strcpy(hatenames[index][j], "0");
                break;
            }
    }
}

void printPavles(int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("-");
    printf("\n");
}





