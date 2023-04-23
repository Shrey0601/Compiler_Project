
class GFG {
	public static void main(String[] args)
	{
		int arr[][][][] = new int[2][2][2][2];
        arr[0][0][0][0]=1;
        arr[0][0][0][1]=2;
        arr[0][0][1][0]=3;
        arr[0][0][1][1]=4;
        arr[0][1][0][0]=5;
        arr[0][1][0][1]=6;
        arr[0][1][1][0]=7;
        arr[0][1][1][1]=8;
        arr[1][0][0][0]=9;
        arr[1][0][0][1]=10;
        arr[1][0][1][0]=11;
        arr[1][0][1][1]=12;
        arr[1][1][0][0]=13;
        arr[1][1][0][1]=14;
        arr[1][1][1][0]=15;
        arr[1][1][1][1]=16;


		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int z = 0; z < 2; z++)
                    for (int k = 0; k < 2; k++)
					System.out.println(arr[i][j][z][k]);
	}
}
