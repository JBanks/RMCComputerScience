
public class Cadet
{

    
    private String name;
    private double markOfCSE101;


    
    Cadet (String n, int mark101)
    {
	name = n;
	markOfCSE101 = mark101;
    }


    
    public void displayCadetInfo ()
    {

	System.out.println ("\nOcdt " + name +
		"'s CSE101 mark is: " +
		markOfCSE101 + ".\n");

    } 
    
    
    public double getMark()
    {
	return markOfCSE101;
    }
} 
