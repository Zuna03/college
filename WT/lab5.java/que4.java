import java.util.Scanner;

class Shape {
    int area;

    void showArea() {
        System.out.println("Area of the shape is " + area);
    }
}

class Circle extends Shape {
    int radius;

    Circle(int r) {
        radius = r;
        area = 3 * radius * radius;
    }
}

class Rectangle extends Shape {
    int length;
    int breadth;

    Rectangle(int l, int b) {
        length = l;
        breadth = b;
        area = length * breadth;
    }
}

class que4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter radius :");
        int r = sc.nextInt();
        Circle c = new Circle(r);
        c.showArea();
        System.out.print("Enter length and breadth :");
        int l = sc.nextInt();
        int b = sc.nextInt();
        Rectangle r1 = new Rectangle(l, b);
        r1.showArea();
        sc.close();
    }
}
