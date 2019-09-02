import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    HashMap<String, String> userList = new HashMap<>();
    private static String ENTER_MESSAGE = "님이 들어왔습니다.";
    private static String LEAVE_MESSAGE = "님이 나갔습니다.";

    public String[] solution(String[] record) {
        List<String> messageList = new ArrayList<>();
        for (int i = 0; i < record.length; ++i) {
            String[] splitCommand = record[i].split("\\s");
            String command = splitCommand[0];
            String uid = splitCommand[1];
            if (command.equals("Enter")) {
                String nickName = splitCommand[2];
                userList.put(uid, nickName);
                String message = uid + " " + "ENTER";
                messageList.add(message);
            } else if (command.equals("Change")) {
                String nickName = splitCommand[2];
                userList.put(uid, nickName);
            } else if (command.equals("Leave")) {
                String message = uid + " " + "LEAVE";
                messageList.add(message);
            }
        }
        List<String> messages = returnMessageList(messageList);
        return messages.toArray(new String[messages.size()]);
    }
    private List<String> returnMessageList(List<String> messageList){
        List<String> returnMessageList = new ArrayList<>();
        for(String message : messageList){
            String[] splitCommand = message.split("\\s");
            String uid = splitCommand[0];
            String messageType = splitCommand[1];
            String str = userList.get(uid);
            if(messageType.equals("ENTER")){
                str += ENTER_MESSAGE;
            }
            else if(messageType.equals("LEAVE")){
                str += LEAVE_MESSAGE;
            }
            returnMessageList.add(str);
        }
        return returnMessageList;
    }
}

public class lth {
    public static void main(String... args) {

    }
}
