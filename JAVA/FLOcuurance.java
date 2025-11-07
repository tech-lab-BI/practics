public class FLOcuurance {
    public static int first = -1;
    public static int last = -1;
    public static void occurance(String s, int i, char c){
        if(i == s.length()){
            if(first == -1){
                System.out.println("Charecter not found !");
            }else{
                System.out.println("First : "+first+" Last : "+last);
            }
            return;
        }
        if(s.charAt(i) == c){
            if(first == -1){
                first = last = i;
            }
            else{
                last = i;
            }
        }
        occurance(s, i+1, c);
    }
    public static void main(String[] args) {
        String s = "hello world I am coming";
        char findChar = 'g';
        occurance(s, 0, findChar);
    }
}
