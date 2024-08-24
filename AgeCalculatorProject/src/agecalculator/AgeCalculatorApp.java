package agecalculator;

// Import Swing components for GUI
import javax.swing.*;
// Import layout components
import java.awt.*;
// Import for handling button events
import java.awt.event.ActionEvent;
// Import for ActionListener interface
import java.awt.event.ActionListener;
// Import for date handling
import java.time.LocalDate;
// Import for calculating the period between dates
import java.time.Period;
// Import for formatting dates
import java.time.format.DateTimeFormatter;
// Import for handling invalid date formats
import java.time.format.DateTimeParseException;

// Main class for the Age Calculator application
public class AgeCalculatorApp extends JFrame {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	// Input field for the user's birth date
    private JTextField birthDateField;
    // Label to display the result
    private JLabel resultLabel;

    // Constructor to set up the GUI
    public AgeCalculatorApp() {
        // Set window title
        setTitle("Age Calculator");
        // Set window size
        setSize(400, 200);
        // Close app on window close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Use BorderLayout for component placement
        setLayout(new BorderLayout());

        // Set up input panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        // Label for birth date input
        panel.add(new JLabel("Enter your birth date (MM-DD-YYYY):"));
        // Text field for birth date input
        birthDateField = new JTextField(10);
        // Add text field to panel
        panel.add(birthDateField);

        // Button to trigger age calculation
        JButton calculateButton = new JButton("Calculate Age");
        // Add button to panel
        panel.add(calculateButton);

        // Add panel to the center of the window
        add(panel, BorderLayout.CENTER);

        // Label for result display
        resultLabel = new JLabel("Your age will appear here.");
        // Add result label to the bottom of the window
        add(resultLabel, BorderLayout.SOUTH);

        // Add button click event listener
        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Call method to calculate age on button click
                calculateAge();
            }
        });
    }

    // Method to calculate the user's age
    private void calculateAge() {
        // Get birth date from text field
        String birthDateText = birthDateField.getText();

        try {
            // Parse the input date in MM-DD-YYYY format
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM-dd-yyyy");
            LocalDate birthDate = LocalDate.parse(birthDateText, formatter);

            // Get the current date
            LocalDate currentDate = LocalDate.now();
            // Calculate age
            Period age = Period.between(birthDate, currentDate);

            // Display the user's age
            resultLabel.setText("Your age is: " + age.getYears() + " years");

        } catch (DateTimeParseException ex) {
            // Handle invalid date input
            resultLabel.setText("Invalid date format. Please use MM-DD-YYYY.");
        }
    }

    // Main method to run the application
    public static void main(String[] args) {
        // Create an instance of the app
        AgeCalculatorApp app = new AgeCalculatorApp();
        // Make the window visible
        app.setVisible(true);
    }
}
