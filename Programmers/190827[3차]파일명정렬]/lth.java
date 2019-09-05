import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String... args) {
        Solution solution = new Solution();
        String[] arg = new String[]{"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
        String[] arg2 = new String[]{"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
        solution.solution(arg2);
    }
}

class Letter implements Comparable<Letter> {
    String header;
    int number;
    String tail;
    String baseString;

    public Letter(String header, String number, String tail, String baseString) {
        this.header = header;
        this.number = Integer.parseInt(number);
        this.tail = tail;
        this.baseString = baseString;
    }

    @Override
    public int compareTo(Letter o) {
        int result = this.header.compareTo(o.header);
        System.out.println(this.header + " " + o.header + " " + result);
        if (result < 0) {
            return -1;
        }else if(result == 0){
            if(this.number < o.number){
                return -1;
            }
            else if(this.number == o.number){
                return 0;
            }
        }
        return 1;
    }
}

class Solution {
    List<Letter> letters = new ArrayList<>();

    public String[] solution(String[] files) {
        Pattern p = Pattern.compile("(^[a-zA-Z\\s-]+)([0-9]+)(.*)");

        for (int i = 0; i < files.length; ++i) {
            String fileName = files[i];
            Matcher matcher = p.matcher(fileName.toUpperCase());
            if (matcher.find()) {
                letters.add(new Letter(matcher.group(1),
                        matcher.group(2),
                        matcher.group(3),
                        fileName));
            }
        }
        Collections.sort(letters);
        List<String> baseStrings = new ArrayList<>();
        for (Letter letter : letters) {
            baseStrings.add(letter.baseString);
        }
        String[] answer = baseSrings.toArray(new String[baseStrings.size()]);
        return answer;
    }
}