/**
 * @author hezhiyu on 15/7/24.
 */
public class FindTheMissingNumber {
    /**
     * @param nums: an array of integers
     * @return an integer
     * TIPS: 利用了桶排序, 但Challenge中的O(1)空间还没有做到
     * TODO: 解决Challenge
     */
    public int findMissing(int[] nums) {
        // write your code here
        if (nums.length == 0) {
            return 0;
        }
        int[] expandArr = new int[nums.length + 1];

        for (int i = 0; i < expandArr.length; i++) {
            expandArr[i] = -1;
        }

        for (int num : nums) {
            expandArr[num] = num;
        }
        for (int i = 0; i < expandArr.length; i++) {
            if (expandArr[i] != i) {
                return i;
            }
        }
        return nums.length;
    }

    public static void main(String[] args) {
        FindTheMissingNumber findTheMissingNumber = new FindTheMissingNumber();
        int[] num = {0, 1, 3};
        System.out.println(findTheMissingNumber.findMissing(num));
    }
}
