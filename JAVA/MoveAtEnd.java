public class MoveAtEnd {
    public static String newString="";
    public static int count=0;
    public static void moveElement(String s, int i, char c){
        if(i==s.length()){
            for(int j=0;j<count;j++){
                newString += c;
            }
            System.out.println("New String : "+newString);
            return;
        }
        if(s.charAt(i)!=c){
            newString += s.charAt(i);
        } else{
            count++;
        }
        moveElement(s, i+1, c);
    }
    public static void main(String[] args) {
        String str = "abdjknaaakehjd";
        char moveChar = 'a';
        moveElement(str, 0, moveChar);
    }
}
