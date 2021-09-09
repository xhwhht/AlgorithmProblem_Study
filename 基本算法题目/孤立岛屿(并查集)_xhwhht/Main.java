package baidu;

import java.util.Scanner;

/*
 * 这个题目在0-1矩阵中寻找岛的数量时，是向8个方向检索。
 * 不同之前只能水平或者垂直方向检索。
 * */
public class Main {


    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int  m = cin.nextInt();
        int  n = cin.nextInt();
        int [][] a = new int[m][n];

        String ss = cin.nextLine();

        for (int i = 0; i <m ; i++) {
            String s = cin.nextLine();
            String[] str = s.split("");

            for (int j = 0; j < n; j++) {
                if(str[j].equals("F")){
                    a[i][j] = 1;
                }
                else{
                    a[i][j] = 0;
                }

            }

        }

        System.out.println(countIslands(a));
    }

    //主要子函数
    public static int countIslands(int a[][]) {
        int n = a.length;
        int m = a[0].length;

        DisjointUnionSets dus = new DisjointUnionSets(n * m);

        /*
         * 下面的循环检查其邻居，如果两者都是1，则进行处理。
         */
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                // 如果单元格的值为0，则什么都不做
                if (a[j][k] == 0)
                    continue;
                System.out.println("新的位置：");
                // 8个方向检查
                if (j + 1 < n && a[j + 1][k] == 1)
                    dus.union(j * (m) + k, (j + 1) * (m) + k);               
                if (k + 1 < m && a[j][k + 1] == 1)
                    dus.union(j * (m) + k, (j) * (m) + k + 1);
                if (j + 1 < n && k + 1 < m && a[j + 1][k + 1] == 1)
                    dus.union(j * (m) + k, (j + 1) * (m) + k + 1);     
            }
        }

        //计算孤立岛屿
        int[] c = new int[n * m];
        int numberOfIslands = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j][k] == 1) {

                    int x = dus.find(j * m + k);  //找公共子节点

                    if (c[x] == 0) {
                        numberOfIslands++;
                        c[x]++;
                    }

                    else
                        c[x]++;
                }
            }
        }
        return numberOfIslands;
    }


    //内部类
    static class DisjointUnionSets{

        int[] parent;
        int[] rank;


        //初始化
        public DisjointUnionSets(int n) {
            rank = new int[n];
            parent = new int[n];
            for (int i = 0; i < n; i++)
                parent[i] = i;

        }

        //找到根节点

        int find(int x) {
            if (parent[x] != x) {
                return find(parent[x]);
            }

            return x;
        }

        //将公共集合里的节点关联至最终根节点  关联数少的往大的靠 当前父节点x
        void union(int x, int y) {

            //寻找这俩个节点的父节点 并合并到公共父节点
            int xRoot = find(x);
            int yRoot = find(y);

            if (xRoot == yRoot) {         //找到自己
                return;
            }

            if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;       //关联节点关系
            }else if (rank[yRoot] < rank[xRoot]) {
                parent[yRoot] = xRoot;       //
            }else
            {
                parent[yRoot] = xRoot;       //这俩个节点关联数量一样 需要合并压缩路径
                rank[xRoot] = rank[xRoot] + 1;
            }

            show(parent,rank);
        }

       void show(int [] parent,int [] rank)
       {
           int n= parent.length;
           for (int i = 0; i < n; i++) {
               System.out.print(parent[i]);
               System.out.print(" ");

           }
           System.out.println();
           for (int i = 0; i <n ; i++) {
               System.out.print(rank[i]);
               System.out.print(" ");

           }
           System.out.println();
       }
    }

}

