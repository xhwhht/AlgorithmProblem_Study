package writtenExamination;

import java.util.*;

public class Main3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int K = scan.nextInt();
        int[][] nums = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                nums[i][j] = scan.nextInt();
            }
        }
        //System.out.println(Arrays.toString(nums[n-1]));
        //处理输入结束

        int[][] res = new int[n][5];    //记录结果
        Map<Integer, Integer> indexMap = new HashMap();     //选用哈希Map的数据结构，来判断序号是否重复
        Map<Integer,Integer> floorMap = new HashMap<>();    //选用哈希Map的数据结构，存储5个楼层的人数
        for (int i = 0; i < n; i++) {
            int indexKey = nums[i][0];      
            int floorKey = nums[i][2];
            if ( !indexMap.containsKey(indexKey) && nums[i][1] == 1){       //这里的分类条件还有可以完善的地方
                if ( floorMap.containsKey(floorKey)){
                    if (floorMap.get(floorKey) < K){
                        floorMap.put(floorKey, floorMap.get(floorKey) + 1);
                    }
                }else {
                    floorMap.put(floorKey,1);
                    indexMap.put(indexKey, 1);
                }
            }else if( indexMap.containsKey(indexKey) && nums[i][1] == 0){
                System.out.println(floorMap.get(floorKey));
                floorMap.put(floorKey, floorMap.get(floorKey) - 1);
                System.out.println(floorMap.get(floorKey));
            }
            for (int j = 1; j < 6; j++) {
                if (floorMap.containsKey(j))
                res[i][j-1] = floorMap.get(j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(res[i][j]);
            }
            System.out.println(res[i][4]);
        }
    }
}
