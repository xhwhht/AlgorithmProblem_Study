public class Main {
    public static void main(String[] args) {


        int amount = 30;
        int[] coins = new int[]{1,3,7,11,13,15};
        int[] nums = new int[]{1,2,3,4,5,2};


        int max = Integer.MAX_VALUE;
        int[] dp = new int[amount + 1];


        //初始化dp数组为最大值
        for (int j = 0; j < dp.length; j++) {
            dp[j] = max;
        }

        //当金额为0时需要的硬币数目为0
        dp[0] = 0;

        for (int i = 0; i < coins.length; i++) {
            //遍历硬币个数
            for (int j = amount; j >=  coins[i]; j--) {
                //倒序遍历：多重背包每个硬币选择次数有限
                for (int k = 1; k <nums[i] + 1 ; k++) {
                    //防止数组越界 && 当 dp[j-coins[i]]为初始最大值时，说明没有符合的组合
                    if (((j - k * coins[i]) >= 0) && (dp[j - k * coins[i]] != max) ) {
                        dp[j] = Math.min(dp[j], dp[j - k*coins[i]] +k);
                    }
                }
            }
            //打印dp数组
            for (int j = 0; j <amount+1 ; j++) {
                System.out.print(dp[j] );
                System.out.print(" ");

            }
            System.out.println();
        }
        //打印结果
        dp[amount]= (dp[amount] == max )? -1 : dp[amount];  //三目运算
        System.out.println(dp[amount]);
    }
}
