public class Test{  
    int x=1,y=2,z=3;
    Test(int a)
    {
        x=a;
    }
    int yo(int x,int y,int z)
    {
        Test s=new Test(1000);  
        s.yo1(10,20,30);
        System.out.println(s.x);
        System.out.println(s.y);
        System.out.println(s.z);
        this.x=x;
        this.y=y;
        this.z=z;
        // System.out.println(a);
    }
    int yo1(int x,int y,int z)
    {
        Test g=new Test(550);  
        // t.yo(50,10,100);
        System.out.println(g.x);
        System.out.println(g.y);
        System.out.println(g.z);
        this.x=x;
        this.y=y;
        this.z=z;
        // System.out.println(a);
    }
public static void main(String args[]){
    Test t=new Test(3);  
    t.yo(50,10,100);
    System.out.println(t.x);
    System.out.println(t.y);
    System.out.println(t.z);
} 
// int a=4,b=5,c=6;
}
// public class Deedee{  
//     int x=1,y=2,z=3;

// public static void yo(String args[]){  }
// int a=4,b=5,c=6;
// }