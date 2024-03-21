import java.util.*;
import java.util.Random;

public class Main{
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);
        R r = new R();
        
        System.out.print("Enter min number: ");
        int no1 = s.nextInt();
        int no2;
        do{
            System.out.print("Enter max number: ");
            no2 = s.nextInt();
        }while(no2<no1);
        
        r.setValue(no1,no2);
        
        System.out.println("The min is "+no1+", and max is "+no2);
        System.out.print("A random no between "+r.getn()+" and "+r.getx()+" is "+ r.getR());
    }
}

class R{
    private int n,x;
    
    public void setValue(int min, int max){
        n=min;
        x=max;
    }
    public int getn(){
        return n;
    }
    public int getx(){
        return x;
    }
    public int getR(){
        Random ran = new Random();
        return ran.nextInt(x-n+1);
    }
}