class Base {
    Base(int i) {
        System.out.println("From Base class : " + i);
    }
}

class Derived extends Base {
    Derived() {
        super(20);
    }
}

public class que6 {
    public static void main(String[] args) {
        Derived object = new Derived();
    }
}