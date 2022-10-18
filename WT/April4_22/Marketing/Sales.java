package Marketing;

import General.*;
import java.util.*;

public class Sales {

  public static double tallowance(double tall) {
    return tall * (5 / 100.00);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the Name : ");
    String name = sc.next();
    System.out.print("Enter the Employee Id : ");
    int ID = sc.nextInt();
    System.out.print("Enter the Basic Salary : ");
    double Salary = sc.nextDouble();
    employee obj = new employee(name, ID, Salary);
    obj.printName();
    Sales t = new Sales();
    double e = obj.earnings();
    System.out.println("The Employee ID is : " + ID);
    System.out.println("The Basic is : " + Salary);
    System.out.println("The Earnings are : " + e);
    System.out.println("The Travel allowance allowed: " + tallowance(e));
  }
}
