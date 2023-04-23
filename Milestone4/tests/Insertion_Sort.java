class InsertionSort {
  public static void main(String args[]) {
    int data[] = new int[5] ;
    data[0] = 9;
    data[1] = 2;
    data[2] = 8;
    data[3] = 4;
    data[4] = 5;
    for (int step = 1; step < 5; step++) {
      int key = data[step];
      int j = step - 1;
      while (j >= 0 && key < data[j]) {
        data[j + 1] = data[j];
        --j;
      }
      data[j + 1] = key;
    }
    for(int i=0;i<5;i++)
    {
        System.out.println(data[i]);
    }
  }
}