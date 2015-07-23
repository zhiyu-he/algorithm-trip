import java.util.*;

/**
 * @author hezhiyu on 15/7/22.
 */
public class Anagrams {
    /**
     * @param strs: A list of strings
     * @return A list of strings
     *
     * TIPS: 对每一个str按字母的字典需排列, 而后计算hash_code, 默认相信不会碰撞（哈希冲突）
     */
    public List<String> anagrams(String[] strs) {
        // write your code here
        if (strs.length == 0) {
            return Collections.emptyList();
        }
        // key: 字符串, value: 数组下标
        Map<String, List<Integer>> hash = new HashMap<>();
        Comparator<Character> comparator = new Comparator<Character>() {
            @Override
            public int compare(Character o1, Character o2) {
                return o1.compareTo(o2);
            }
        };

        int index = 0;
        for (String str : strs) {
            List<Character> characters = new ArrayList<>(str.length());
            for (int i = 0; i < str.length(); i++) {
                characters.add(str.charAt(i));
            }
            Collections.sort(characters, comparator);
            String key = "";
            for (Character ch : characters) {
                key += ch;
            }
            List<Integer> indexList = hash.get(key);
            if (indexList == null) {
                indexList = new ArrayList<>();
            }
            indexList.add(index);
            hash.put(key, indexList);
            index++;
        }
        List<Integer> anagramIndexList = new ArrayList<>();
        for (String key : hash.keySet()) {
            if (hash.get(key).size() > 1) {
                anagramIndexList.addAll(hash.get(key));
            }
        }
        Collections.sort(anagramIndexList);
        List<String> resList = new ArrayList<>(anagramIndexList.size());
        for (Integer each : anagramIndexList) {
            resList.add(strs[each]);
        }
        return resList;
    }

    public static void main(String[] args) {
        Anagrams anagrams = new Anagrams();
        String[] str1 = {"lint", "intl", "inlt", "code"};
        System.out.println(anagrams.anagrams(str1));
        String[] str2 = {"ab", "ba", "cd", "dc", "e"};
        System.out.println(anagrams.anagrams(str2));
    }
}
