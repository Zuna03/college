public class ques {
    
    interface x{
        void add(Rational a,Rational b);
        void show();

    }

    static class Rational implements x{
        public int num,den;
        Rational(){

        }
        Rational(int a,int b){
            num=a;
            den=b;
        }
        public void add(Rational a,Rational b){
            int temp1,temp2;
            temp1=a.num+b.num;
            temp2=a.den+b.den;
            System.out.println(temp1+"/"+temp2);

        }
        public void show(){
            System.out.println(num+"/"+den);
        }
    }
    public static void main(String[] args){
        Rational a=new Rational(2,3);
        Rational b=new Rational(4,5);

        a.add(a, b);


    }
}
