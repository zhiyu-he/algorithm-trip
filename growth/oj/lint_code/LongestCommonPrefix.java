import java.util.ArrayList;
import java.util.List;

/**
 * @author hezhiyu on 15/7/22.
 */
public class LongestCommonPrefix {
    /**
     * @param strs: A list of strings
     * @return The longest common prefix
     *
     * TIPS: 循环遍历 判断每个str[i]的是否均相同, 相同 i++, 否则return
     */
    public String longestCommonPrefix(String[] strs) {
        // write your code here
        // 当字符数组为空时,
        if (strs.length == 0) {
            return "";
        }
        // 当输入一个字符串时, prefix为自身
        if (strs.length == 1) {
            return strs[0];
        }
        // 处理可能携带的空白符
        List<String> list = new ArrayList<>();
        for (int i = 0; i < strs.length; i++) {
            strs[i] = strs[i].trim();
            if (strs[i].length() == 0) {
                return "";
            }
            if (strs[i].length() > 0) {
                list.add(strs[i]);
            }
        }
        if (list.size() <= 1) {
            return "";
        }
        // 选区任意一个作为target
        String target = list.remove(0);
        String res = "";
        int i = 0;
        while (i < target.length()) {
            char ch = target.charAt(i);
            for (String str : list) {
                if (i >= str.length() || str.charAt(i) != ch) {
                    return res;
                }
            }
            res += ch;
            i++;
        }
        return res;
    }


    public static void main(String[] args) {
        LongestCommonPrefix lcp = new LongestCommonPrefix();
        String[] str1 = {"ABCD", "ABEF", "ACEF"};
        System.out.println(lcp.longestCommonPrefix(str1));
        String[] str2 = {"ABCDEFG", "ABCEFG", "ABCEFA"};
        System.out.println(lcp.longestCommonPrefix(str2));
        String[] str3 = {"", "A"};
        System.out.println(lcp.longestCommonPrefix(str3));

    }
}
