public class TowerOfHanoi {
    public static void TOH(int n, char S, char H, char D) {
        if (n == 1) {
            System.out.println("Move disk " + n + " from " + S + " to " + D);
            return;
        }
        TOH(n - 1, S, D, H);  // Step 1: move n-1 from S → H
        System.out.println("Move disk " + n + " from " + S + " to " + D); // Step 2: move nth from S → D
        TOH(n - 1, H, S, D);  // Step 3: move n-1 from H → D
    }

    public static void main(String args[]) {
        int n = 3; // You can change this for more disks
        TOH(n, 'S', 'H', 'D');
    }
}