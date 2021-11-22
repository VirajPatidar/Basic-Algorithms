import java.util.Scanner;
public class addressCalc {
    static int decToBinary(int n){
        if (n == 0)  
            return 0;    
        else
            return (n%2 + 10*decToBinary(n/2));
    } 
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the IP Address");
        String ip = sc.nextLine();
        int i=0, deci; String str, bin;
        while (ip.charAt(i)!='.')
            i++;
        str = ip.substring(0,i);
        deci = Integer.parseInt(str);
        if(deci > 255){
            System.out.println("You have entered an Invalid IP Address");
            System.exit(0);
        }
        bin = Integer.toString(decToBinary(deci));
        if(bin.length()<8)
            System.out.println("CLASS A");
        else{
            if(bin.charAt(1)=='0')
                System.out.println("CLASS B");
            else if(bin.charAt(2)=='0')
                System.out.println("CLASS C");
            else if(bin.charAt(3)=='0')
                System.out.println("CLASS D");
            else
                System.out.println("CLASS E");
        }
        sc.close();
        System.out.println("");
        System.out.println("");
    }
}