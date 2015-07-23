import java.util.HashMap;
import java.util.Map;

/**
 * @author hezhiyu on 15/7/20.
 */
public class StringToInteger {
    /**
     * @param str: A string
     * @return An integer
     *
     * TIPS: 记录A字符串每个字符出现的次数, 用B的去做减法, 如果能减法后 每位 >= 0 则true; 否则 false
     *       TimeComplexity O(A.length + B.length)
     *       TODO: challenge O(n) O(1)
     */
    public int atoi(String str) {

        // write your code here
        if (str == null) {
            return 0;
        }
        str = str.trim();
        int strLen = str.length();

        if (strLen == 0) {
            return 0;
        }

        Map<Character, Integer> hash = new HashMap<>();
        hash.put('0', 0);
        hash.put('1', 1);
        hash.put('2', 2);
        hash.put('3', 3);
        hash.put('4', 4);
        hash.put('5', 5);
        hash.put('6', 6);
        hash.put('7', 7);
        hash.put('8', 8);
        hash.put('9', 9);

        int negative = 0;
        int index = 0;
        if (str.charAt(0) == '-') {
            negative = 1;
            index = 1;
        }
        if (str.charAt(0) == '+') {
            index = 1;
        }
        long res = 0;
        while (index < strLen) {
            Integer value = hash.get(str.charAt(index));
            if (value == null) {
                break;
            }
            res = res * 10 + value;
            if (negative == 0) { // 正数
                if (res > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
            } else { // 负数
                if (res * -1 < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
            }
            index++;
        }
        return negative == 0 ? (int)res : (int)(res * -1);
    }

    public static void main(String[] args) {
        StringToInteger sti = new StringToInteger();
        System.out.println(sti.atoi("1.0"));
        System.out.println(sti.atoi("123123123123123"));
        System.out.println(sti.atoi("10"));
        System.out.println(sti.atoi("-1"));
        System.out.println(sti.atoi("    -5211314"));
        System.out.println(sti.atoi("+1"));
    }
}
