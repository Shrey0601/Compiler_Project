class Employee{  
    int id;  
    Employee()
    {
        id=0;
    } 
    void insert(int i) {  
        id=i;   
    }  
    void display(){System.out.println(id);}
    }
public class TestEmployee {  
public static void main(String[] args) {  
    Employee e1=new Employee();  
    Employee e2=new Employee();  
    Employee e3=new Employee();  
    e1.insert(101);  
    e2.insert(102);  
    e3.insert(103);  
    e1.display();  
    e2.display();  
    e3.display();  
}  
}  