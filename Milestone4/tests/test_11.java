// A Dynamic Programming based solution
// for 0-1 Knapsack problem

import java.io.*;

class Knapsack {

	// A utility function that returns
	// maximum of two integers
	static int max(int a, int b) {
		if(a > b){
			return a;
		}
		else{
			return b;
		}
	 }

	// Driver code
	public static void main(String args[])
	{
		int profit[] = new int[3];
		profit[0] = 60;
		profit[1] = 100;
		profit[2] = 120;
		int weight[] = new int[3];
		weight[0] = 10;
		weight[1] = 20;
		weight[2] = 30;
		int W = 50;
		int n = 3;
		int i, w;
		int K[][] = new int[n + 1][W + 1];

		// Build table K[][] in bottom up manner
		for (i = 0; i <= n; i++) {
			for (w = 0; w <= W; w++) {
				if (i == 0 || w == 0)
					K[i][w] = 0;
				else if (weight[i - 1] <= w)
					K[i][w]
						= max(profit[i - 1]
								+ K[i - 1][w - weight[i - 1]],
							K[i - 1][w]);
				else
					K[i][w] = K[i - 1][w];
			}
		}

		System.out.println(K[n][W]);
	}
}
/*This code is contributed by Rajat Mishra */
