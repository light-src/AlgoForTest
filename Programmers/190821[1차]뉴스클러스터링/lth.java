import java.util.ArrayList;
import java.util.List;

class Solution {
    private static int NUM = 65536;
    List<String> copyList1 = new ArrayList<>();
    List<String> copyList2 = new ArrayList<>();
    int minCount = 0;
    int maxCount = 0;

    public int solution(String str1, String str2) {
        int answer = 0;
        List<String> strings1 = setList(str1.toUpperCase());
        List<String> strings2 = setList(str2.toUpperCase());

        copyList1.addAll(strings1);
        copyList2.addAll(strings2);

        this.subSet(strings1);
        this.subSet(strings2);

        if (maxCount == 0) {
            System.out.println(NUM);
            return NUM;
        }
        double a = ((double) minCount / (double) maxCount);
        answer = (int) (a * NUM);
        System.out.println(answer);
        return answer;
    }

    private void subSet(List<String> strings) {
        for (String str : strings) {
            int count1 = 0;
            int count2 = 0;
            while (copyList1.contains(str)) {
                count1++;
                copyList1.remove(str);
            }

            while (copyList2.contains(str)) {
                count2++;
                copyList2.remove(str);
            }
            minCount = minCount + Math.min(count1, count2);
            maxCount = maxCount + Math.max(count1, count2);
        }
    }

    private List<String> setList(String str) {
        List<String> strings = new ArrayList<>();
        for (int i = 0; i < str.length() - 1; ++i) {
            String subString = str.substring(i, i + 2);
            if (subString.matches("[a-zA-Z]*$")) {
                strings.add(subString);
            }
        }
        return strings;
    }
}

public class lth {
    public static void main(String... args) {
        Solution solution = new Solution();
        solution.solution("FRANCE", "french");
    }
}
