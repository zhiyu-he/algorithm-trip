/**
 * @author hezhiyu on 15/7/20.
 */
public class CompareStrings {

    /**
     * @param A : A string includes Upper Case letters
     * @param B : A string includes Upper Case letter
     * @return :  if string A contains all of the characters in B return true else return false
     *
     * TIPS: 记录A字符串每个字符出现的次数, 用B的去做减法, 如果能减法后 每位 >= 0 则true; 否则 false
     *       TimeComplexity O(A.length + B.length)
     */
    public boolean compareStrings(String A, String B) {
        // write your code here
        int a_len = A.length();
        int b_len = B.length();

        if (b_len == 0) {
            return true;
        }
        if (a_len < b_len) {
            return false;
        }

        int ch[] = new int[Character.MAX_VALUE];

        for (int i = 0; i < Character.MAX_VALUE; i++) {
            ch[i] = 0;
        }

        for (int i = 0; i < a_len; i++) {
            ch[A.charAt(i)] += 1;
        }

        for (int i = 0; i < b_len; i++) {
            if (ch[B.charAt(i)] == 0) {
                return false;
            }
            else {
                ch[B.charAt(i)] -= 1;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        CompareStrings cs = new CompareStrings();
        System.out.println(cs.compareStrings("ABCD", "AABC"));
    }
}
