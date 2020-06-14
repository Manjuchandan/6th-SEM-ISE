package lab1;

import java.util.*;
import java.util.Map.Entry;

public class DatabaseCallers {

    public static HashMap<Long, String>  hm = new HashMap<Long, String>();
    public static Scanner sc = new Scanner(System.in);

    public static void createEnteries() {
    	System.out.println("Enter how many details do you require?");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the phone number and Contact name");
            Long phno = sc.nextLong();
            String name = sc.next();
            hm.put(phno, name);
        }
    }
    public static void display() {
        

            System.out.print("collection is"+hm.entrySet());
        }
    }
