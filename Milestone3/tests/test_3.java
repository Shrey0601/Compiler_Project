public class SyntaxCheck {
    static void printFunc(float val) {
        //System.out.println(val);
    }

    public static void main(String[] args) {
        int a;
        a = 5;
        a++;
        printFunc(a);
        ++a;
        float b = 3.14f; // Default to a float type
        printFunc(b);
        float c = (float) (a + b);
        long val = 100L;
        printFunc(val);
    }
}
