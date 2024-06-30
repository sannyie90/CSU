package GroceryBillCalculator;
//importing class Scanner from JDK
import java.util.Scanner;
public class GroceryBillCalculator {

	public static void main(String[] args) {
		
		//using scanner class for the datatype  input along with system.in
		
		try (Scanner input = new Scanner(System.in)) {
			System.out.print("Enter the coupon amount as a decimal (example, .10): ");
			//using double for upto 15 decimal digits
   //Could have used Float if the decimal place is upto 7 digit 
     // name the data set as a coupon
			//used nextDouble to receive the input from the keyboard in the form of a double
			
			double coupon = input.nextDouble();

			// Validate coupon amount
			//using the if condition to make sure if the coupon is less than equal to 0
			// or
			// if the coupon amount is more than 1
			// coupon is automatically set to 10% or 10/100=0.10
			
			if (coupon <= 0 || coupon > 1) {
			    coupon = 0.10;
			}

			// Prompt for weekly grocery bills
			//using the array variable here for the weekly bills
			// total number of weeks set to 4
			// using the for loop control variable i and set i's value equal to 0 to initiate
			// setting a false if the value exceeds 4 and terminate the process
			// using ++ for the increment of 1
			//using input.nextdouble again for user input for each week's grocery bill
			
			double[] weeklyBills = new double[4];
			for (int i = 0; i < 4; i++) {
			    System.out.print("Enter the grocery bill for week " + (i + 1) + ": ");
			    weeklyBills[i] = input.nextDouble();
			}

			// Calculate total monthly bill
			//setting datatype double variable to the totalMonthlyBill
			// setting totalMonthlyBill initial value at 0 as a starting point
			// using for loop and colon to ensure loop will iterate over each week
			//using double bill to ensure will take on the value of each element in the weeklyBills array one by one
			
			double totalMonthlyBill = 0;
			for (double bill : weeklyBills) {
			    totalMonthlyBill += bill;
			}

			// Calculate average weekly bill
			//using arithmetic function divide to take an average
			
			double averageWeeklyBill = totalMonthlyBill / 4;

			// Calculate discounted amounts
			// using arithmetic function multiply and minus to get discountedMonthlyBill and discountedWeeklyBill at 90%

			double discountedMonthlyBill = totalMonthlyBill * (1 - coupon);
			double discountedWeeklyBill = averageWeeklyBill * (1 - coupon);

			// Display results
			// print results on the screen/output device for all the calculations
			System.out.println("Total monthly grocery bill without coupon: $" + totalMonthlyBill);
			System.out.println("Average weekly grocery bill without coupon: $" + averageWeeklyBill);
			System.out.println("Total monthly grocery bill with coupon: $" + discountedMonthlyBill);
			System.out.println("Average weekly grocery bill with coupon: $" + discountedWeeklyBill);
		}

        // Prompt the user for coupon amount


	}

}
