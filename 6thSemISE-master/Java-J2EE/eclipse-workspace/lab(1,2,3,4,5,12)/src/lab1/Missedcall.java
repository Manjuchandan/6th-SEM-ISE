package lab1;


import java.util.*;

public class Missedcall {

    static LinkedList<MissedcallDetails> amiss;

    static void HandleMissedCallActivities() {
    	int i;
        amiss = new LinkedList<MissedcallDetails>();
        while (true) {
            System.out.println("Enter a choice");
            System.out.println(
                    "1: add missed call \n 2.Display and delete on request \n 3. Delete based on number \n 4. Print");
            int choice = DatabaseCallers.sc.nextInt();
            // int i=1;
            switch (choice) {
            case 1: // add missed call
                System.out.println("Enter the missed call telephone number");
                Calendar cb = Calendar.getInstance();
                Long telnum = DatabaseCallers.sc.nextLong();
                String name; // = DataBaseCallers.sc.next();
                // check for name in the Database
                if (DatabaseCallers.hm.containsKey(telnum))
                    name = DatabaseCallers.hm.get(telnum);
                else
                    name = "Private Caller";
                MissedcallDetails mcd = new MissedcallDetails(cb, telnum, name);
                if (amiss.size() == 10)// for eleventh entry onwards
                {
                    // for eleventh entry onwards enter from the beginning
                    amiss.removeLast();
                }
                amiss.addFirst(mcd);
                break;
            case 2: // Display number and ask for user to delete
                ListIterator<MissedcallDetails> itr = amiss.listIterator();
              //  LinkedList<MissedcallDetails> removeList = new LinkedList<MissedcallDetails>();
                //int i = 0;
                while (itr.hasNext()) {
                  //  i++;
                    System.out.println("Number is ");
                    MissedcallDetails m1 = itr.next();
                    System.out.println(m1.tel_num);
                    //System.out.println(
                   //         "Do you want to delete the details related to this number? Indicate by 1 : delete, 2: move next call , 3: display call details \n");
                 //   int cho = DatabaseCallers.sc.nextInt();
                    //if (cho == 1)
                      //  removeList.add(m1);
               //     //else if (cho == 3) {// display
                   //     m1.display();
                 //   }
               // }
                //if (i == 0)
                  //  System.out.println("No missed calls");
                //amiss.removeAll(removeList);
                }
                break;
            case 3: // Delete based on the number specified by the user
                System.out.println("Delete based on the number given by user");
                System.out.println("Enter the number");
                Long num = DatabaseCallers.sc.nextLong();
                ListIterator<MissedcallDetails> it1 = amiss.listIterator();
                boolean flag = false;
                i = 0;
                while (it1.hasNext()) {
                    i++;
                    MissedcallDetails m1 = it1.next();
                    if (m1.tel_num == num) {
                        flag = true;
                        amiss.remove(m1);
                        break;
                    }
                }
                if (i != 0) {
                    if (flag == true)
                        System.out.println("Phone number with details " + num + "deleted");
                    else
                        System.out.println("No such number exists");
                } else
                    System.out.println("No missed Call");
                break;
            case 4:
                // print missed call details
                ListIterator<MissedcallDetails> it2 = amiss.listIterator();
                while (it2.hasNext()) {
                    MissedcallDetails m1 = it2.next();
                    m1.display();
                }
                break;
            default:
                return;
            }
        }
    }

    public static void main(String[] args) {
        // 1. Enter contact details in the database
        DatabaseCallers.createEnteries();;
        System.out.println("Receive missed Calls");
        // DataBaseCallers.sc
        HandleMissedCallActivities();
        DatabaseCallers.display();
    }
}