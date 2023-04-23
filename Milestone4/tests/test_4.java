class Student{  
 int rollno;   
 void insertRecord(int r){  
  rollno=r;  
 }  
 void displayInformation(){System.out.println(rollno);}  
}  
class TestStudent4{  
 public static void main(String args[]){  
  Student s1=new Student();  
  Student s2=new Student();  
  s1.insertRecord(111);  
  s2.insertRecord(222);  
  s1.displayInformation();  
  s2.displayInformation();  
 }  
}