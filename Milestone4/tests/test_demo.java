public class Main
{
        int sum(int a, int b, int c){
                return a + b + c ;
        }
	public static void main() {
        int a = 1, b = 2, c = 3 ;
        int d = sum(a,b*c, c) ;
        System.out.println(d) ;
        return ;
	}
}