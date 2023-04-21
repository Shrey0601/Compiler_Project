class Student{   
 int id;
 int yo(){return 2*3;}
}  
class TestStudent2{  
 public static void main(String args[]){  
  Student s1=new Student();  
  s1.id=101;  
  System.out.println(s1.id);
  System.out.println(yo());
 }  
} 