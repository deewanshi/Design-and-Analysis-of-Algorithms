#include<iostream>
using namespace std;

#define max1 20
#define max2 20

void PRINT_LCS(char b[][max2], char X[], int i, int j)
{
     if((i == 0) || (j == 0))
          return;
     if(b[i][j] == '\\')
     {
          PRINT_LCS(b, X, i - 1, j - 1);
          cout<<X[i-1]<<" ";
     }
     else
     {
          if(b[i][j] == '|')
               PRINT_LCS(b, X, i - 1, j);
          else
               PRINT_LCS(b, X, i, j - 1);
     }
}

void LCS_LENGTH(char X[], int m, char Y[], int n)
{
     char b[max1][max2];
     char c[max1][max2];
     
     for(int i = 0; i <= m; i++)
          c[i][0] = 0; 
     for(int j = 0; j <= n; j++)
          c[0][j] = 0;

     int count = 0;

     for(int i = 1; i <= m; i++)
     {
          for(int j = 1; j <= n; j++)
          {
               if(X[i-1] == Y[j-1])
               {
                    c[i][j] = c[i-1][j-1] + 1;
                    b[i][j] = '\\';
                    count = count + 1;
               }
               else
               {
                    if(c[i-1][j] >= c[i][j-1])
                    {
                         c[i][j] = c[i-1][j];
                         b[i][j] = '|';
                    }
                    else
                    {
                         c[i][j] = c[i][j-1];
                         b[i][j] = '-';
                    }
               }
          }
     }
     
     if(count == 0)
          cout<<"There is no Longest Common Subsequence.";
     else
     {
          cout<<"\nLongest Common Subsequence: ";
          PRINT_LCS(b, X, m, n);
     }
}

int main()
{
     cout<<"Enter the length of 1st sequence: ";
     int size1;
     cin>>size1;
     char *X = new char[size1];

     cout<<"Enter Elements of First Sequence: ";
     for(int i = 0; i < size1 ; i++)
          cin>>X[i];
     
     cout<<"Enter the length of 2nd sequence: ";
     int size2;
     cin>>size2;
     char *Y = new char[size2];

     cout<<"Enter Elements of Second Sequence: ";
     for(int j = 0; j < size2; j++)
          cin>>Y[j];
     
     system("CLS");
     
     cout<<"\nFirst Sequence: ";
     for(int i = 0; i < size1; i++)
          cout<<X[i]<<" ";
     
     cout<<"\nSecond Sequence: ";
     for(int j = 0; j < size2; j++)
          cout<<Y[j]<<" ";
          
     LCS_LENGTH(X, size1, Y, size2);
     system("PAUSE");
}
