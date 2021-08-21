package Problem02;
import java.util.Scanner;
public class Ali02 {

    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);

        int N, M,i,j,c,d,max=1,k=1,temp,y,mm;

        M = cin.nextInt();   //运动员个数
        N = cin.nextInt();   //指令个数

        int[] a = new int [M+1];  //记录各个赛道的人数
        int[] t = new int [N+1];  // 存放差值
        int[] f = new int [M+1];  //按顺序记录运动员所在赛道


        for(i=1;i<M+1;i++)
        {
            a[i]=1;
            f[i]=i;
        }

        for(j=0;j<N;j++) {
            c = cin.nextInt();
            d = cin.nextInt();

            if (f[c]>f[d]) {
                mm = f[d];             //保护需要移动的较小赛道号 以免被覆盖
                for (y=1;y<M;y++) {    //保较小赛道号 上的所有人都需要移动
                    if (f[y] == mm) {
                        a[f[c]] = a[f[c]] + 1;
                        f[y] = f[c];
                    }
                }
            }
            else if (f[c] < f[d] ){
                mm = f[c];
                for (y = 1; y < M; y++) {
                    if (f[y] == mm) {
                        a[f[d]] = a[f[d]] + 1;
                        f[y] = f[d];
                    }
                }
            }
            else{
                if (i > 0) {
                    temp=a[f[c]];
                    t[k] = max-temp;
                    k = k + 1;
                }
            }

            for (i = 0; i < M; i++) {
                if (a[i] > max)
                    max = a[i];
            }
        }

        //输出
        for (i = 1; i <k; i++) {
            System.out.println(t[i]);
        }
        for (i = 1; i < M +1;i++) {
            System.out.print(f[i] );
            if(i<M) {
                System.out.print(" ");
            }
        }

    }
}
