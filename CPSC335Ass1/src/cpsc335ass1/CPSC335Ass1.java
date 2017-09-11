/*
Jake Dappen
CPSC 335
Assignment 1
*/
package cpsc335ass1;
import java.util.Scanner;

public class CPSC335Ass1 {

    public static void main(String[] args) {
     int n;
     int m = 1;
     int k;
     int i;
     int l= 1;
     int[] disks;
     
     //header prompt
     System.out.println("CPSC 3335-01-Programming Assignment #1");
     System.out.println("The alternating disk problem: left-to-right algorithm");
     System.out.println("Enter the number of single color disks(light or dark)");
     
     //input scanner
     Scanner input = new Scanner(System.in);
     
     //reads input and sets array size
     n = input.nextInt();
     disks = new int[2*n];
     
     for(i = 0; i < n; i++)
     {
         disks[2*i] = 1;
         disks[2*i+1] = 0;
     }
     
     System.out.println("Initial Configuration");
     
     print_disks(n, disks);
        
     for(k = 0; k <n; k++)
     {
         if(disks[k]== 1)
         {
             int j = k;
             while( j != disks.length - l)
             {                  
                 int temp = disks[j+1];
                 disks[j+1] = disks[j];
                 disks[j] = temp;
                 m++;
                 j++;
             }
         }
         l++;
     }
        
     //after shuffling
     System.out.println("After moving darker ones to the right");
     print_disks(n, disks);
     System.out.println("Number of swaps is " + m);
           
        
        
    }
    
    public  static void print_disks(int n, int[] disks)
    {
        System.out.println("List of disks");
        for(int i = 0; i < disks.length; i++)
        {
            if(disks[i] == 0)
            {
                System.out.print("l");
            }
            else{
                System.out.print("d");
            }
        }
        System.out.println("");
    }
    
    
}
