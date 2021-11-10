//Group Matador CM Project 
#include<iostream>
#include<iomanip>
#include<cmath>

void Deter()
{
    double a1[2][2];
    double a2[3][3];
    float det1,det2;
    int sz;
    std::cout << "Give the size of square matrix which you want to determine.For 2*2 matrix press 2 and for 3*3 matrix press 3: ";
    std::cin >> sz; 
    while(sz<2||sz>3){
	std::cout << "Size of matrix inputted wrongly.Please Enter a valid input : ";
    std::cin >>sz;
    }
if(sz == 2){
std::cout << "Enter digits for matrix 2*2" << std::endl;
for(int i=0;i<2;i++)
for(int j=0;j<2;j++)
    {
        std::cout << "Row : " << i+1 << "\tColumn : " << j+1 << std::endl;
        std::cin >> a1[i][j];
    }
    det1 = ((a1[0][0]*a1[1][1])-(a1[0][1]*a1[1][0]));//
std::cout<<"                  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|        "            <<std::endl;
std::cout<<"                  -------------------------------------------------         "            <<std::endl;
std::cout<<"                  |     Calculating Determinant of  2*2 Matrix    |         "           <<std::endl;
std::cout<<"                  -------------------------------------------------         "            <<std::endl;
std::cout<<"                  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|        "            <<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
std::cout << "The determinant for matrix 2*2 : " << det1 << std::endl;
    }
    else
    {
    std::cout << "Enter the matrix for 3*3" << std::endl;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
        std::cout << "Row : " << i+1 << "\tColumn : " << j+1 << std::endl;
        std::cin >> a2[i][j];
    }

    det2 = a2[0][0]*((a2[1][1]*a2[2][2])-(a2[1][2]*a2[2][1]))-a2[0][1]*((a2[1][0]*a2[2][2])-(a2[1][2]*a2[2][0]))
                    +a2[0][2]*((a2[1][0]*a2[2][1])-(a2[1][1]*a2[2][0]));

std::	cout<<"                  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|        "            <<std::endl;
std::	cout<<"                  -------------------------------------------------         "            <<std::endl;
std::	cout<<"                  |     Calculating Determinant of  3*3 Matrix    |         "           <<std::endl;
std::	cout<<"                  -------------------------------------------------         "            <<std::endl;
std::	cout<<"                  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|        "            <<std::endl;
std::	cout<<std::endl;

    std::cout << "The determinant for matrix 3*3 : " << det2 << std::endl;
    }
}


//**************************************************************************************************************************************

