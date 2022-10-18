package General;

import java.util.*;

public class employee {
  protected int empid;
  private String ename;
  private double basic, DA, HRA;

  public employee(String name, int id, double b) {
    ename = name;
    basic = b;
    empid = id;
    DA = b * (80 / 100.00);
    HRA = b * (50 / 100.00);
  }

  public double earnings() {
    return basic + DA + HRA;
  }

  public void printName() {
    System.out.println("\nName: " + ename);
  }
}
