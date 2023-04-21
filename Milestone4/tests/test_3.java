public class SyntaxCheck {
    int a=0;
    void printFunc(int val) {
        System.out.println(val);
    }

    public static void main(String[] args) {
        int a;
        a = 5;
        int b = 10;
        a++;
        printFunc(a+b);
    }
}
