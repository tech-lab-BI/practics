public class SubSequence {
    static void subPart(String s,int i,String newString){
        if(i == s.length()){
            System.out.println(newString);
            return;
        }
        subPart(s, i+1, newString+s.charAt(i));//to be add
        subPart(s, i+1, newString);//not to be add
    }
    public static void main(String[] args) {
        String str = "abc";// what for "aaa"
        subPart(str,0,"");
    }
}
