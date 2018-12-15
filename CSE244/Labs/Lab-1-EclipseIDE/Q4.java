

public class Q4
{

    public static void main (String[] whatEverIdentifier)
    {

      
	Cadet[] cadet = new Cadet [3];

	cadet [0] = new Cadet ("Tom Gough", 95);
	cadet [1] = new Cadet ("Simon French", 90);
	cadet [2] = new Cadet ("Lydia Lau", 97);



	printCadetInfoWhoHasHighestCSE101Mark (cadet);

    } 

    
    static void printCadetInfoWhoHasHighestCSE101Mark (Cadet[] c)
    {
	
	int highestMark = 0;
	int index = 0;
	
	for (int i=0; i< c.length; i++)
	{
	    if (highestMark < c[i].getMark())
	    {
	       index = i;
	    }
	}
	
	c[index].displayCadetInfo(); 
     

    } 
    
    
} 
