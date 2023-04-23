class Student{   
 int id;
 int square(int a){return a*a;}
}  
class TestStudent2{  
 public static void main(String args[]){  
  Student s1=new Student();  
  s1.id=101;  
  System.out.println(s1.id);
  System.out.println(s1.square(10));
 }  
} 