void lufac()
{
    int M,i,j,k,p;
    double a[10][10],l[10][10]={0},u[10][10]={0};
    double sum,B[10],Y[10]={0},X[10]={0};               
    
   std:: cout<<"Give the variables :  ";
    std::cin>>M;
    while(M<=3)
    {
        std::cout << "The variable number you enter is less than 3, please input another variable number\nVariable number : ";
        std::cin >> M;
    }
   std:: cout<<"Enter all coefficients of matrix => "<<std::endl;
    for(i=1;i<=M;i++)
    {
        std::cout<<" The Row here: "<<i<<"  ";
        for(j=1;j<=M;j++)
           std:: cin>>a[i][j];
    }
    std::cout<<std::endl;
    std::cout<<"Enter elements of B matrix"<<std::endl;
    for(i=1;i<=M;i++)
        std::cin>>B[i];

   
    for(k=1;k<=M;k++)
    {
        u[k][k]=1;
        for(i=k;i<=M;i++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k];
            l[i][k]=a[i][k]-sum;
        }

        for(j=k+1;j<=M;j++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }
    
    std::cout<<std::endl;
    std::cout<<"The l decomposition matrix => "<<std::endl;
    for(i=1;i<=M;i++)
    {
        for(j=1;j<=M;j++)
         std::   cout<<l[i][j]<<"  ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"The u decomposition matrix => "<<std::endl;
    for(i=1;i<=M;i++)
    {
        for(j=1;j<=M;j++)
        std::    cout<<u[i][j]<<"  ";
      std::  cout<<std::endl;
    }

    
    for(i=1;i<=M;i++)
    {                                        
        sum=0;
        for(p=1;p<i;p++)
        sum+=l[i][p]*Y[p];
        Y[i]=(B[i]-sum)/l[i][i];
    }

    
    for(i=M;i>0;i--)
    {
        sum=0;
        for(p=M;p>i;p--)
            sum+=u[i][p]*X[p];
        X[i]=(Y[i]-sum)/u[i][i];
    }
    
   std:: cout<<std::endl<<"Set of solution is"<<std::endl;
    for(i=1;i<=M;i++)
    {
       std:: cout<<"X"<<i<<"= "<<X[i]<<std::endl;
    }
}

//*********************************************************************************

void interp()
{
int n;
    std::cout << "Give the number of data point that are less than content 7 => ";
    std::cin >>n;
while(n < 0||n > 7){
    std::cout << "Invalid data.Sir please enter right data =>  ";
    std::cin >>n;
    }
double **datPt= new double*[2];
for(int i=0;i<2;i++)
    datPt[i] = new double [n]; 
    for(int i=0;i<n;i++){
    std::cout << "Here is the data point =>  " << i+1 << std::endl;
    std::cout << "X : ";
    std::cin >> datPt[0][i];
    std::cout << "Y : ";
    std::cin >> datPt[1][i];
    }
    //Generating linear polynomial for degree of 2
double A[3];
double V[3];
double S[3][3];
    S[0][0] = 0;
    S[0][1] = 0;
    S[0][2] = 0;
    S[1][2] = 0;
    S[2][2] = 0;
for(int i=0;i<n;i++){
    S[0][0] = S[0][0] + pow(datPt[0][i],0);
    S[0][1] = S[0][1] + pow(datPt[0][i],1);
    S[0][2] = S[0][2] + pow(datPt[0][i],2);
    S[1][2] = S[1][2] + pow(datPt[0][i],3);
    S[2][2] = S[2][2] + pow(datPt[0][i],4);
    }
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
S[j][i] = S[i][j];
S[1][1] = S[2][0];

for(int i=0;i<3;i++){
    V[i] = 0;
for(int j=0;j<n;j++)
    V[i] = V[i] + pow(datPt[0][j],i)*datPt[1][j];
    }

    //Gaussian Elimination
	V[0] = V[0]/S[0][0];
for(int i=2;i>=0;i--)
	S[0][i] = S[0][i]/S[0][0];

float Count;
    Count = S[1][0];
    V[1] = V[1]-(V[0]*Count);
for(int i=0;i<3;i++)
    S[1][i] = S[1][i] - (S[0][i] * Count);
    Count = S[2][0];
    V[2] = V[2]-(V[0]*Count);
for(int i=0;i<3;i++)
    S[2][i] = S[2][i] - (S[0][i] * Count);

    V[1] = V[1]/S[1][1];
for(int i=2;i>=1;i--)
    S[1][i] = S[1][i]/S[1][1];

    Count = S[2][1];
    V[2] = V[2]-(V[1]*Count);
for(int i=1;i<3;i++)
    S[2][i] = S[2][i] - (S[1][i] *Count);

    Count = S[2][2];
    V[2] = V[2]/S[2][2];
    S[2][2] = S[2][2]/1;
for(int i=2;i>=0;i--){
        A[i] = V[i];
    if(i != 2){
            A[i] = V[i];
        if(i != 2)                         //last row
        for(int j=2;j!=i;j--)
            A[i] = A[i] - S[i][j]*A[j];
        }
    }
double pnt;
    std::cout << "Enter the point => ";
    std::cin >> pnt;
float ans;
    ans = A[2]*pow(pnt,2) + A[1]*pnt + A[0];
    std::cout << "p(x) = " << A[0] << " + " << A[1] << "x + " << A[2] << "x^2" << std::endl;
    std::cout << "p(" << pnt<< ") = " << ans;

for(int i=0;i<2;i++)
    delete []datPt[i];
    delete []datPt;
}


//**********************************************************************

int main(){
int ch;
char ans; 

do{
std::cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<std::endl;
std::cout<<"^^    Welcome to Matador Calculating Machine     ^^"<<std::endl;
std::cout<<"^^    Sir What you want to Calculate             ^^"<<std::endl;
std::cout<<"^^    1. Determinant calculation                 ^^"<<std::endl;
std::cout<<"^^    2. LU factorization                        ^^"<<std::endl;
std::cout<<"^^    3. Interpolation                           ^^"<<std::endl;
std::cout<<"^^    4. Exit                                    ^^"<<std::endl;
std::cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<std::endl;
std:: cout<<std::endl;
std:: cout<<std::endl;
std::cout<<"Enter your choice:";
std:: cout<<std::endl;
std::cin>>ch;
switch(ch){
    case 1:
    	 Deter();
        break;
    case 2:
        lufac();  
        break;
      case 3:
      	interp();
        break;
      case 4:  
        exit(0);
        //break;
      default:
        std::cout<<"Invalid Choice";
       // break;
   }
std::cout<<"\n\t Do you want to continue(Yes=Y/NO=N)? ,if you want to calculate again please press y,if want to exit press n . TQ.";
std:: cout<<std::endl;
std:: cin>>ans;
 }

 while(ans=='y'||ans=='Y'); 
  
  
  
 return 0;
}
