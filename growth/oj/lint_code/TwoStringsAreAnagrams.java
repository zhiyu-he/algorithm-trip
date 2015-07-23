/**
 * @author hezhiyu on 15/7/19.
 */
public class TwoStringsAreAnagrams {

    /**
     * @param s: The first string
     * @param t: The second string
     * @return true or false
     *
     * TIPS: 1. 暴力的做法就是统计出现的次数, 然后s与t做减法
     *       2. 将字符串排序后, 计算hashcode
     */
    public boolean anagram(String s, String t) {
        // write your code here
        if (s.length() != t.length()) {
            return false;
        }
        s = s.toLowerCase();
        t = t.toLowerCase();
        int[] ch = new int[Character.MAX_VALUE];
        for (int i = 0; i < Character.MAX_VALUE; i++) {
            ch[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            ch[s.charAt(i)] += 1;
        }
        boolean flag = true;
        for (int i = 0; i < t.length(); i++) {
            if (ch[t.charAt(i)] == 0) {
                flag = false;
                break;
            }
            ch[t.charAt(i)] -= 1;
        }

        for (int i = 0; i < 26; i++) {
            if (ch[i] != 0) {
                flag = false;
            }
        }
        return flag;
    }

    public static void main(String[] args) {

        TwoStringsAreAnagrams t = new TwoStringsAreAnagrams();

        System.out.println(t.anagram("abcd", "dcab"));
    }
}
