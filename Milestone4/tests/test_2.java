public class TypeCheck1 {
    int a = 5;
    int b;

    public TypeCheck1(int a1, int b1) {
        this.a = a1;
        a = 100;
        this.b = b1;
    }

    public int getA() {
        return this.a;
    }

    public float getB() {
        return this.b;
    }

    public void setA(int a1) {
        this.a = a1;
    }

    public void setB(int b1) {
        this.b = b1;
    }

    public static void main(String[] args) {
        TypeCheck1 obj = new TypeCheck1(1, 2);

        // Same names
        int a = obj.a;
        int b = obj.b;
        // obj.setA(10);
        // obj.setB(20);
        // System.out.println(obj.a);
        // System.out.println(getB());
        System.out.println(obj.a);
        System.out.println(b);
        // // Different names
        // int c = obj.a;
        // float d = obj.b;
    }
}
