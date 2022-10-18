import java.util.*;

public class q2 {

    public static boolean isUpperCase(String s) {
        for (char c : s.toCharArray()) {
            if (!Character.isUpperCase(c))
                return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 , s2 = "" , s3 = "";
        System.out.println(
                "1. Change the case\n2. Reverse the string\n3. Compare two strings\n4.Insert one string into another");
        System.out.print("\nEnter Your Choice : ");
        int ch = sc.nextInt();
        switch (ch) {
            case 1:
                System.out.print("\nEnter the String in either all caps or all non caps : ");
                s1 = sc.next();
                if (isUpperCase(s1)) {
                    System.out.println(s1.toLowerCase());
                } else {
                    System.out.println(s1.toUpperCase());
                }
                break;
            case 2:
                System.out.print("\nEnter the String : ");
                s1 = sc.next();
                for (int i = 0; i < s1.length(); i++) {
                    char c = s1.charAt(i); // extracts each character
                    s2 = c + s2; // adds each character in front of the existing string
                }
                System.out.println("Reversed string : " + s2);
                break;

            case 3:
                boolean flag = true;
                System.out.print("\nEnter the String 1 : ");
                s1 = sc.next();
                System.out.print("\nEnter the String 2 : ");
                s2 = sc.next();
                if (s1.length() != s2.length()) {
                    flag = false;
                }
                else {
                    for (int i = 0; i < s1.length(); i++) {
                        if (s1.charAt(i) !=  s2.charAt(i)) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    System.out.println("Two strings are same");
                }
                else {
                    System.out.println("Two strings are different");
                }
                break;
            
            case 4:
                System.out.print("\nEnter the String 1 : ");
                s1 = sc.next();
                System.out.print("\nEnter the String 2 : ");
                s2 = sc.next();
                System.out.print("\nEnter the position of insertion (0,n-1) : ");
                int pos = sc.nextInt();
                for (int i = 0; i < s1.length(); i++) {
                    char c = s1.charAt(i); // extracts each character
                    if (i != pos) {
                        s3 = s3 + c;
                    }
                    else {
                        s3 = s3 + s2 + c;
                    }
                }
                System.out.println("\nNew string : " + s3);
                break;

            default:
                System.out.println("Wrong Choice");
                break;
        }
        sc.close();
    }
}
