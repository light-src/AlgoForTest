import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    int rows = 0;
    int cols = 0;
    String[][] copyRelation;
    List<HashSet<Integer>> answerSet = new ArrayList<>();

    public int solution(String[][] relation) {
        int arr[] = new int[10];
        copyRelation = relation;
        rows = relation.length;
        cols = relation[0].length;
        for (int i = 1; i <= cols; ++i) {
            combination(arr, 0, cols, i, 0);
        }
        return answerSet.size();
    }

    private void combination(int arr[], int index, int n, int r, int target) {
        if (r == 0) {
            HashSet<Integer> subSet = new HashSet<>();
            for (int i = 0; i < index; i++) {
                subSet.add(arr[i]);
            }
            if (isSubset(subSet)) {
                return;
            }

            if (isUnique(subSet)) {
                answerSet.add(subSet);
            }
        } else if (target == n) {
            return;
        } else {
            arr[index] = target;
            combination(arr, index + 1, n, r - 1, target + 1);
            combination(arr, index, n, r, target + 1);
        }
    }

    private boolean isSubset(HashSet<Integer> subSet) {
        for (int i = 0; i < answerSet.size(); ++i) {
            HashSet<Integer> tempSet = answerSet.get(i);
            if (subSet.containsAll(tempSet)) {
                return true;
            }
        }
        return false;
    }

    private boolean isUnique(HashSet<Integer> indexes) {
        List<String> strings = new ArrayList<>();
        List<Integer> arr = new ArrayList(indexes);
        for (int row = 0; row < rows; ++row) {
            String str = "";
            for (int i = 0; i < arr.size(); ++i) {
                int col = arr.get(i);
                str = str + " " + copyRelation[row][col];
            }
            for (int j = 0; j < strings.size(); j++) {
                if (strings.get(j).equals(str)) {
                    return false;
                }
            }
            strings.add(str);
        }
        return true;
    }
}

public class lth {
    public static void main(String... args) {
        Solution solution = new Solution();
        String[][] strings = new String[][]
                {{"100", "ryan", "music", "2"},
                        {"200", "apeach", "math", "2"},
                        {"300", "tube", "computer", "3"},
                        {"400", "con", "computer", "4"},
                        {"500", "muzi", "music", "3"},
                        {"600", "apeach", "music", "2"}
                };
        solution.solution(strings);
    }
}
