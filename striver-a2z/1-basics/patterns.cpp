#include <bits/stdc++.h>
using namespace std;

/*
ALL PATTERNS WILL INVOLVE NESTED LOOPS
1) For the outer loop, count the number of rows
2) For the inner loop, focus on the columns and connect them somehow to the rows
3) Whatever you're printing, print it inside the inner loop
4) Observe symmetry (Optional)
*/

/*Pattern 1:
****
****
****
****
*/
void pattern1(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        cout << "*";
        cout << endl;
    }
}


/* Pattern 2:
*
**
***
****
*****
*/
void pattern2(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        cout << "*";
        cout << endl;
    }
}

/* Pattern 3:
1
12
123
1234
12345
*/

void pattern3(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        cout << j;
        cout << endl;
    }
}

/* Pattern 4:
1
22
333
4444
55555
*/

void pattern4(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        cout << i;
        cout << endl;
    }
}

/* Pattern 5:
*****
****
***
**
*
*/

void pattern5(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=n; j>i; j--)
        cout << "*";
        cout << endl;
    }
}

/* Pattern 6:
12345
1234
123
12
1
*/

void pattern6()
{
    for(int i=0; i<5;i++)
    {
        for(int j=5; j>=1; j--)
        cout << j;
        cout << endl;
    }
}

/* Pattern 7:
    *
   ***
  *****
*/

void pattern7(int n)
{
    //For n rows, there are (2n+1) columns
        // We are printing space, stars, space
        // The space, stars, space for every row goes like (4,1,4), (3,3,3) etc.
        // The question is now broken down into 3 patterns; break it down into parts
   for(int i=0; i<n; i++)
   {
    for(int k=0; k<n-i-1; k++)
    cout << " ";
    for(int j=0; j<(2*i+1);j++)
    cout << "*";
    for(int k=0; k<n-i-1; k++)
    cout << " ";
    cout << endl;
   }
}


/* Pattern 8: Inverted patter of pattern 7 */

void pattern8(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        cout << " ";
        for(int k=(2*n-1-2*i); k>0; k--)
        cout << "*";
        for(int j=0; j<=i; j++)
        cout << " ";
        cout << endl;
    }
}

/*Combination of pattern 7 and 8 */
void pattern9(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<n-i-1; k++)
    cout << " ";
    for(int j=0; j<(2*i+1);j++)
    cout << "*";
    for(int k=0; k<n-i-1; k++)
    cout << " ";
    cout << endl;}
    for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++)
        cout << " ";
        for(int k=(2*n-1-2*i); k>0; k--)
        cout << "*";
        for(int j=0; j<=i; j++)
        cout << " ";
        cout << endl;
    }
}

void pattern10(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        cout << "*";
        cout << endl;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=n-i-2; j>=0; j--)
        cout << "*";
        cout <<endl;
    }
}

/* Pattern 11:
1
01
101
0101
10101
*/
void pattern11(int n)
{
    for(int i=0; i<n; i++)
    {
        int start=0;
        if(i%2==0) start=1;
        else start=0;
        for(int j=0; j<=i;j++)
        {
            cout <<start;
            start=1-start;
        }
        cout <<endl;
    }
}

/* Pattern 12:
1      1
12    21
123  321
12344321
*/
void pattern12(int n)
{
    /* (1, 6 spaces, 1), (2, 4 spaces, 2) etc.; 1 pattern on th left; spaces loop runs from 2n-2i; another pattern on right
    */

    for(int i=1; i<=n; i++)
    {
     for(int j=1; j<=i; j++)
     cout<<j;
     for(int k=2*n-2*i; k>0; k--)
     cout << " ";
     for(int m=i; m>=1; m--)
     cout <<m;
     cout <<endl;
    }
}

/* Pattern 13:
1
23
456
78910
1112131415
*/
void pattern13(int n)
{
    int num=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
       { cout<<num<<" ";
        num+=1;}
        cout<<endl;
    }
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        pattern1(n);
    }

}