import java.util.Scanner;

class account {
    int acc_no, balance;

    void getdata(int c) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the account number and balance of person " + (c + 1) + ":  ");
        acc_no = sc.nextInt();
        balance = sc.nextInt();
    }
}

class person extends account {
    int adhaar_no;
    String name;

    void getdata(int c) {
        super.getdata(c);
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the adhaar number and name of person " + (c + 1) + ":  ");
        adhaar_no = sc.nextInt();
        name = sc.next();
    }

    void showdata(int c) {
        System.out.println("Displaying details of person " + (c + 1) + ": ");
        System.out.println("Account number: " + acc_no);
        System.out.println("Name: " + name);
        System.out.println("Balance: " + balance);
        System.out.println("Adhaar number: " + adhaar_no);
    }

}

public class que5 {
    public static void main(String arg[]) {
        person p[] = new person[5];
        int i;
        System.out.println("ACCUMULATING DATA: ");
        for (i = 0; i < 5; i++) {
            p[i] = new person();
            p[i].getdata(i);
        }
        System.out.println("PRINTING DATA: ");
        for (i = 0; i < 5; i++) {
            p[i].showdata(i);
        }
    }
}