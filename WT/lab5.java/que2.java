
import java.util.Scanner;

class plate {
    int length;
    int breadth;

    plate(int l, int b) {
        System.out.println("Constructor plate called");
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }
}

class box extends plate {
    int height;

    box(int l, int b, int h) {
        super(l, b);
        System.out.println("Constructor box called");
        height = h;
    }

    int volume() {
        return area() * height;
    }
}

class wood_box extends box {
    int thickness;

    wood_box(int l, int b, int h, int t) {
        super(l, b, h);
        System.out.println("Constructor wood_boc called");
        thickness = t;
    }

    int val() {
        return volume() - ((length - (2 * thickness)) * (breadth - (2 * thickness)) * (height - (2 * thickness)));
    }
}

class que2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter l, b, h, t");
        int l = sc.nextInt();
        int b = sc.nextInt();
        int h = sc.nextInt();
        int t = sc.nextInt();
        wood_box w = new wood_box(l, b, h, t);
        System.out.println("The volume of wood contained in the box : " + w.val());
        sc.close();
    }
}