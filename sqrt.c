#include <stdio.h>
#include <math.h>

typedef struct 
{
  int length;
  int period[200];
} contFrac;

int main()
{
  //FILE *fp = fopen("dump.txt","r");
  FILE *fw = fopen("dump1.txt","r");

  contFrac A0[1001];
  //while(feof(fp)==0)
  //{
  //  char c;
  //  c = fgetc(fp);
  //  if(c==',' || c==';' || c=='\t')
  //  {
  //    fputc(' ',fw);
  //    //printf(" ");
  //    continue;
  //  }
  //  //printf("%c",c);
  //  fputc(c,fw);
  //}

  char line[500];
  int n=0;
  while(fgets(line,sizeof(line),fw))
  {
    int len = 0;
    int d = 0;
    char c;
    int k=0;
    while(1)
    {
      c = line[len];
      if(c=='\n') 
      {
        //printf("%d ",k);
        A0[n].period[d] = k;
        d++;
        break;
      }
      if(c == ' ')
      {
        //printf("%d ",k);
        A0[n].period[d] = k;
        d++;
        k = 0;
      }else
      {
        k = (k*10) + c-'0';
      }
      len++;
    }
    A0[n].length = d;
    n++;
    //printf("lenght = %d\n",d);
  }
  fclose(fw);

  for(int i=0;i<n;i++)
  {
    for(int k=0;k<A0[i].length;k++)
    {
      printf("%d ",A0[i].period[k]);
    }
    printf("\n");
  }
  return 0;
}



