public class MatrixAdditionExample{  
    // int x=5,y=8,z=10;
public static void main(String args[]){  
//creating two matrices    
int a[][]=new int[3][3];   
int b[][]=new int[3][3];
int c[][]=new int[3][3];
//initializing first matrix
a[0][1]=1;
a[0][1]=2;
a[0][2]=3;
a[1][0]=4;
a[1][1]=5;
a[1][2]=6;
a[2][0]=7;
a[2][1]=8;
a[2][2]=9;
// initializing second matrix
b[0][0]=1;
b[0][1]=1;
b[0][2]=1;
b[1][0]=1;
b[1][1]=1;
b[1][2]=1;
b[2][0]=1;
b[2][1]=1;
b[2][2]=1; 
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        c[i][j]=a[i][j]-b[i][j];
        System.out.println(c[i][j]);
    }
}
} 
}