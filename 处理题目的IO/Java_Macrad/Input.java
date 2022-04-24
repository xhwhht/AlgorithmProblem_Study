import java.util.ArrayList;
import java.util.Scanner;


public class Input {

    public static void main(String[] args) {

      /*  //-----------------第一种输入----------------------------//

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();		             //以字符串形式读入数据（空格隔开，也可换成','等字符隔开）

        String[] str = s.split(" ");	         //使用split函数将字符串分割成字符串数组
        int n = 0;
        for (String data : str) {		              //增强for循环获得个数
            n++;
        }

        int[] a = new int[n];			              //定义int数组
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(str[i]);          //使用Integer.parseInt()将分开的字符串转为整数
        }


        // 验证
        for (int i = 0; i < n; i++) {
            System.out.print( a[i]);
            System.out.print( " ");
        }*/

     /*  //-----------------第二种输入----------------------------//

        int m,n=0;
        Scanner scanner = new Scanner (System.in);
        ArrayList<String[]> list = new ArrayList<>();
        while(scanner.hasNextLine()){

            String input = scanner.nextLine();
            if(input.equals(""))
            {
                break;
            }
            String[] split =input.split(",");
            n= split.length;
            list.add(split);

        }

          m=list.size();
          String [][] strings= new String[m][n];
          int [][] IntNum= new int[m][n];


          String [][] objects = list.toArray(strings);
          for (int i = 0; i < m; i++) {
              for (int j = 0; j <n ; j++) {
                  IntNum[i][j] = Integer.parseInt(objects[i][j]);
              }
          }*/


   /*     // 验证
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <n ; j++) {
                System.out.print(IntNum[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
*/


    }
}

