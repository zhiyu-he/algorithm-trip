/**
 * @author hezhiyu on 15/7/20.
 */
public class StrStr {

    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     *
     * TIPS: 字符串查找, O(n^2)了, 考虑优化做法
     */
    public int strStr(String source, String target) {
        // 合法性校验
        if (source == null || target == null) {
            return - 1;
        }
        int sLen = source.length();
        int tLen = target.length();

        // 当都为空串
        if (sLen == 0 && tLen == 0) {
            return 0;
        }
        // target为空时, 返回0
        if (tLen == 0) {
            return 0;
        }
        // 原串小于目标串时 返回-1
        if (sLen < tLen) {
            return -1;
        }

        int i = 0;
        int j = 0;
        while (i < sLen && j < tLen) {
            if (source.charAt(i) == target.charAt(j)) {
                i++;
                j++;
            } else {
                i++;
                j = 0;
            }
        }

        return j == tLen ? i - tLen : -1;
    }

    public static void main(String[] args) {
        StrStr strStr = new StrStr();
        System.out.println(strStr.strStr("abcdabcdefg", ""));
    }
}
