public class RemoveDuplicate {
    public static boolean[] map = new boolean[26];
    public static String newString = "";
    public static void remove(String s,int i){
        if(i==s.length()){
            System.out.println(newString);
            return;
        }
        if(map[s.charAt(i)-'a']==false){
            newString += s.charAt(i);
            map[s.charAt(i)-'a'] = true;
        }
        remove(s,i+1);
    }
    public static void main(String[] args) {
        // for(int i=0;i<26;i++){ // default false
        //     map[i] = false;
        // }
        String s = "anackkfksls";
        remove(s,0);
    }
}