/**
 * @author hezhiyu on 15/7/23.
 */
public class LongestCommonSubstring {

    /**
     * @param A, B: Two string.
     * @return the length of the longest common substring.
     * TIPS: 1. 暴力解
     *       2. TODO 动态规划
     *       3. TODO 高位数组 ＋ 后缀数组
     */
    public int longestCommonSubstring(String A, String B) {
        // write your code here
        if (A == null || B == null || A.length() == 0 || B.length() == 0) {
            return 0;
        }

        String target = A.length() < B.length() ? A : B; // 长度小的作为目标串
        String search = A.length() < B.length() ? B : A; // 长度大的作为搜索串

        int tLen = target.length();
        int sLen = search.length();
        int lcs = tLen;
        while (lcs > 0) {
            for (int i = 0; i <= tLen - lcs; i++) {
                for (int j = 0; j <= sLen - lcs; j++) {
                    String t = target.substring(i, lcs + i);
                    String s = search.substring(j, lcs + j);
                    if (t.compareTo(s) == 0) {
                        return lcs;
                    }
                }
            }
            lcs--;
        }
        return lcs;
    }

    public static void main(String[] args) {
        LongestCommonSubstring longestCommonSubstring = new LongestCommonSubstring();
        System.out.println(longestCommonSubstring.longestCommonSubstring("ABCD", "CBCE"));
        System.out.println(longestCommonSubstring.longestCommonSubstring("ABCD", "ABD"));
    }
}
